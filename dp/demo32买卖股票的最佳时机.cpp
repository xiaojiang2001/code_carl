#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// 贪心策略
/*
int maxProfit(vector<int>& prices) 
{
    // dp 表示当前一天获取的最大利益
    vector<int> dp(prices.size()); 
    dp[0] = 0;
    int min = prices[0];
    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] >= min) {
            dp[i] = max(dp[i], prices[i] - min);
        }
        else {
            min = prices[i];
            dp[i] = 0;
        }
    }
    // for (int i = 0; i < dp.size(); i++)
    // {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    return *max_element(dp.begin(), dp.end());
}
*/

// 完全动态规划的思想
int maxProfit(vector<int>& prices) 
{
    //dp[i][0]: 表示第 i 天持有这只股票的最大现金
    //dp[i][1]: 表示第 i 天不持有这只股票的最大现金
    vector<vector<int>> dp(prices.size(), vector<int>(2));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    // 第i天持有：第i天买入 + 第 i-1 天买入, 第 i 天保持不变
    for (int i = 1; i < prices.size(); i++)
    {
        // 保持 + 买入
        dp[i][0] = max(dp[i-1][0], -prices[i]);
        // 保持 + 当天卖出
        dp[i][1] = max(dp[i-1][1], prices[i] + dp[i-1][0]);
    }

    cout << "买入"  << " " << "卖出" << endl;
    for (int i = 0; i < dp.size(); i++) {
        cout << dp[i][0] << " " << dp[i][1] << endl; 
    }

    return max(dp[prices.size()-1][0], dp[prices.size()-1][1]);
}

int main()
{
    vector<int> prices{7,1,5,3,6,4};
    maxProfit(prices);
    return 0;
}