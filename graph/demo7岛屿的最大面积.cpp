#include <bits/stdc++.h>

using namespace std;

int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int maxArea = 0;
int curArea = 0;
void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y)
{
    // 在递归中判断 当是未被访问的陆地才递归
    curArea++;
    for (int i = 0; i < 4; i++)
    {
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
            continue;
        if(grid[nextx][nexty] == 1 && visited[nextx][nexty] == false)
        {
            visited[nextx][nexty] = true;
            dfs(grid, visited, nextx, nexty);
        }
    }
    return;
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
    
    vector<vector<bool>> visited(n, vector<bool>(m,false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(grid[i][j] == 1  && visited[i][j] == false)
            {
                visited[i][j] = true;
                curArea = 0;
                // 深度搜索 把x,y周围的陆地进行标记，并计算形成岛屿的面积
                dfs(grid, visited, i, j);
                maxArea = max(maxArea, curArea);
            }
        }
        
    }
    cout << maxArea;

    return 0;
}