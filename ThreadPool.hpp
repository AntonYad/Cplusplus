#pragma once

#include <iostream>
#include <queue>
#include <unistd.h>
#include <math.h>

#define NUM 5

class Task{
    public:
        int base;
    public:
        Task(){}
        Task(int _b):base(_b){}

        void Run()
        {
            std::cout <<"thread is[" << pthread_self() << "] task run ... done: base# "<< base << " pow is# "<< pow(base,2) << std::endl;
        }
        ~Task(){}
};

class ThreadPool{
    private:
        std::queue<Task*> q;
        int max_num;
        pthread_mutex_t lock;
        pthread_cond_t cond; //only consumer, thread pool thread;
        bool quit;
    public:
        void LockQueue()
        {
            pthread_mutex_lock(&lock);
        }
        void UnlockQueue()
        {
            pthread_mutex_unlock(&lock);
        }
        bool IsEmpty()
        {
            return q.size() == 0;
        }
        void ThreadWait()
        {
            pthread_cond_wait(&cond, &lock);
        }
        void ThreadWakeup()
        {
            //if(low_water > 30){
            //    pthread_cond_broadcast(&cond);
            //}
            pthread_cond_signal(&cond);
        }
        void ThreadsWakeup()
        {
            pthread_cond_broadcast(&cond);
        }
    public:
        ThreadPool(int _max=NUM):max_num(_max),quit(false)
        {}
        static void *Routine(void *arg) //
        {
            ThreadPool *this_p = (ThreadPool*)arg;
            while(!quit){
                this_p->LockQueue();
                while(!quit && this_p->IsEmpty()){
                    this_p->ThreadWait();
                }

                Task t;
                if(!quit && !this_p->IsEmpty){
                    this_p->Get(t);
                }
                this_p->UnlockQueue();
                //t.Run();
            }
        }
        void ThreadPoolInit()
        {
            pthread_mutex_init(&lock, nullptr);
            pthread_cond_init(&cond, nullptr);
            pthread_t t;
            for(int i = 0; i < max_num; i++){
                pthread_create(&t, nullptr, Routine, this);
            }
        }
        //server
        void Put(Task &in)
        {
            LockQueue();
            q.push(&in);
            UnlockQueue();

            ThreadWakeup();
        }
        //Thread pool t;
        void Get(Task &out)
        {
            Task*t = q.front();
            q.pop();
            out = *t;
        }
        void ThreadQuit()
        {
            if(!IsEmpty()){
                std::cout << "task queue is not empty" << std::endl;
                return;
            }
            quit = true;
            ThreadsWakeup();
        }
        ~ThreadPool()
        {
            pthread_mutex_destroy(&lock);
            pthread_cond_destroy(&cond);
        }

};









