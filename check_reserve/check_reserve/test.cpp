#include<iostream>
#include<vector>

using namespace std;

int main()
{
	size_t sz;
	vector<int>foo;
	sz = foo.capacity(); 
	cout << "making foo grow:\n";
	for (int i = 0; i < 100; i++)
	{
		foo.push_back(i);
		if (sz != foo.capacity())
		{
			sz = foo.capacity();
			cout << "capacity changed:" << sz << endl;
		}
	
	}
}
