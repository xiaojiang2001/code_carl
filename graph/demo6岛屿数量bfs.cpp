#include <bits/stdc++.h>
using namespace std;

// 四个方向
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
// 把 x y 邻接的陆地全部进行标记 形成陆地

void bfs(vector<vector<int>>& grid,vector<vector<bool>>& visited, int x, int y)
{
    queue<pair<int, int>> que;    // 定义队列
    que.push({x, y});
    visited[x][y] = true;           // 加入队列就标记
    while (!que.empty())
    {
        pair<int, int> cur = que.front();   // 获取队列元素
        que.pop();
        int curx = cur.first;
        int cury = cur.second;
        for(int i = 0; i < 4; i++)
        {
            int nextx = curx + dir[i][0];
            int nexty = cury + dir[i][1];
            if(nextx < 0 || nexty < 0 || nextx >= grid.size() || nexty >= grid[0].size())
                continue;
            if(visited[nextx][nexty] == false && grid[nextx][nexty] == 1)
            {
                que.push({nextx, nexty});
                visited[nextx][nexty] = true;
            }
        }
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
            // 通过bfs把该陆地邻接的陆地全部进行标记，形成一片岛屿
            if(grid[i][j] == 1 && visited[i][j] ==  false)
            {
                res++;     
                visited[i][j] = true;      
                bfs(grid, visited, i, j);
            }
        }
    }
    cout << res << endl;
    return 0;
}