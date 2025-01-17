#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int from;
    int to;
    int val;
};

int main()
{
    int n,m;
    cin >> n >> m;

    int s,t,v;
    vector<Edge> grid(n + 1);
    while (m--) {
        cin >> s >> t >> v;
        grid.push_back({s,t,v});
    }

    // 到起点的最短距离
    vector<int> minDist(n+1, INT_MAX);
    // 用来记录上一次遍历的结果
    vector<int> minDist_copy(n+1);

    int src, dst, k;
    cin >> src >> dst >> k;
    minDist[src] = 0;

    // 经过k个点，最多松弛 k+1 条边
    for (int i = 1; i <= k+1; i++)
    {
        minDist_copy = minDist;
        for (auto edge : grid)
        {
            int from = edge.from;
            int to = edge.to;
            int val = edge.val;
            // 使用 minDist_copy 来计算 minDist 
            if(minDist_copy[from] != INT_MAX && minDist_copy[from] + val < minDist[to])
                minDist[to] =  minDist_copy[from] + val;
        }
    }
    
    // 不能到达终点
    if(minDist[dst] == INT_MAX)
        cout << "unreachable" << endl;
    // 到达终点最短路径
    else
        cout << minDist[dst] << endl;

    return 0;
}