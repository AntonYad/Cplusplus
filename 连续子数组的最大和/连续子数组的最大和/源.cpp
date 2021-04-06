class Solution
{
public:
	int FindGreatestSumOfSubArray(vector<int> array)
	{
		int cur = array[0];
		int max = array[0];
		for (int i = 1; i<array.size(); i++)
		{
			cur += array[i];
			if (cur<array[i])
				cur = array[i];
			if (cur>max)
				max = cur;
		}
		return max;
	}
};