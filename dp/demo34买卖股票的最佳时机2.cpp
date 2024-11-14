#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) 
{
    //dp[i][0]: 表示当天持有股票的最大现金
    //dp[i][1]: 表示当天不持有股票的最大现金   
    vector<vector<int>> dp(prices.size(), vector<int>(2));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        // 当天持有 = 前一天持有 + 当天买入
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
        // 当天不持有 = 前一天就不持有 + 当天卖出
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
    }

    // cout << "买入" << "  卖出" << endl;
    // for (size_t i = 0; i < dp.size(); i++)
    // {
    //     cout << dp[i][0] << "   " << dp[i][1] << endl;
    // }
    return dp[prices.size()-1][1];
}

int main()
{
    vector<int> prices{7,1,5,3,6,4};
    int ret = maxProfit(prices);
    cout << "ret:" << ret << endl; 
}