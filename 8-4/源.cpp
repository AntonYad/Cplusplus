#define   MAX    ((a)>(b)?(a):(b))

#include<iostream>
#include<math.h>
#include<vector>
#include<map>
using namespace std;
int main()
{
	int a = 64;
	int res=a | (1 << 8);
	//cout << res <<hex<< endl;
	//vector<int> v = {1,2,4,4,7};
	return 0;
}
vector<int> sum(vector<int> v, int target)
{
	vector<int> res;
	if (v.size() == 0) return res;
	multimap<int,int> us;
	for (int i = 0; i < v.size(); i++)
	{
		int num=target - v[i];
		auto it = us.find(num);
		if (it == us.end())
		{
			us.insert(make_pair(v[i],i));
		}
		else
		{
			
			res.push_back(v[i]);
			res.push_back(num);
			us.erase(it);
		}
	}
	return res;
	
}
