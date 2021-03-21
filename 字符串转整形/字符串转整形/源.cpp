class Solution {
public:
	int StrToInt(string str)
	{
		int i;
		if (str[0] == NULL)
		{
			return 0;
		}
		int flag = 1;
		int count = 0;
		if (str[0] == '-')
		{
			flag = -1;
		}
		if (str[0] == '-' || str[0] == '+')
		{
			i = 1;
		}
		else
		{
			i = 0;
		}
		for (; i<str.size(); i++)
		{
			if (str[i]>'9' || str[i]<'0')
			{
				return 0;
			}
			str[i] = (str[i] - '0');
			count = count * 10 + str[i];
		}


		return flag*count;
	}
};