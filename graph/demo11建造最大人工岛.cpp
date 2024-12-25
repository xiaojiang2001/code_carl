#include <iostream>
#include <vector>
#include <unordered_map> 
#include <algorithm>
#include <unordered_set>

using namespace std;

// 当前岛屿的面积
int area = 0;  
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
// 标记陆地的起始下标
int idx = 2;                   
void dfs(vector<vector<int>>& grid, int x, int y)
{
    grid[x][y] = idx;
    for (int i = 0; i < 4; i++)
    {
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
            continue;
        if(grid[nextx][nexty] == 1) {
            area++;
            dfs(grid, nextx, nexty);
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

    // 是否全部陆地
    bool flag = true;
    // 1. 计算每一块岛屿的面积，并做map标记
    unordered_map<int, int> umap;

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if(grid[i][j] == 0)
                flag = false;
            if(grid[i][j] == 1) 
            {
                area = 1;
                dfs(grid, i, j);
                // 对每一块陆地进行标记与面积映射
                umap[idx++] = area;
            }
        }
    }

    // 全部陆地
    if(flag){
        cout << n * m << endl;
        return 0;
    }
        

    int res = 0;
    unordered_set<int> uset;
    // 2. 遍历地图，遍历0的方格，并统计该1(0转1)周边岛屿面积，将其相邻面积相加在一起
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if(grid[i][j] == 0)
            {
                uset.clear();
                area = 1;
                // 统计每个陆地四个方向的面积
                for(int k = 0; k < 4; k++)
                {
                    int nextx = i + dir[k][0];
                    int nexty = j + dir[k][1];
                    // 越界
                    if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
                        continue;
                    // 周围为海洋
                    if(grid[nextx][nexty] == 0)
                        continue;
                    // 周围为陆地且未添加
                    if(uset.find(grid[nextx][nexty]) == uset.end())
                    {
                        area += umap[grid[nextx][nexty]];
                        uset.insert(grid[nextx][nexty]);
                    }
                }
                // cout << area << endl;
                res = max(res, area);
            }
        }
    }
    cout << res << endl;
    return 0;
}
/*
10 10
1 0 0 0 1 0 0 0 0 0
1 1 0 1 1 0 1 0 1 0
1 0 1 1 1 0 0 1 0 0
1 0 1 1 0 0 0 1 0 0
1 1 1 1 1 0 0 1 0 0
1 0 1 1 0 0 0 1 0 0
1 1 1 0 0 1 1 0 1 1
0 1 1 0 1 1 0 0 0 1
0 0 0 1 0 0 0 0 1 1
1 1 1 0 1 0 0 0 0 0
*/