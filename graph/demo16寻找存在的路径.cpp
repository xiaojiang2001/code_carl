#include <bits/stdc++.h>

using namespace std;

int n = 100;
vector<int> father(n, 0);

void init()
{
    for(int i = 0; i < n; i++)
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


int main()
{
    int N, M;
    int s, t;
    cin >> N >> M;

    // 初始化并查集
    init();     
    while (M--)
    {
        cin >> s >> t;
        join(s, t);     // 加入并查集
    }

    cin >> s >> t;
    // 判断并查集
    bool ret = isSame(s, t);
    if(ret)
        cout << "1" << endl;
    else
        cout << "0" << endl;
}