#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>

using namespace std;

//邻接矩阵法
/* 
vector<vector<int>> result;		// 手机符合条件的路径
vector<int> path;				//0节点到终点的路径
// graph：存当前的图
// x：目前遍历的节点
// n：终点
void dfs(const vector<vector<int>> graph, int x, int n)
{
	// 当前遍历的节点x 到达节点n 
	if(x == n)
	{
		result.push_back(path);
		return;
	}
	// 遍历节点x链接的所有节点
	for(int i = 1; i <= n; i++)
	{
		// 找到 x指向的节点，就是节点i
		if(graph[x][i] == 1)
		{
			// 将选中的x所指向的节点，加入到 单一路径来。
			path.push_back(i);
			// 进入下一层递归
			dfs(graph,i,n);
			// 回溯的过程，撤销本次添加节点的操作
			path.pop_back();
		}
	}
}

int main()
{
	// m条边 n个节点 
	// graph[s][t] = 1表示节点s可以指向t
	int m,n,s,t;
	cin >> n >> m;
	vector<vector<int>> graph(n+1, vector<int>(n+1,0));
	while(m--)
	{
		cin >> s >> t;
		// 使用邻接矩阵 表示无线图，1 表示 s 与 t 是相连的
		graph[s][t] = 1;
	}
	
	// 任何路径都是从节点1开始
	path.push_back(1);
	// 开始遍历
	dfs(graph,1,n);
	
	// 打印结果
	if(result.size() == 0)
		cout << -1 << endl;
	for(int i = 0; i < result.size();i++)
	{
		for(int j = 0; j < result[i].size() - 1; j++)
		{
			cout << result[i][j] << " ";
		}
		cout << result[i][result[i].size() - 1] << endl;
	}
	
	return 0;
}
*/

//邻接表法
vector<vector<int>> result;		// 手机符合条件的路径
vector<int> path;				//0节点到终点的路径
// graph：存当前的图
// x：目前遍历的节点
// n：终点
void dfs(const vector<list<int>> graph, int x, int n)
{
	// 当前遍历的节点x 到达节点n 
	if(x == n)
	{
		result.push_back(path);
		return;
	}
	// 遍历节点x链接的所有节点
	for(int node: graph[x])
	{
		// 将选中的x所指向的节点，加入到 单一路径来。
		path.push_back(node);
		// 进入下一层递归
		dfs(graph,node,n);
		// 回溯的过程，撤销本次添加节点的操作
		path.pop_back();
	}
}

int main()
{
	// m条边 n个节点 
	// graph[s][t] = 1表示节点s可以指向t
	int m,n,s,t;
	cin >> n >> m;
	vector<list<int>> graph(n+1);
	while(m--)
	{
		cin >> s >> t;
		// 使用邻接矩阵 表示无线图，1 表示 s 与 t 是相连的
		graph[s].push_back(t);
	}
	
	// 任何路径都是从节点1开始
	path.push_back(1);
	// 开始遍历
	dfs(graph,1,n);
	
	// 打印结果
	if(result.size() == 0)
		cout << -1 << endl;
	for(int i = 0; i < result.size();i++)
	{
		for(int j = 0; j < result[i].size() - 1; j++)
		{
			cout << result[i][j] << " ";
		}
		cout << result[i][result[i].size() - 1] << endl;
	}
	
	return 0;
}




// bfs模板
/*
int dir[4][2] ={0,1,1,0,-1,0,0,-1};
// grid 是地图，也就是一个二维数组
// visited标记访问过的节点，不要重复访问
// x,y 表示开始搜索节点的下标
void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y)
{
	queue<pair<int,int>> que;	//定义队列
	que.push({x,y});			//起始节点加入队列
	visited[x][y] = true;		//// 只要加入队列，立刻标记为访问过的节点
	while(!que.empty())
	{
		// 从队列取元素
		pair<int, int> cur = que.front();
		que.pop();
		 // 当前节点坐标
		int curx = cur.first;
		int cury = cur.second;
		// 开始想当前节点的四个方向左右上下去遍历
		for(int i = 0; i < 4; i++)
		{
			// 获取周边四个方向的坐标
			int nextx = curx + dir[i][0];
			int nexty = cury + dir[i][1];
			// 坐标越界了，直接跳过
			if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
				continue;
			 // 如果节点没被访问过
			if(!visited[nextx][nexty])
			{
				// 队列添加该节点为下一轮要遍历的节点
				que.push({nextx,nexty});
				// 只要加入队列立刻标记，避免重复访问
				visited[nextx][nexty] = true;
				
			}
			
		}
	}
}
*/
