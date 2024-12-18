#include <bits/stdc++.h>

using namespace std;

vector<int> path;
vector<vector<int>> res;

// x表示当前遍历节点，n表示终点
void dfs(vector<list<int>>& graph, int x, int n)
{
    // 到达终点
    if(x == n) {
        res.push_back(path);
        return;
    }
    // 遍历当前节点链接的节点
    for (auto node : graph[x])
    {
        path.push_back(node);
        dfs(graph, node, n);
        path.pop_back();
    }
}

int main()
{
    int n,m;
    cin >> n >> m;

    // 节点编号从1到n，所以申请 n+1 这么大的数组
    vector<list<int>> graph(n+1);

    int s,t;
    while (m--) {
        cin >> s >> t;
        // 使用邻接表 ，表示 s -> t 是相连的
        graph[s].push_back(t);
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