#include <iostream>
#include <vector>
#include <climits>
#include <list>
#include <queue>

using namespace std;

//基础实现
/*
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
	
	vector<int> minDist(n+1, INT_MAX);
	minDist[start] = 0;
	// 对所有边 松弛 n-1 次
	bool flag = false;				// 判断是否有负
	for(int i = 1; i <= n ; i++)
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
			if(i < n)
			{
				if(minDist[from] != INT_MAX && minDist[from] + val < minDist[to])
					minDist[to] = minDist[from] + val;
			}
			else 	// 多加一次松弛判断负权回路
			{
				if(minDist[from] != INT_MAX && minDist[from] + val < minDist[to]) 
					 flag = true;
			}
		}
	}
	
//	for(int i = 0; i < n; i++){
//		cout << minDist[i] << " ";
//	}
	
	 if (flag) 							// 有负价环
		cout << "circle" << endl;
	if (minDist[end] == INT_MAX) 
		cout << "unconnected" << endl; 	// 不能到达终点
	else 
		cout << minDist[end] << endl; 	// 到达终点最短路径
	return 0;
}
*/

//队列优化实现
struct Edge{
	int to;
	int val;
	Edge(int t,int v):to(t),val(v){}
};

int main()
{
	int n, m;
	cin >> n >> m;
	int p1,p2,val;
	// 使用邻接表 将所有边保存起来
	vector<list<Edge>> grid(n+1);
	while(m--)
	{
		cin >> p1 >> p2 >> val;
		grid[p1].push_back(Edge(p2,val));
	}
	
	int start = 1;  // 起点
	int end = n;    // 终点

	vector<int> minDist(n+1, INT_MAX);
	minDist[start] = 0;
	
	queue<int> que;				// 暂存要处理的节点队列 
	que.push(start);			// 初始化队列
	
	vector<int> count(n+1, 0);	// 记录节点加入队列几次
	count[start]++;
	
	bool flag = false;			// 标记是否有负价环
	while(!que.empty())
	{
		//获取当前要处理的节点
		int cur = que.front();
		que.pop();
		//获取节点所连接的所有边
//		for(int i = 1; i <= n; i++)
//			cout << minDist[i] << " ";
//		cout << endl;
		
		for(Edge edge: grid[cur])
		{
			int from = cur;
			int to = edge.to;
			int val = edge.val;
			//松弛
			if(minDist[from] + val < minDist[to])
			{
//				cout << from << "->" << to << ":" << val << endl;
				minDist[to] = minDist[from] + val;
				que.push(to);
				count[to]++;
				// 如果加入队列次数超过 n-1次 就说明该图与负权回路
				if(count[to] == n) 
				{
					flag = true;
					while(!que.empty()) 
						que.pop();
					break;
				}
			}
 		}
	}
	
//	for(int i = 0; i < n; i++){
//		cout << minDist[i] << " ";
//	}
	if (flag) 
		cout << "circle" << endl;
	else if (minDist[end] == INT_MAX) 
		cout << "unconnected" << endl; 	// 不能到达终点
	else 
		cout << minDist[end] << endl; 	// 到达终点最短路径
	return 0;
}
