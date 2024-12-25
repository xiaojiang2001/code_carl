#include <iostream>
#include <vector>
using namespace std;

// 将从某个点出发能到达的点进行标记
int dir[4][2] = {1, 0, 0 ,1, -1, 0, 0, -1};
void dfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& visited)
{
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
            continue;
        if(visited[nextx][nexty] == false && grid[nextx][nexty] >= grid[x][y]){
            dfs(grid, nextx, nexty, visited);
        }   
    }
}


int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        } 
    }

    // 标记从第一组边界出发能到达的点
    vector<vector<bool>> visited1(n, vector<bool>(m, false));
    // 第一列
    for (int i = 0; i < n; i++)
        dfs(grid, i, 0, visited1);
    // 第一行
    for (int j = 0; j < m; j++)
        dfs(grid, 0, j, visited1);
    
    // 标记从第二组边界出发能到达的点
    vector<vector<bool>> visited2(n, vector<bool>(m, false));
    // 右边界
    for (int i = 0; i < n; i++)
        dfs(grid, i, m-1, visited2);
    // 下边界
    for (int j = 0; j < m; j++)
        dfs(grid, n-1, j, visited2);

    // 统计结果
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(visited1[i][j] && visited2[i][j])
                cout << i << " " << j << endl;
        }
    }
    
    return 0;
}