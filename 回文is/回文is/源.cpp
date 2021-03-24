class Solution {
public:
	bool isletter(string s, int n)
	{
		if ((s[n] >= 'a'&&s[n] <= 'z') || (s[n] >= 'A'&&s[n] <= 'Z') || (s[n] >= '0'&&s[n] <= '9'))
		{
			return true;
		}
		return false;
	}
	bool isPalindrome(string s) {
		if (s.empty())
		{
			return true;
		}
		for (int i = 0; i<s.size(); ++i)
		{
			s[i] = tolower(s[i]);
		}
		int begin = 0;
		int end = s.size() - 1;
		while (begin<end)
		{
			while (!isletter(s, begin) && begin<end)
			{
				begin++;
			}
			while (!isletter(s, end) && begin<end)
			{
				end--;
			}
			if (s[begin] != s[end])
			{
				return false;
			}
			begin++;
			end--;
		}
		return true;
	}
};