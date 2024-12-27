#include <bits/stdc++.h>

using namespace std;

void dfs(vector<list<int>> &graph, int cur, vector<bool> &visited)
{
    visited[cur] = true;
    // 遍历 cur 连接的所有的边
    for(auto item: graph[cur]) 
    {
        // 下一条边是未访问过的
        if(visited[item] ==  false)
        {
            dfs(graph, item, visited);
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    int s, t;
    vector<list<int>> graph(n + 1); 
    while (k--) {
        cin >> s >> t;
        graph[s].push_back(t);
    }

    vector<bool> visited(n + 1, false);

    // dfs遍历能到达的点
    dfs(graph, 1, visited);

    // 判断能否到达所有的点
    for(int i = 1; i <= n; i++) {
        if(visited[i] ==  false) {
            cout << "-1" << endl;
            return 0;
        }
    }
    cout << "1" << endl;
    return 0;
}