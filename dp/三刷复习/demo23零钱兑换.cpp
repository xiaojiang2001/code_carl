#include <bits/stdc++.h>

using namespace std;

// 全完背包 求装满完全背包的元素最小个数 组合
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 0; i < coins.size(); i++)      // 先物品
    {
        for (int j = coins[i]; j <= amount; j++) // 后背包
        {
            // 如果dp[j - coins[i]]是初始值则跳过
             if (dp[j - coins[i]] != INT_MAX) { 
                dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
            }
        }
    }
    if(dp[amount] != INT_MAX)
        return dp[amount];
    
    return -1;
}