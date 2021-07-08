//#include<iostream>
//#include<string>
//#include<map>
//#include<algorithm>
//using namespace std;
//int main()
//{
//    string A, B;
//    while (cin >> A >> B)
//    {
//        map<char, int> mB;
//
//        for (auto& e : B)
//        {
//            mB[e]++;
//        }
//        int i;
//        for (i = 0; i < A.size(); i++)
//        {
//            auto ret = mB.find(A[i]);
//            if (ret != mB.end() && mB[A[i]] != 0)
//            {
//                mB[A[i]]--;
//            }
//            else
//            {
//                cout << "NO" << endl;
//                break;
//            }
//        }
//        if (i == A.size())
//            cout << "YES" << endl;
//    }
//    return 0;
//}
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
    string a, b;
    while (cin >> a >> b) {
        map<char, int> ma, mb;
        for (auto e : a) {
            ++ma[e];
        }
        for (auto e : b) {
            ++mb[e];
        }
        bool flag = true;
        //for(map<char, int>::iterator it = mb.begin(); it != mb.end(); ++it){
            //if(ma[it->first] < it->second){
        for (auto e : mb) {
            if (ma[e.first] < e.second) {
                flag = !flag;
                break;
            }
        }
        if (flag) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}