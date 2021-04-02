class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int i = 0;
		for (int j = 0; j<nums.size(); j++)
		{
			i = nums[j] ^ i;
		}
		return i;
	}
};