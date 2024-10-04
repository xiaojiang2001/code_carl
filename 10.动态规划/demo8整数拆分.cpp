#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int integerBreak(int n) 
	{
		// dp[i] : i 拆分后得到的最大乘积数
		vector<int> dp(n+1);
		// dp[0] dp[1] 无意义
		dp[0] = dp[1] = 0;	
		dp[2] = 1;
		for(int i = 3; i <= n; i++)
		{
			for(int j = 1; j < i; j++)		// 对 i 进行拆分 j 和 i-j
			{
				dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
			}
		}
		return dp[n];
	}
};

int main()
{
	Solution s;
	int ret = s.integerBreak(10);
	cout << "ret: " << ret << endl;
	return 0;
}
