#include <iostream>
#include <vector>

using namespace std;

int findMaxForm(vector<string>& strs, int m, int n) 
{
    // 装满i个0 j个1大小的背包里面最多有dp[i][j]个物品 背包有2个维度
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    // 遍历物品
    for (auto str:strs)
    {
        // 获取每个字符串由 x个0 y个1组成
        int x = 0;
        int y = 0;
        for (auto chr : str) {
            if (chr == '0') x++;
            else            y++;
        }
        // cout << "x: " << x << " y: " << y << endl;
        // 遍历背包容量
        for (int i = m; i >= x; i--)
        {
            for (int j = n; j >= y; j--)
            {
                // dp[j] = max(dp[j], [j-weightdp[i]] + value[i]);
                dp[i][j] = max(dp[i][j], dp[i-x][j-y] + 1);
            }    
        }
    }
    // 打印dp数组
    // for (int i = 0; i <= m; i++)
    // {
    //     for (int j = 0; j <= n; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return dp[m][n];
}

int main()
{
    vector<string> strs{"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3;
    int ret = findMaxForm(strs, m, n);
    cout << "ret:" << ret << endl;
}
