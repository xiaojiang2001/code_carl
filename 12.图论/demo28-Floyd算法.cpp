#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/*
int main()
{
	int n, m;
	cin >> n >> m;
	// C++定义了一个三位数组
	//本题求的是最小值，所以输入数据没有涉及到的节点的情况都应该初始为一个最大数。
	//这样不会影响，每次计算取最小值的时候 初始值对计算结果的影响。
	vector<vector<vector<int>>> grid(n+1, vector<vector<int>>(n+1, vector<int>(n+1, 10005)));
	int u,v,w;
	while(m--)
	{
		cin >> u >> v >> w;
		grid[u][v][0] = w;
		grid[v][u][0] = w;
	}
	
	//Floyd算法
	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
				grid[i][j][k] = min(grid[i][j][k-1], grid[i][k][k-1] + grid[k][j][k-1]);
		}
	}
	
	// 输出结果
	int q;
	int start,end;
	cin >> q;
	while(q--)
	{
		cin >> start >> end;
		if(grid[start][end][n] == 10005)
			cout << -1 << endl;
		else
			cout << grid[start][end][n] << endl;
	}
	
	return 0;
}
*/



//优化
int main()
{
	int n, m;
	cin >> n >> m;
	// C++定义了一个三位数组
	//本题求的是最小值，所以输入数据没有涉及到的节点的情况都应该初始为一个最大数。
	//这样不会影响，每次计算取最小值的时候 初始值对计算结果的影响。
	vector<vector<int>> grid(n+1,vector<int>(n+1, 10005));	//10005是因为边的最大距离是10^4
	int u,v,w;
	while(m--)
	{
		cin >> u >> v >> w;
		grid[u][v] = w;
		grid[v][u] = w;
	}
	
	//Floyd算法
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++)
				grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
		}
	}
	
	// 输出结果
	int q;
	int start,end;
	cin >> q;
	while(q--)
	{
		cin >> start >> end;
		if(grid[start][end] == 10005)
			cout << -1 << endl;
		else
			cout << grid[start][end] << endl;
	}
	
	return 0;
}
