#include <iostream>
#include <vector>

using namespace std;

int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

// 计算每个陆地的周长
int cntCir(vector<vector<int>>& grid, int x, int y)
{
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) {
            cnt++;
            continue;
        }
        if(grid[nextx][nexty] == 0)
            cnt++;
    }
    return cnt;
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

    int res = 0;
    for (int i = 0; i < n; i++) 
    {
        for(int j = 0; j < m; j++) 
        {
            if(grid[i][j] == 1)
                res += cntCir(grid, i, j);
        } 
    }

    cout << res << endl;
    return 0;
}