#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
	int v1;
	int v2;
	int val;
};
//按边的权值排序仿函数
bool cmp(Edge& edge1, Edge& edge2)
{
	return edge1.val < edge2.val;
}


// 并查集功能模板
int n = 10001;				// 边树
vector<int> fa(10001);

void init()
{
	for(int i = 1; i <= n; i++)
		fa[i] = i;
}

int find(int i)
{
	if(fa[i] == i)
		return i;
	else
	{
		fa[i] = find(fa[i]);
		return fa[i];
	}
}

void join(int u, int v)
{
	int u_fa = find(u);
	int v_fa = find(v);
	if(u_fa == v_fa)
		return;
	fa[v_fa] = u_fa;
}

bool isSame(int u, int v)
{
	int u_fa = find(u);
	int v_fa = find(v);
	return u_fa == v_fa;
}


int main()
{
	int v, e;
	cin >> v >> e;
	
	int x, y, k;
	vector<Edge> edges;		// 边容器
	while(e--)
	{
		cin >> x >> y >> k;
		edges.push_back({x,y,k});
	}
	// 将边按权值从小到大排序
	sort(edges.begin(), edges.end(), cmp);
	
	
	// 并查集初始化
	init();
	
	// 遍历排序后的每条边
	vector<Edge> result; 	// 存储最小生成树的边
	for(auto edge: edges)
	{
		// 加入这条边成环
		if(isSame(edge.v1, edge.v2))
			continue;
		else
		{
			join(edge.v1, edge.v2);
			result.push_back(edge);
		}
	}
	
	// 计算生成树大小
	int res = 0;
	for(auto edge: result)
		res += edge.val;
	
	cout << res << endl;
	
}
