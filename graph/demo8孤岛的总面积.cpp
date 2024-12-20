#include <bits/stdc++.h>

using namespace std;

int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
// 将矩阵四周边缘邻接的陆地全部变成海洋，剩下的就是孤岛了
void dfs(vector<vector<int>>& grid, int x, int y)
{   
    grid[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
            continue;
        if(grid[nextx][nexty] == 1)
        {
            dfs(grid, nextx, nexty);
        }
    }
    return;
}


int main()
{
    int n,m;
    cin >> n >> m;
    // 存储
    vector<vector<int>> grid(n, vector<int>(m,0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    // 左侧第一列
    for (int i = 0; i < n; i++) {
        if(grid[i][0] == 1)
            dfs(grid, i, 0);
    }
    // 右侧列
    for (int i = 0; i < n; i++) {
        if(grid[i][m-1] == 1)
            dfs(grid, i, m-1);
    }
    // 第一行
    for (int j = 0; j < m; j++) {
        if(grid[0][j] == 1)
            dfs(grid, 0, j);
    }
    // 最后一行
    for (int j = 0; j < m; j++) {
        if(grid[n-1][j] == 1)
            dfs(grid, n-1, j);
    }

    // 统计孤岛面积
    int sum = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(grid[i][j] ==  1)
                sum++;
        }
    }
    cout << sum;
    return 0;
}