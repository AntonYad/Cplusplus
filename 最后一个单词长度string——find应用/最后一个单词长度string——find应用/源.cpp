#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	for (int i = 0; i<s.size(); i++)
	{
		int pos1 = s.find(' ', 0);
		if (pos1 == NULL || s == "")
		{
			cout << s.size() << endl;
		}
	}
	for (auto e : s)
	{
		size_t pos = s.rfind(' ');
		cout << s.size() - pos - 1 << endl;
		break;
	}
	return 0;
}