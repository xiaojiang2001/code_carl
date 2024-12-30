#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int s, t;
    //记录每个点的入度
    vector<int> inDegree(n, 0);
    unordered_map<int, vector<int>> umap;   // 记录节点依赖关系
    while (m--) {
        cin >> s >> t;
        inDegree[t]++;                      // t的入度加一
        umap[s].push_back(t);               // 记录s指向哪些节点
    }

    queue<int> que;                         // 记录入度为0的节点
    for (int i = 0; i < n; i++)
    {
        if(inDegree[i] == 0)
            que.push(i);
    }
    
    vector<int> res;
    while (!que.empty())
    {
        int node = que.front();
        que.pop();
        res.push_back(node);

        // 获取当前节点连接的下个点
        vector<int> nextNodes = umap[node];
        for (auto item : nextNodes)
        {
            inDegree[item]--;           // 断开下个节点
            if(inDegree[item] == 0)     // 下个节点变成入度为0
                que.push(item);
        }
    }
    

    if(res.size() == n)
    {
        for(int i = 0; i < n - 1; i++)
            cout << res[i] << " ";
        cout << res[n-1] << endl;
    }
    else
        cout << -1 << endl;

    return 0;
}