#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <climits>

using namespace std;

//邻接表
struct Edge{
	int to;
	int val;
	Edge(int t, int w): to(t), val(w) {}  // 构造函数
};


int main()
{
	int n, m;
	cin >> n >> m;
		
	vector<list<Edge>> grid(n+1);
	int s,t,k;
	// 将所有边保存起来
	while(m--)
	{
		cin >> s >> t >> k;
		grid[s].push_back(Edge(t,k));
	}
	
	int start = 1;	// 起点
	int end = n;	// 终点
	
	vector<int> minDist(n+1, INT_MAX);
	minDist[start] = 0;
	
	queue<int> que;
	que.push(start); 
	
	while(!que.empty())
	{
		int cur = que.front();
		que.pop();
		for(Edge edge: grid[cur])
		{
			int from = cur;
			int to = edge.to;
			int val = edge.val;
			//cout << from << "->" << to << ":" << val << endl;
			// 开始松弛
			if(val + minDist[from] < minDist[to])
			{
				minDist[to] = val + minDist[from];
				que.push(to);
			}
		}
	}
	
//	for(int i = 0; i < n; i++){
//		cout << minDist[i] << " ";
//	}
	
	if(minDist[end] == INT_MAX)
		cout << "unconnected" << endl;
	else
		cout << minDist[end] << endl;
}
