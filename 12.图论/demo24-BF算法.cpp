#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// 边结构 存储边
struct Edge{
	int from;
	int to;
	int val;
};

int main()
{
	int n, m;
	cin >> n >> m;
	int s,t,k;
	
	vector<Edge> grid;
	while(m--)
	{
		cin >> s >> t >> k;
		grid.push_back(Edge{s,t,k});
	}

	int start = 1;  // 起点
	int end = n;    // 终点
	
	//记录每个节点到源点的最短路径
	vector<int> minDist(n+1, INT_MAX);
	minDist[start] = 0;
	// 对所有边 松弛 n-1 次
	for(int i = 1; i < n ; i++)
	{
		// 每一次松弛，都是对所有边进行松弛
		for(Edge edge: grid)
		{
			int from = edge.from;	// 边的出发点
			int to = edge.to;		// 边的到达点
			int val = edge.val;		// 边的权值
			//cout << from << "->" << to << ":" << val << endl;
			// 松弛操作 
			// minDist[from] != INT_MAX 防止从未计算过的节点出发
			if(minDist[from] != INT_MAX && minDist[from] + val < minDist[to])
				minDist[to] = minDist[from] + val;
		}
	}
	

//	for(int i = 0; i < n; i++){
//		cout << minDist[i] << " ";
//	}

	
	if (minDist[end] == INT_MAX) 
		cout << "unconnected" << endl; // 不能到达终点
	else 
		cout << minDist[end] << endl; // 到达终点最短路径
	return 0;
}
