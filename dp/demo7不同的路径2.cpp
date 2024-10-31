#include <iostream>
#include <vector>

using namespace std;


int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
{
    // dp[i][j] : 表示从start到[i][j]的路径为dp[i][j]   全部初始化为0
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n,0));

    // 初始化第一行和第一列障碍物前的路径为1 后面的为0 已初始化
    for (int i = 0; i < m; i++) {
        if (obstacleGrid[i][0] == 1)
            break;
        dp[i][0] = 1;
    }
    for (int j = 0; j < n; j++) {
        if (obstacleGrid[0][j] == 1)
            break;
         dp[0][j] = 1;
    }
    
    // 遍历整个地图
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            // 当前是否为障碍物
            if (obstacleGrid[i][j]  == 1)   
                dp[i][j] = 0;
            else    
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[m-1][n-1];
}


int main()
{
    vector<vector<int>> grid{{0,0,0},{0,1,0},{0,0,0}};

    int ret = uniquePathsWithObstacles(grid);
    cout << "ret: " << ret << endl;
    return 0;
}