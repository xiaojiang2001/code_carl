#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> father(1001, 0);

void init()
{
    for(int i = 0; i <= n; i++)
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
    int s, t;
    cin >> n;

    // 初始化并查集
    init();

    while (n--) {
        cin >> s >> t;
        if(isSame(s, t) == false)
            join(s, t);
        else {
            cout << s << " " << t << endl;
            return 0;
        }
    }
    return 0;
}