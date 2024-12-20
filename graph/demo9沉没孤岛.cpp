#include <bits/stdc++.h>

using namespace std;

int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
// 将矩阵四周边缘邻接的陆地标记为2，剩下的就是孤岛了
void dfs(vector<vector<int>>& grid, int x, int y)
{   
    grid[x][y] = 2;             // 标记值
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

// 1.将靠边的陆地进行标记为2
// 2. 沉没孤岛
// 3. 还原第一次的标记
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
    
    // 1. 把周围的陆地进行标记
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
    // 2. 沉没孤岛
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(grid[i][j] ==  1)
                grid[i][j] = 0;
        }
    }

    // 3. 还原周围陆地
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(grid[i][j] ==  2)
                grid[i][j] = 1;
        }
    }

    // 输出结果
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
           cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}