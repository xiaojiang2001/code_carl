#include <iostream>
#include <vector>
#include <list>

using namespace std;

// key 当前得到的可以 
// visited 记录访问过的房间 
void dfs(vector<list<int>>& graph, int key, vector<bool>& visited)
{
	list<int> keys = graph[key];
	for(int key: keys)
	{
		if(visited[key] == false)
		{
			visited[key] = true;
			dfs(graph,key,visited);
		}
	}
}

int main()
{
	int n, m, s, t;
	cin >> n >> m;
	
	vector<list<int>> graph(n+1);

	while(m--){
		cin >> s >> t;
		graph[s].push_back(t);
	}
	
	vector<bool> visited(n + 1, false);
	visited[1] = true; 	// 节点1 预先处理
	dfs(graph, 1, visited);
	
	for(int i = 1; i <= n; i++)
	{
		if(visited[i] == false)
		{
			cout << -1 << endl;	
			return 0;
		}
	}
	
	cout << 1 << endl;	
	return 0;
}

