#include <iostream>
#include <vector>
#include <climits>			// IINT_MAX

using namespace std;


int main()
{
	int v,e;
	int x,y,k;
	
	cin >> v >> e;
	vector<vector<int>> grid(v+1, vector<int>(v+1, 10001));
	while(e--){
		cin >> x >> y >> k;
		// 因为是双向图，所以两个方向都要填上
		grid[x][y] = k;
		grid[y][x] = k;
	}
	

	// 标记节点是否在生成树中
	vector<bool> isInTree(v+1, false);
	// 记录非生成树中的节点到生成树的最短距离
	vector<int> minDist(v+1, 10001);
	
	
	
	// 只需要循环 n-1次，建立 n - 1条边，就可以把n个节点的图连在一起
	for(int i = 1; i < v; i++)
	{
		// 步骤一、选距离生成树最近节点
		int cur = -1;			// 待加入到生成树中的节点
		int minDis = INT_MAX;	// 记录本轮离生成树最近距离
		for(int j = 1; j <= v; j++)
		{
			// 加入生成树的条件：
			// 1. 节点不在生成树中
			// 2. 距离最小生成树最近的节点
			if(!isInTree[j] &&  minDist[j] < minDis)
			{
				minDis = minDist[j];
				cur = j;	
			}
		}
		
		// 步骤二、最近节点加入生成树
		isInTree[cur] = true;
		
		
		// 第三步、更新非生成树节点到生成树的距离
		// cur节点加入之后， 最小生成树加入了新的节点，
		// 那么所有节点到 最小生成树的距离（即minDist数组）需要更新一下
		// 由于cur节点是新加入到最小生成树，那么只需要关心与 cur 相连的 非生成树节点 的距离 
		// 是否比 原来 非生成树节点到生成树节点的距离更小了呢
		for(int j = 1; j <= v; j++)
		{
			// 更新节点的要求：
			// 1. 节点不在生成树中
			// 2. 与cur相连的某节点的权值 比 该某节点距离最小生成树的距离小
			if(!isInTree[j] &&  grid[cur][j] < minDist[j]){
				minDist[j] = grid[cur][j];
			}
		}
	}
	
	// 统计结果
	int result = 0;
	// 不计第一个顶点，因为统计的是边的权值，v个节点有 v-1条边
	for (int i = 2; i <= v; i++) { 
		result += minDist[i];
	}
	cout << result << endl;
}



