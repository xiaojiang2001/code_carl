#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n,m;
    cin >> n >> m;

    vector<list<pair<int, int>>> grid(n+1);
    int s,t,val;
    while (m--) {
        cin >> s >> t >> val;
        grid[s].push_back({t,val});
    }
    
    vector<int> minDist(n + 1 , INT_MAX);
    int start = 1;
    int end = n;

    minDist[start] = 0;
    queue<int> que;
    // 加入优化，已经在队里里的元素不用重复添加
    vector<bool> isInQueue(n + 1); 
    que.push(start);
    while (!que.empty())
    {
        int node = que.front();
        que.pop();
        isInQueue[node] = false;
        for (auto edge : grid[node])
        {
            int from = node;
            int to = edge.first;
            int val = edge.second;
            if(minDist[from] != INT_MAX && minDist[from] + val < minDist[to])
                minDist[to] = minDist[from] + val;
            if(isInQueue[to] ==  false) {
                que.push(to);
                isInQueue[to] = true;
            }
        }
    }
    
    if(minDist[end] == INT_MAX)
        cout << "unconnected" << endl;
    else
        cout << minDist[end] << endl;
    return 0;
}