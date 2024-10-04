#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge{
	int from;
	int to;
	int val;
	Edge(int x, int y, int k):from(x),to(y),val(k){}
};

int main()
{
	int n, m;
	cin >> n >> m;
	
	vector<Edge> grid;
	int s, t, v;
	while(m--)
	{
		cin >> s >> t >> v;
		grid.push_back(Edge{s, t, v});
	}
	int src, dst, k;
	cin >> src >> dst >> k;

	vector<int> minDist(n+1, INT_MAX);
	//松弛 k + 1 次
	minDist[src] = 0;
	// 用来记录上一次遍历的结果
	 vector<int> minDist_copy(n + 1); 
	for(int i = 0; i <= k; i++)
	{
		minDist_copy = minDist;			// 获取上一次计算的结果
		for(Edge edge: grid)
		{
			int from = edge.from;
			int to   = edge.to;
			int val  = edge.val;
			// 注意使用 minDist_copy 来计算 minDist 
			if(minDist_copy[from] != INT_MAX && minDist_copy[from] + val < minDist[to])
				minDist[to] = minDist_copy[from] + val;
		}
	}
	
	if(minDist[dst] == INT_MAX)
		cout << "unreachable" << endl;
	else
		cout << minDist[dst]  << endl;
	
	return 0;
}

