#include <bits/stdc++.h>

using namespace std;

vector<int> path;
vector<vector<int>> res;

// x表示当前遍历节点，n表示终点
void dfs(vector<vector<int>>& graph, int x, int n)
{
    // 到达终点
    if(x == n) {
        res.push_back(path);
        return;
    }
    // i 表示下一个节点
    for (int i = 1; i <= n; i++)
    {
        // 找到 x 链接的节点
        if(graph[x][i] ==  1)
        {
            path.push_back(i);
            dfs(graph, i, n);
            path.pop_back();
        }
    }
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));

    int s,t;
    while (m--) {
        cin >> s >> t;
        graph[s][t] = 1;
        // graph[t][s] = 1; 这里是有向图，不需要双向
    }
    // 先把起点加入到路径中
    path.push_back(1);
    dfs(graph, 1, n);

   //打印结果
    if(res.size() == 0)
        cout << -1 << endl;
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size() -  1; j++) {
            cout << res[i][j] << " ";
        }
        cout << res[i][res[i].size() - 1] << endl;
    }
    
    return 0;
}