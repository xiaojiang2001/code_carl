#include <bits/stdc++.h>
using namespace std;

// 四个方向
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

// 把 x y 邻接的陆地全部进行标记 形成陆地
// 无结束条件 个人认为更易于理解 结束条件写在了下次递归的条件里面
/*
void dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited, int x, int y)
{
    // 遍历该岛屿四个方向的岛屿
    for (int i = 0; i < 4; i++)
    {
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        // 越界
        if(nextx < 0 || nexty < 0 || nextx >= grid.size() || nexty >= grid[0].size())
            continue;
        if(grid[nextx][nexty] == 1 && visited[nextx][nexty] == false)
        {
            visited[nextx][nexty] = true;
            dfs(grid, visited, nextx, nexty);
        }
    }
}
*/

void dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited, int x, int y)
{
    // 访问过的 或者 非陆地 返回
    if(visited[x][y] == true || (grid[x][y] == 0 && visited[x][y] == false))
        return;
    // 未访问的陆地 进行标记
    visited[x][y] = true;
    // 遍历该岛屿四个方向的岛屿
    for (int i = 0; i < 4; i++)
    {
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        // 越界
        if(nextx < 0 || nexty < 0 || nextx >= grid.size() || nexty >= grid[0].size())
            continue;
        dfs(grid, visited, nextx, nexty);
    }
}


int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m,0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // 记录每个格子的访问情况
    int res = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // 出现未被访问过的陆地，即出现新的陆地
            // 通过dfs把该陆地邻接的陆地全部进行标记，形成一片岛屿
            if(grid[i][j] == 1 && visited[i][j] ==  false)
            {
                res++;           
                dfs(grid, visited, i, j);
            }
        }
    }
    cout << res << endl;
    return 0;
}