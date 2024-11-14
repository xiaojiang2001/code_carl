#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) 
{
    if(prices.size() <= 1)
		return 0;
    // dp[i][j]
    // 第 i 天的相关操作
    //dp[i][0]: 不操作
    //dp[i][1]: 第一次持有   保持 + 当天买入
    //dp[i][2]: 第一次不持有 保持 + 当天卖出
    //dp[i][3]: 第二次持有   保持 + 当天买入
    //dp[i][4]: 第二次不持有 保持 + 当天卖出
    vector<vector<int>> dp(prices.size(), vector<int>(5));
    dp[0][0] = 0;               // 不操作
    dp[0][1] = -prices[0];      // 第一次持有 
    dp[0][2] = 0;               // 第一次不持有
    dp[0][3] = -prices[0];      // 第二次持有
    dp[0][4] = 0;               // 第二次不持有

    for (int i = 1; i < prices.size(); i++)
    {
        dp[i][0] = dp[i-1][0];
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);     // 第一次持有 
        dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i]);     // 第一次不持有
        dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i]);     // 第二次持有 
        dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i]);     // 第二次不持有 
    }

    return max(dp[prices.size()-1][2], dp[prices.size()-1][4]);
}

int main()
{
    // vector<int> prices{7,1,5,3,6,4};
    vector<int> prices{3,3,5,0,0,3,1,4};
    int ret = maxProfit(prices);
    cout << "ret: " << ret << endl;
    return 0;
}