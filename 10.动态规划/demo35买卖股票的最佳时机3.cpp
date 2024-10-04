#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	// 动规
	int maxProfit(vector<int>& prices) 
	{
		// 一天有五个操作
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
		*/
		
		int len = prices.size();
		if(len <= 1)
			return 0;
		vector<vector<int>> dp(len, vector<int>(5));
		dp[0][0] = 0;
		dp[0][1] = -prices[0];
		dp[0][2] = 0;
		dp[0][3] = -prices[0];
		dp[0][4] = 0;
		for(int i = 1; i < len; i++)
		{
			dp[i][0] = dp[i-1][0];
			dp[i][1] = max(dp[i-1][0] - prices[i], dp[i-1][1]);
			dp[i][2] = max(dp[i-1][1] + prices[i], dp[i-1][2]);
			dp[i][3] = max(dp[i-1][2] - prices[i], dp[i-1][3]);
			dp[i][4] = max(dp[i-1][3] + prices[i], dp[i-1][4]);
		}
		return max(dp[len-1][2],dp[len-1][4]);
	}
};

int main()
{
	Solution s;
	vector<int> maxProfit{1,2,3,4,5};
	int ret = s.maxProfit(maxProfit);
	cout << "\nret: " << ret;
	return 0; 
}

