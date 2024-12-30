#include <bits/stdc++.h>

using namespace std;

// l, r为 边两边的节点，val为边的数值
struct Edge {
    int l, r, val;
};

int n;
vector<int> fa(n+1);

void init()
{
    for(int i = 1; i <= n; i++)
        fa[i] = i;
} 

int find(int i)
{
    if(i == fa[i])
        return i;

    fa[i] = find(fa[i]);
        return fa[i];
}

void join(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return;

    fa[v] = u;
}

bool isSame(int u, int v)
{
    u = find(u);
    v = find(v);
    if(u == v)
        return true;
    return false;
}

// 根据边权值排序 升序
bool cmp(Edge &first, Edge &second)
{
    return first.val < second.val;
}

int main()
{
    int m;
    cin >> n >> m;
    int s, t, val;
    vector<Edge> edges;
    while (m--) {
        cin >> s >> t >> val;
        edges.push_back({s, t, val});
    }

    sort(edges.begin(), edges.end(), cmp);

    int cnt = 0;    // 统计已收集的边的条数
    int res = 0;    // 统计最小生成树的长度
    init();     // 初始化并查集
    for (auto  edge : edges)
    {
        if(isSame(edge.l, edge.r) ==  false)   // 两个点不在并查集中 不构成环
        {
            join(edge.l, edge.r);
            cnt++;
            res += edge.val;
            if(cnt == n-1) {
                cout << res << endl;
                return 0;
            }
        }
    }
    
    return 0;
}