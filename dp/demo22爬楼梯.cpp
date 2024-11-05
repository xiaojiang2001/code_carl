#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,m;    // n 背包大小，m 物品大小与价值 
    cin >> n >> m;
    
    // 爬上 i 阶楼梯有 dp[i] 种方法
    vector<int> dp(n+1);
    dp[0] = 1;      // 累加根基
    // 排列数 先背包 后物品
    for (int j = 0; j <= n; j++)
    {
        for (int i = 1; i <= m; i++)
        {
            if (j - i >= 0)
                dp[j] += dp[j - i];            
        }
    }

    cout << dp[n] << endl;
    return 0;
}


