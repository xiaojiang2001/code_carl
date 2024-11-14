#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices, int fee) 
{
    if(prices.size() <= 1)
	    return 0;
    //dp[i][0]:  保持持有   
    //dp[i][1]:  保持不持有
    vector<vector<int>> dp(prices.size(), vector<int>(2));
    // 初始化dp
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i] - fee);
    }
    
    // cout << "买入 " <<  " 卖出" << endl;
    // for (int i = 0; i < dp.size(); i++)
    // {
    //     cout << dp[i][0] << "  " << dp[i][1] << endl;
    // }

    return dp[prices.size()-1][1];
}

int main()
{
    // vector<int> prices{7,1,5,3,6,4};
    vector<int> prices{1, 3, 2, 8, 4, 9};
    int fee = 2;
    int ret = maxProfit(prices, fee);
    cout << "ret: " << ret << endl;
    return 0;
}