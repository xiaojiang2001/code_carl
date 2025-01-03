#include <bits/stdc++.h>
#include <climits>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int s, t, val;
    vector<vector<int>> grid(n+1, vector<int>(n+1, INT_MAX));
    vector<int> minDist(n+1, INT_MAX);              // 记录每个点到源点的最短距离
    vector<int> isInPath(n+1, false);               // 记录每个点是否在路径中
    while (m--)
    {
        cin >> s >> t >> val;
        grid[s][t] = val; 
    }

    minDist[1] = 0;                             // 起始点到自身的距离为0
    for (int i = 1; i < n; i++)
    {
        // 1. 找离源点最近的点
        int cur = 0;
        int minVal = INT_MAX;
        for(int j = 1; j <= n; j++)
        {
            if(!isInPath[j] && minDist[j] < minVal)
            {
                cur = j;
                minVal = minDist[j];
            }
        }

        // 2. 当前节点加入路径
        isInPath[cur] = true;

        // 更新minDist数组
        for(int j = 1; j <= n; j++)
        {
            if(!isInPath[j] &&  grid[cur][j] != INT_MAX && minDist[cur] + grid[cur][j] < minDist[j])
                minDist[j] = minDist[cur] + grid[cur][j];
        }
    }
    
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << minDist[i] << " ";
    // }
    
    if (minDist[n] == INT_MAX) 
        cout << -1 << endl;         // 不能到达终点
    else 
        cout << minDist[n] << endl; // 到达终点最短路径

    return 0;
}