#include <vector>
#include <iostream>
#include <climits>

using namespace std;

int coinChange(vector<int>& coins, int amount) 
{
    // 装满价值为i的背包的最少硬币数为dp[i]
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < coins.size(); i++)          // 遍历物品
    {
        for (int j = coins[i]; j <= amount; j++)    // 遍历背包
        {
            if (dp[j - coins[i]] != INT_MAX)            
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }
    
    if (dp[amount] == INT_MAX)
        return -1;
    return dp[amount];
}

int main()
{
    vector<int> coins{2};
    int amount = 3;
    int ret = coinChange(coins, amount);
    cout << "ret: " << ret << endl;
}
