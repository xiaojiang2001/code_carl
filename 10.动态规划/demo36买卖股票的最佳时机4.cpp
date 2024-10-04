#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	// 动规
	int maxProfit(int k, vector<int>& prices) 
	{
		// 由于最多 k 次，一天相当于有 2 * k + 1 个操作
		/*
		dp[i][j]表示第i天状态j后所剩的最大现金
		0. 没有操作 （其实我们也可以不设置这个状态）dp[i-1][0]
		1. 第一次持有股票	
		(1) 第 i 天买入：dp[i-1][0] - prices[i]
		(2）第 i 之前就买入，第 i 天只是保持不动 dp[i-1][1]
		所以：dp[i][1] = max(dp[i-1][0] - prices[i], dp[i-1][1])
		2. 第一次不持有股票
		(1) 第 i 天卖出：dp[i-1][1] + prices[i]
		(2) 第 i 天之前卖出，第 i 天只是不变：dp[i-1][2]
		所以 dp[i][2] = max(dp[i-1][1] + prices[i], dp[i-1][2])
		3. 第二次持有股票
		同理状态1：dp[i][3] = max(dp[i-1][2] - prices[i], dp[i-1][3])
		4. 第二次不持有股票
		同理状态2：dp[i][4] = max(dp[i-1][3] + prices[i], dp[i-1][4])
		......
		// j = 1 3 5
		第 k 次持有股票：  dp[i][j] = max(dp[i-1][j-1] - prices[i], dp[i-1][j]);
		第 k 次不持有股票: dp[i][j] = max(dp[i-1][j-1] + prices[i], dp[i-1][j]);
		*/
		
		int len = prices.size();
		if(len <= 1)
			return 0;
		vector<vector<int>> dp(len, vector<int>(2 * k + 1, 0));
		//初始化
		for(int i = 1; i < 2 * k; i += 2)
			dp[0][i] = -prices[0];

		//递推公式 k = 2
		for(int i = 1; i < len; i++)
		{
			dp[i][0] = dp[i-1][0];
			// 1 3 
			for(int j = 1; j < 2 * k; j += 2)
			{
				dp[i][j] = max(dp[i-1][j-1] - prices[i], dp[i-1][j]);		// 买入
				dp[i][j+1] = max(dp[i-1][j] + prices[i], dp[i-1][j+1]);		// 卖出
			}
		}
		return dp[len-1][2 * k];
	}
};

int main()
{
	Solution s;
	vector<int> profit{3,2,6,5,0,3};
	int ret = s.maxProfit(2, profit);
	cout << "\nret: " << ret;
	return 0; 
}

