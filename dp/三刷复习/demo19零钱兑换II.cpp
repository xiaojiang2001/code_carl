#include <bits/stdc++.h>

using namespace std;

// 全完背包 求组合数
int change(int amount, vector<int>& coins) 
{
    // 背包大小 amount
    vector<int> dp(amount+1, 0);
    // 累加初值
    dp[0] = 1;
    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = coins[i]; j <= amount; j++)
        {
            dp[j] += dp[j-coins[i]];
        }
    }
    return dp[amount];
}