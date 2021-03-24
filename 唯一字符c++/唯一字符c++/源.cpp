class Solution
{
public:
	int firstUniqChar(string s)
	{
		int num[26] = { 0 };
		for (auto e : s)
		{
			num[e - 'a']++;
		}
		for (int i = 0; i<s.size(); i++)
		{
			if (num[s[i] - 'a'] == 1)
			{
				return i;
			}
		}
		return -1;
	}
};