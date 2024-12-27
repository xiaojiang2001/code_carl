#include <bits/stdc++.h>

using namespace std;

int n = 1005;
vector<int> fa(n, 0);
void init()
{
    for (int i = 0; i < n; i++)
        fa[i] = i;
}

// 并查集里寻根的过程
int find(int u)
{
    if(u == fa[u])
        return u;
    else {
        fa[u] = find(fa[u]);
        return fa[u];
    }
}
// 将v，u 这条边加入并查集
void join(int u, int v)
{
    u = find(u);
    v = find(v);
    if(u == v)
        return;
    fa[v] = u;
}

// 判断 u 和 v是否找到同一个根
bool isSame(int u, int v)
{
    u = find(u);
    v = find(v);
    if(u == v)
        return true;
    return false;
}
int main()
{

    return 0;
}