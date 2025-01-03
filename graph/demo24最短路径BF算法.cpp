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

    vector<Edge> grid(n+1);
    int s,t,val;
    while (m--) {
        cin >> s >> t >> val;
        grid.push_back({s,t,val});
    }
    
    vector<int> minDist(n + 1 , INT_MAX);
    minDist[1] = 0;
    // 对所有边 松弛 n-1 次
    for (int i = 1; i < n; i++) 
    {
        // 每一次都是对所有的边进行松弛
        for (auto edge : grid)
        {
            int from = edge.from;
            int to = edge.to;
            int val = edge.val;
            if(minDist[from] != INT_MAX && minDist[from] + val < minDist[to])
                minDist[to] = minDist[from] + val;
        }
    }
    if(minDist[n] == INT_MAX)
        cout << "unconnected" << endl;
    else
        cout << minDist[n] << endl;
    return 0;
}