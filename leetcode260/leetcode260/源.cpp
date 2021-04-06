class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<int> v;
		int i = 0;
		while (i<nums.size() - 1)
		{
			if (nums[i] == nums[i + 1])
			{
				i = i + 2;
			}
			else
			{
				v.push_back(nums[i]);
				i = i + 1;
			}
		}
		if (i<nums.size())
		{
			v.push_back(nums[i]);
		}
		return v;

	}
};