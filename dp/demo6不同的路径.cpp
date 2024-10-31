#include <iostream>
#include <vector>

using namespace std;


int uniquePaths(int m, int n) 
{
    // dp[i][j] : 表示从start到[i][j]的路径为dp[i][j]
    vector<vector<int>> dp(m, vector<int>(n,0));

    // 初始化第一列和第一行
    for (int i = 0; i < m; i++)
        dp[i][0] = 1;
    for (int j = 0; j < n; j++)
        dp[0][j] = 1;

    // 当前方案 = 往下走的 + 往右走的
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }

    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    
    return dp[m-1][n-1];
}

int main()
{
    int ret = uniquePaths(3,7);
    cout << "ret: " << ret << endl;
    return 0;
}