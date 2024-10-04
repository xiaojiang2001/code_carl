#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	// 动规
	int maxProfit(vector<int>& prices, int fee) 
	{
		// 状态0：
		// dp[i][0] 表示第i天持有股票所得最多现金
		// 保持不变: dp[i-1][0] 
		// 第i天买入股票：dp[i-1][1] - prices[i]
		
		// 状态1：
		// dp[i][1] 表示第i天不持有股票所得最多现金
		// 保持不变：dp[i-1][1]
		// 卖出：dp[i][1] = dp[i-1][0] + prices[i] - fee
				
		int len = prices.size();
		if(len <= 1)
			return 0;
		vector<vector<int>> dp(len, vector<int>(2));
		dp[0][0] = -prices[0];
		dp[0][1] = 0;
		
		for(int i = 1; i < len; i++)
		{
			dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
			dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i] - fee);
		}
		
		return max(dp[len-1][0], dp[len-1][1]);
	}
};

int main()
{
	Solution s;
	vector<int> profit{1, 3, 2, 8, 4, 9};
	int ret = s.maxProfit(profit,2);
	cout << "\nret: " << ret;
	return 0; 
}

