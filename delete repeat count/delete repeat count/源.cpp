class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int slow = 0;
		if (nums.size()<2)
		{
			return nums.size();
		}
		for (int fast = 1; fast<nums.size(); fast++)
		{
			if (nums[slow] != nums[fast])
			{
				slow++;
				nums[slow] = nums[fast];
			}
		}
		return slow + 1;
	}
};