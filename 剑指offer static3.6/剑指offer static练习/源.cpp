#define _CRT_SECURE_NO_WARNINGS 1
class Solution
{
public:
	class sum
	{
	public:
		sum()
		{
			_num = _num + _i;
			_i++;
		}
	};
	int Sum_Solution(int n)
	{
		_i = 1;
		_num = 0;
		sum arr[n];
		return _num;
	}
	static size_t _num;
	static size_t _i;
};
size_t Solution::_num = 0;
size_t Solution::_i = 1;