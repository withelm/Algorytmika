class Solution
{
private:
	int calc(string &s, int val)
	{
		int r = 0;
		for (auto &x : s)
		{
			r += (x - '0') != val;
			val = (val + 1) % 2;
		}
		return r;
	}

public:
	int minOperations(string s)
	{
		return min(calc(s, 0), calc(s, 1));
	}
};