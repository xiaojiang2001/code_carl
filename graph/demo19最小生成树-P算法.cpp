#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int s, t, val;
    vector<vector<int>> grid(n+1, vector<int>(n+1, 10001));
    while (m--) {
        cin >> s >> t >> val;
        grid[s][t] = val;
        grid[t][s] = val;
    }

    // 记录每个点到最小生成树的距离
    vector<int> minDist(n + 1, 10001);
    vector<bool> inTree(n + 1, false);

    // 第一步，选距离生成树最近节点
    // 第二步，最近节点加入生成树
    // 第三步，更新非生成树节点到生成树的距离（即更新minDist数组）
    for (int i = 1; i < n; i++)
    {
        // 1. 第一步，选距离生成树最近节点
        int cur = -1;               // 最近的点
        int minVal = INT_MAX;       // 最近的距离
        for(int j = 1; j <= n; j++)
        {
            // 点不在集合中 && 距离最小生成树最近的节点
            if(!inTree[j] && minDist[j] < minVal) {
                cur = j;
                minVal = minDist[j];
            }
        }

        // 2. 把最近的点加入集合
        inTree[cur] = true;

        // 3. 更新minDist数组
        for (int j = 1; j <= n; j++)
        {
            // 点不在集合中 && 该点到最小生成树有直接的边
            if(!inTree[j] && grid[cur][j] < minDist[j]) {
                minDist[j] = grid[cur][j];
            }
        }
    }
    
    int res = 0;
    for (int i = 2; i <= n; i++) {
        res += minDist[i];
    }
    cout << res << endl;
    return 0;
}