#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	// 任何一个正整数都可以 因为有 1
	int numSquares(int n) 
	{
		// dp[i] :  组成和为 i 的完全平方数的最少个数 最终求dp[n]
		vector<int> dp(n + 1, INT_MAX);
		// 物品重量 i  物品价值  i * i
		// 背包大小 n
		//递推公式
		//dp[j] = min(dp[j - i * i] + 1, dp[j])
		dp[0] = 0;
		// 遍历物品
		for(int  i = 1; i * i <= n; i++)
		{
			// 遍历背包
			for(int j = i * i; j <= n; j++)
			{	
				if(dp[j - i * i] != INT_MAX)
					dp[j] = min(dp[j - i * i]+1,dp[j]);
			}
		}
		for(int num:dp)
			cout << num << " ";
		return dp[n];
	}
	
};

int main()
{
	Solution s;
	vector<int> nums{1, 2, 5};
	int ret = s.numSquares(13);
	cout << endl << "ret: " << ret;
	return 0; 
}

