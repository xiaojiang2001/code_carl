#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> father(1001, 0);

void init()
{
    for(int i = 1; i <= n; i++)
        father[i] = i;
}

int find(int i)
{
    if(i == father[i])
        return i;
    father[i] = find(father[i]);
    return father[i];
}

void join(int u, int v)
{
    u = find(u);
    v = find(v);
    if(u == v)
        return;
    father[v] = u;
}

bool isSame(int u, int v)
{
    u = find(u);
    v = find(v);
    if(u == v)
        return true;
    return false;
}

bool isTreeAfterMoveEdge(vector<vector<int>> &edges, int deleteEdge)
{
    init();         // 初始化并查集
    for(int i = 0; i < n; i++)
    {

    }
    
}

int main()
{
    int n, s, t;
    cin >> n;
    vector<vector<int>> edges;          // 保存边
    vector<int> inDegree(n+1, 0);       // 统计每个点的入度
    while (n--) {
        cin >> s >> t;
        inDegree[t]++;
        edges.push_back({s,t});
    }

    //获取入度为2的点连接的边，若有，就有2条
    vector<int> vec;
    for(int i = n - 1; i >= 0; i--)
    {
        if(inDegree[edges[i][1]] == 2) {
            vec.push_back(i);
        }
    }
    
    // 存在入度为2的点
    if(vec.size() > 0)
    {

    }

}