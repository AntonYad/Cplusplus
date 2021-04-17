#pragma once
#include<vector>
namespace GX
{
	template<class T,class Container = vector<T>,class Compare= less<T>>// Compare =greater<T>
	class priority_queue
	{
	public:
		priority_queue（）
		{}
		void Adjustdown(int root)
		{
			Compare com;
			int parents = root;
			child = parents * 2 + 1;
			if (child+1<_com.size()&&_con[child] > _con[child + 1])
			{
				child++;
			}
			while (child<_con.size())
			{
				if (_con[child] < _con[parents])//if(_con[child],_con[parents])
				{
					swap(_con[child], _con[parents]);
					parents = child;
					child = parents * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}
		void Adjustup(int child)
		{
			Compare com;
			int parents = (child - 1) / 2;
			while (child>0)
			{
				if (_con[child] >_con[ parents])//if(_con[parents],_con[child])
				{
					swap(_con[parents],_con[ child]);
					child = parents;
					parents = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		void push(const T& x)
		{
			_con.push.back(x);
			Adjustup(_con.size() - 1);
		}
		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			Adjustdown(0);
		}
		T& top()
		{
			return _con.front();
		}

		size_t size()
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.empty();
		}
		template <class Inputiterator>
		priority_queue(Inputiterator first, Inputiterator last)
			:_con(first,last)
		{
			for (int i = (_con.size() - 2) / 2; i >= 0; i--)
			{
				Adjustdown();
			}
		}
	private:
		Container _con;
	};
}
//仿函数（优先级队列 priority）
template<class T>
struct less
{
	bool opreator(const T& x1,const T& x2 )
	{
		return x1 < x2;
	}
};
template<class T>
struct greater
{
	bool opreator(const T& x1, const T& x2)
	{
		return x1 > x2;
	}
};