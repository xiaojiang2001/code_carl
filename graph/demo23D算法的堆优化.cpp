#include <bits/stdc++.h>

using namespace std;


class Cmp
{
public:
    bool operator()(const pair<int,int> &first, const pair<int,int> &second)
    {
        return first.second > second.second;
    }
};


int main()
{
    int n,m;
    cin >> n >> m;

    vector<list<pair<int, int>>> grid(n + 1);
    int s,t,val;
    while (m--)
    {
        cin >> s >> t >> val;
        grid[s].push_back({t,val});
    }

    // 优先队列中存放 pair<节点编号，源点到该节点的权值> 
    priority_queue<pair<int,int>, vector<pair<int, int>>, Cmp> pq;
    



    return 0;
}