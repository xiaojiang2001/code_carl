#include <iostream>
#include <vector>
#include <climits>
using  namespace std;

int main()
{
	int n, m;	// n个节点 m条边
	cin >> n >> m;
	
	int s, e, v;
	vector<vector<int>> grid(n + 1, vector<int>(n + 1, INT_MAX));
	while(m--)
	{
		cin >> s >> e >> v;
		grid[s][e] = v;
	}
	
	//标记起点和终点
	int start = 1;
	int end = n;
	
	// 标记节点1到每个节点的最短距离
	vector<int> minDist(n+1, INT_MAX);
	// 标记每个节点是否被访问过
	vector<bool> visited(n+1,false);
	minDist[start] = 0;
	
	for(int i = 0; i <= n; i++)
	{
		int minDis = INT_MAX;		// 记录本轮循环中距离最近的点的距离
		int cur = 1;				// 记录本轮循环中距离最近的点
		
		// 1、选距离源点最近且未访问过的节点
		// 判断是否加入路径的要求
		//1. 该节点没有被访问过
		//2. 该节点距离当前节点距离最短
		for(int j = 1; j <= n; j++)
		{
			if(!visited[j] && minDist[j] < minDis)
			{
				minDis = minDist[j];
				cur = j;
			}
		}
		
		// 2、标记该节点已被访问
		visited[cur] = true;
		
		// 3、更新非访问节点到源点的距离（即更新minDist数组）
		// 遍历cur邻接的节点(cur的邻边)
		for(int j = 1; j <= n; j++)
		{
			// !visited[j] 未访问过的节点
			// cur邻边有值，即是与cur直连的
			// minDist[cur] + grid[cur][j] < minDist[j] 存在比之前更短的路径 更新mindDist[j]
			if(!visited[j] && grid[cur][j] != INT_MAX && minDist[cur] + grid[cur][j] < minDist[j])
			{
				minDist[j] = minDist[cur] + grid[cur][j];
			}
		}
	}
	
	if(minDist[end] == INT_MAX)
		cout << "-1" << endl;
	else
		cout << minDist[end] << endl;
}
