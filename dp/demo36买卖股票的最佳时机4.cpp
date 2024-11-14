#include <iostream>
#include <vector>

using namespace std;

int maxProfit(int k, vector<int>& prices) 
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
    vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1));
    // 初始化dp
    for (int i = 0; i < 2 * k + 1; i++)
    {
        if(i % 2 == 0)
            dp[0][i] = 0;           // 不操作 + 第 i / 2 次不持有
        else
            dp[0][i] = -prices[0];  // 第i/2 + 1次持有 
    }
    for (int i = 1; i < prices.size(); i++)
    {
        dp[i][0] = dp[i-1][0];
        for (int j = 1; j < 2 * k + 1; j += 2)
        {
            dp[i][j]   = max(dp[i-1][j],   dp[i-1][j-1] - prices[i]);     // 第j次持有 
            dp[i][j+1] = max(dp[i-1][j+1], dp[i-1][j]   + prices[i]);     // 第j次不持有
        }
    }

    return dp[prices.size()-1][2*k];
}

int main()
{
    // vector<int> prices{7,1,5,3,6,4};
    int  k = 2;
    vector<int> prices{3,3,5,0,0,3,1,4};
    int ret = maxProfit(2, prices);
    cout << "ret: " << ret << endl;
    return 0;
}