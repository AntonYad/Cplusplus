class Solution {
public:
	string addStrings(string num1, string num2)
	{
		char next = 0;
		char sum;
		int i, j;
		string allsum;
		i = num1.size() - 1;
		j = num2.size() - 1;
		while (i >= 0 || j >= 0)
		{
			char sum1 = 0, sum2 = 0;
			if (i >= 0)
			{
				sum1 = num1[i] - '0';
				--i;
			}
			if (j >= 0)
			{
				sum2 = num2[j] - '0';
				--j;
			}
			sum = sum1 + sum2 + next;
			if (sum >= 10)
			{
				sum = sum - 10;
				next = 1;
			}
			else
			{
				next = 0;
			}
			allsum += (sum + '0');
		}
		if (next == 1)
		{
			allsum += '1';
		}
		reverse(allsum.begin(), allsum.end());
		return allsum;
	}
};