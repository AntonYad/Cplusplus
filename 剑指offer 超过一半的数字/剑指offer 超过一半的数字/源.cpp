class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int len = numbers.size() / 2;
		vector<int> v(10, 0);
		int count = 0;
		if (numbers.size() == 1)
		{
			return numbers[0];
		}
		for (int i = 0; i<numbers.size(); i++)
		{
			v[numbers[i]] = v[numbers[i]] + 1;
		}
		for (int i = 0; i<v.size(); i++)
		{
			if (v[i]>4)
			{
				return i;
			}
		}
		return 0;
	}
};