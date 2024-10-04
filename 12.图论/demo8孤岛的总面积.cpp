#include <iostream>
#include <vector>

using namespace std;


// 方案1：在dfs时候检测是否靠边
// 如果下个岛屿未靠边，ares++
// 如果下个岛屿靠边，则flag标记，最后main函数检测flag标记
/*
int area;
int dir[4][2] = {1,0,0,1,-1,0,0,-1};
int flag = 1;
void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y )
{
	//cout << "dfs: " << x << "," << y << endl;
	for(int i = 0; i < 4; i++)
	{
		int nextx = x + dir[i][0];
		int nexty = y + dir[i][1];
		// 越界
		if(	nextx < 0 || nextx >= grid.size() ||  nexty < 0 || nexty >= grid[0].size() )
			continue;
		//计算相连的陆地形成的岛屿面积
		if(!visited[nextx][nexty] && grid[nextx][nexty] == 1)
		{
			//接触边缘的岛屿为非孤岛 面积置 0 并结束搜索
			if(	nextx == 0 || nextx == grid.size() - 1 ||  
				nexty == 0 || nexty == grid[0].size() - 1)
			{		
				flag = 0;	// 标记为非孤岛
			}
			else	//孤岛
			{
				visited[nextx][nexty] = true;
				area++;
				dfs(grid,visited,nextx,nexty);
			}
		}
	}
}

int main()
{
	int n = 10;
	int m = 10;
	//cin >> n >> m;
	vector<vector<int>> grid{
		{0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
		{0, 0, 1, 0, 0, 0, 1, 1, 1, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
		{0, 0, 0, 1, 0, 1, 0, 1, 0, 0},
		{0, 0, 1, 1, 1, 1, 1, 0, 1, 1},
		{0, 1, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
		{0, 0, 1, 0, 1, 0, 1, 1, 0, 0},
		{1, 1, 1, 1, 0, 1, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 1, 1, 1, 1, 0}
	};
//	vector<vector<int>> grid(n,vector<int>(m));
//	for(int i = 0; i < n; i++){
//		for(int j = 0; j < m; j++){
//			cin >> grid[i][j];
//		}
//	}
	
	vector<vector<bool>> visited(n, vector<bool>(m,false));
	int res = 0;
	//遍历岛屿 靠边的岛屿不用搜索
	for(int i = 1; i < n-1; i++){
		for(int j = 1; j < m-1; j++){
			//遍历未访问的岛屿同时是陆地
			if(!visited[i][j] && grid[i][j] == 1)
			{
				visited[i][j] = true;
				area = 1;
				flag = 1;	//默认为孤岛
				// 将相邻的陆地都标记为 true
				dfs(grid,visited,i,j);
				if(flag)
					res += area;
				
//				// 非孤岛的面积为0 孤岛面积 >= 1
//				if(area > 0)
//					cout << area << ": " << i << "," << j << endl;
				
			}
		}
	}
	cout << res << endl;
}
*/

// 本题要求找到不靠边的陆地面积，那么我们只要从周边找到陆地然后 通过 dfs或者bfs 
//将周边靠陆地且相邻的陆地都变成海洋，然后再去重新遍历地图 统计此时还剩下的陆地就可以了。

// 将相连的岛屿全部变成海洋
int dir[4][2] = {1,0,0,1,-1,0,0,-1};
int cnt = 0;
void dfs(vector<vector<int>>& grid, int x, int y)
{
	cnt++;
	grid[x][y] = 0;
	for(int i = 0; i < 4; i++)
	{
		int nextx = x + dir[i][0];
		int nexty = y + dir[i][1];
		if(	nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
			continue;
		if(grid[nextx][nexty] == 1)
			dfs(grid,nextx,nexty);
	}
	return;
}

int main()
{
	int n;
	int m;
	cin >> n >> m;
	vector<vector<int>> grid(n,vector<int>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> grid[i][j];
		}
	}
	vector<vector<bool>> visited(n, vector<bool>(m,false));
	
	//遍历左右两边的岛屿 使相连的陆地全部变成海洋
	for(int i = 0; i < n;i++)
	{
		//左边
		if(grid[i][0] == 1)
			dfs(grid, i, 0);
		if(grid[i][m-1] == 1)
			dfs(grid, i, m-1);
	}
	//遍历上下两边的岛屿 使相连的陆地全部变成海洋
	for(int j = 0; j < m; j++)
	{
		if(grid[0][j] == 1)
			dfs(grid, 0, j);
		if(grid[n-1][j] == 1)
			dfs(grid, n-1, j);
	}
	
	//遍历岛屿 剩下的陆地全是孤岛了
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	
	
	
	cnt = 0;
	//遍历岛屿 剩下的陆地全是孤岛了
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(grid[i][j] == 1)
				dfs(grid,i,j);
		}
	}

	cout << cnt << endl;
}
