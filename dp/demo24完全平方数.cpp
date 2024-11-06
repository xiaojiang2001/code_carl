#include <iostream>
#include <vector>
#include <math.h>
#include <climits>

using namespace std;

int numSquares(int n) 
{   
    // 和为 i 的完全平方数的最少数量为 dp[i]
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    // 组合问题 先遍历物品 后遍历背包
    // 物品 1 4 9 16
    // 背包 n  问装满背包所用物品的最少个数
    for (int i = 1; i <= sqrt(n); i++)              // 遍历物品
    {
        for (int j = i * i; j <= n; j++)
        {
            if (dp[j - i * i] != INT_MAX)
                dp[j] = min(dp[j], dp[j - i * i] + 1);
        }
    }
    
    return dp[n];
}

int main()
{
    int n = 12;
    int ret = numSquares(n);
    cout << "ret:" << ret << endl;
}