#define _CRT_SECURE_NO_WARNINGS 1
int findUnsortedSubarray(int* nums, int numsSize)
{
	int max, min, curA = 0, curB = numsSize - 1;
	while (curA<curB&&nums[curA] <= nums[curA + 1])
	{
		curA++;
	}
	while (curA<curB&&nums[curB] >= nums[curB - 1])
	{
		curB--;
	}
	if (curA == curB)
	{
		return 0;
	}
	min = nums[curA];
	max = nums[curB];
	for (int i = curA; i <= curB; i++)
	{
		if (nums[i]<min)
		{
			min = nums[i];
		}
		if (nums[i]>max)
		{
			max = nums[i];
		}
	}
	curA = 0;
	curB = numsSize - 1;
	while (nums[curA] <= min)
	{
		curA++;
	}
	while (nums[curB] >= max)
	{
		curB--;
	}
	return curB - curA + 1;
}