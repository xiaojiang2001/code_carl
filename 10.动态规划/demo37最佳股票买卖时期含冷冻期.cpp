#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	// 动规
	int maxProfit(vector<int>& prices) 
	{
		// 状态0：
		// dp[i][0] 表示第i天持有股票所得最多现金
		// 保持不变: dp[i-1][0] 
		// 第i天买入股票：
			// 冷冻期后一天买入：dp[i-1][3] - prices[i]
			// 保持买入股票状态：dp[i-1][1] - prices[i]
		
		// 状态1：
		// dp[i][1] 保持股票卖出的状态
			// 保持不变：dp[i-1][1]
			// 冷冻期后一天也是保持卖出的状态，前一天是冷冻期，dp[i-1][3]
		
		// 状态2：
		// dp[i][2] 表示第i天卖出股票的状态,前一天肯定持股
		// 第i天卖出股票: dp[i][2] = dp[i-1][0] + prices[i] 
		
		// 状态3：
		// dp[i][3]: 冷冻期
		//冷冻期前一天肯定是卖出股票 dp[i][3] = dp[i-1][2]
		
		int len = prices.size();
		if(len <= 1)
			return 0;
		vector<vector<int>> dp(len, vector<int>(4));
		dp[0][0] = -prices[0];
		dp[0][1] = 0;
		dp[0][2] = 0;
		dp[0][3] = 0;
		
		for(int i = 1; i < len; i++)
		{
			dp[i][0] = max(dp[i-1][0], max(dp[i-1][1] - prices[i], dp[i-1][3] - prices[i]));
			dp[i][1] = max(dp[i-1][3], dp[i-1][1]);
			dp[i][2] = dp[i-1][0] + prices[i];
			dp[i][3] = dp[i-1][2];			
		}
		
		return max(dp[len-1][1], max(dp[len-1][2], dp[len-1][3]));
	}
};

int main()
{
	Solution s;
	vector<int> profit{1,2};
	int ret = s.maxProfit(profit);
	cout << "\nret: " << ret;
	return 0; 
}

