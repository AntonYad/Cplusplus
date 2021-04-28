class Solution {
public:
	int numWays(int n) {

		if (n == 0)
		{
			return 1;
		}
		if (n == 1 || n == 2)
		{
			return n;
		}
		vector<int> v(n + 1, 0);
		v[0] = 1;
		v[1] = 1;
		for (int i = 2; i<n + 1; i++)
		{
			v[i] = (v[i - 1] + v[i - 2]) % 1000000007;
		}
		return v[n];
	}
};