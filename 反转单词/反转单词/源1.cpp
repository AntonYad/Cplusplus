class Solution {
public:
	void Reverse(string &s, int start, int end)
	{
		char tmp;
		while (start < end)
		{
			tmp = s[start];
			s[start] = s[end];
			s[end] = tmp;
			start++;
			end--;
		}
	}
	string reverseWords(string s)
	{
		size_t begin = 0;
		size_t end = 0;
		while (begin < s.size())
		{
			end = s.find(' ', begin);
			if (end == string::npos)
			{
				end = s.size() - 1;
				break;
			}
			Reverse(s, begin, end - 1);
			begin = end + 1;
		}
		Reverse(s, begin, end);
		return s;
	}

};