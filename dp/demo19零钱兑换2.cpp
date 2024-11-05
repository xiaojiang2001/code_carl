#include <iostream>
#include <vector>

using namespace std;


int change(int amount, vector<int>& coins) 
{
    // 装满价值为i的背包的组合数为dp[i];
    vector<int> dp(amount + 1);
    dp[0] = 1;                  // dp[0] = 1是 递归公式的基础
    // 组合 先物品 后背包
    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = coins[i]; j <= amount; j++)
        {
            dp[j] += dp[j - coins[i]];
        }
    }
    return dp[amount];
}


int main()
{
    int amount = 5;
    vector<int> coins {1, 2, 5};
    int ret = change(amount, coins);
    cout << ret << endl;
}