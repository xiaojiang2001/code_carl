#include <iostream>
#include <vector>

using namespace std;
//一个比较直白的想法，其实就是 遍历每个点，
//然后看这个点 能不能同时到达第一组边界和第二组边界
// 超时 整体时间复杂度O(m^2 * n^2) 
/*
int n, m;
int dir[4][2] = {1,0,0,1,-1,0,0,-1};
//从x,y出发，把可走的路都标记上
void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y)
{
	if(visited[x][y]) 
		return;
	
	visited[x][y] = true;
	for(int i = 0; i < 4; i++)
	{
		int nextx = x + dir[i][0];
		int nexty = y + dir[i][1];
		//越界
		if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
			continue;
		//可流水
		if(grid[x][y] >= grid[nextx][nexty])
			dfs(grid, visited, nextx, nexty);
	}
	return ;
}

bool isResult(vector<vector<int>>& grid,int x, int y)
{
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	
	// 深搜，将x,y出发 能到的节点都标记上。
	dfs(grid, visited, x, y);
	//是否到达第一第二边界
	bool isFirst = false;
	bool isSecond = false;
	
	// 以下就是判断x，y出发，是否到达第一组边界和第二组边界
	// 第一边界的上边
	for (int j = 0; j < m; j++) {
		if (visited[0][j]) {
			isFirst = true;
			break;
		}
	}
	// 第一边界的左边
	for(int i = 0; i < n;i++){
		if (visited[i][0]) {
			isFirst = true;
			break;
		}
	}
	// 第二边界右边
	for (int j = 0; j < m; j++) {
		if (visited[n - 1][j]) {
			isSecond = true;
			break;
		}
	}
	// 第二边界下边
	for (int i = 0; i < n; i++) {
		if (visited[i][m - 1]) {
			isSecond = true;
			break;
		}
	}
	if(isFirst && isSecond)
		return true;
	else
		return false;
}

int main()
{
	cin >> n >> m;
	vector<vector<int>> grid(n,vector<int>(m,0));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++){
			cin >> grid[i][j];
		}
	}
	// 遍历每一个点，看是否能同时到达第一组边界和第二组边界
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(isResult(grid,i,j))
				cout << i << " " << j << endl;
		}
	}
}
*/

//那么我们可以 反过来想，从第一组边界上的节点 逆流而上，将遍历过的节点都标记上。
//同样从第二组边界的边上节点 逆流而上，将遍历过的节点也标记上。
//然后两方都标记过的节点就是既可以流太平洋也可以流大西洋的节点。

int n, m;
int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};
void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y)
{
	if(visited[x][y]) 
		return;
	
	visited[x][y] = true;
	for(int i = 0; i < 4; i++)
	{
		int nextx = x + dir[i][0];
		int nexty = y + dir[i][1];
		//越界
		if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
			continue;
		/// 注意：这里是逆向流水
		if(grid[x][y] <= grid[nextx][nexty])
			dfs(grid, visited, nextx, nexty);
	}
	return ;
}

int main()
{
	cin >> n >> m;
	vector<vector<int>> grid(n,vector<int>(m,0));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++){
			cin >> grid[i][j];
		}
	}
	// 标记从第一组边界上的节点出发，可以遍历的节点
	vector<vector<bool>> firstBorder(n, vector<bool>(m, false));
	// 标记从第一组边界上的节点出发，可以遍历的节点
	vector<vector<bool>> secondBorder(n, vector<bool>(m, false));
	
	//左侧和右侧
	for(int i = 0; i < n; i++)
	{
		dfs(grid, firstBorder, i, 0);		// 遍历最左列，接触第一组边界
		dfs(grid, secondBorder, i,m-1);		// 遍历最右列，接触第二组边界
	}
	
	//上下边界
	for(int j = 0; j < m; j++)
	{
		dfs(grid, firstBorder, 0, j);		// 遍历最上册，接触第一组边界
		dfs(grid, secondBorder, n-1, j);	// 遍历最下列，接触第二组边界
	}
	
	
	// 遍历每一个点，看是否能同时到达第一组边界和第二组边界
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(firstBorder[i][j] && secondBorder[i][j])
				cout << i << " " << j << endl;
		}
	}
}

