#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) 
{
    if(prices.size() <= 1)
		return 0;
    //dp[i][0]:  持有   
    // 不持有
    //dp[i][1]:  保持不持有
    //dp[i][2]:  当天卖出
    //dp[i][3]:  冷冻期
    vector<vector<int>> dp(prices.size(), vector<int>(4));
    // 初始化dp
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    dp[0][2] = 0;
    dp[0][3] = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        // 持有：保持前一天持有 / 前一天不持有时,当天买入 / 前一天冷冻期，再买入
        dp[i][0] = max(dp[i-1][0], max(dp[i-1][3] - prices[i], dp[i-1][1] - prices[i]));
        // 保持卖出：保持前一天就不持有 / 前两天就卖出+一天的冷冻期
        dp[i][1] = max(dp[i-1][1], dp[i-1][3]);
        // 卖出: 前一天肯定持有
        dp[i][2] = dp[i-1][0] + prices[i];
        // 冷冻期：前一天卖出
        dp[i][3] = dp[i-1][2];
    }

    return max(dp[prices.size()-1][1], max(dp[prices.size()-1][2],dp[prices.size()-1][3]));
}

int main()
{
    // vector<int> prices{7,1,5,3,6,4};
    vector<int> prices{1,2,4};
    int ret = maxProfit(prices);
    cout << "ret: " << ret << endl;
    return 0;
}