#include <iostream>
#include <vector>

using namespace std;



int dir[4][2] = {1,0,0,1,-1,0,0,-1};
//将靠近地图周边的岛屿全部变成 2
void dfs(vector<vector<int>>& grid, int x, int y)
{
	grid[x][y] = 2;
	for(int i = 0; i < 4; i++)
	{
		int nextx = x + dir[i][0];
		int nexty = y + dir[i][1];
		if(	nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
			continue;
		if(grid[nextx][nexty] == 1)
			dfs(grid,nextx,nexty);
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n,vector<int>(m));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> grid[i][j];
		}
	}
	
	// 左右两列
	for(int i = 0; i < n;i++)
	{
		if(grid[i][0] == 1)
			dfs(grid, i, 0);
		if(grid[i][m-1] == 1)
			dfs(grid, i, m-1);
	}
	//上下两行
	for(int j = 0; j < m; j++)
	{
		if(grid[0][j] == 1)
			dfs(grid, 0, j);
		if(grid[n-1][j] == 1)
			dfs(grid, n-1, j);
	}	

	cout << "temp: " << endl;
	for(int i = 0; i < n;i++)
	{
		for(int j = 0; j < m; j++)
		{
			cout << grid[i][j] << " ";
		}		
		cout << endl;
	}
	
	//步骤二 三 周围陆地变成1 孤岛陆地为0
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			//两个顺序不能换 否则全为0
			if(grid[i][j] == 1)	grid[i][j] = 0;
			if(grid[i][j] == 2)	grid[i][j] = 1;
		}		
	}
	
	//输出结果
	for(int i = 0; i < n;i++)
	{
		for(int j = 0; j < m; j++)
		{
			cout << grid[i][j] << " ";
		}		
		cout << endl;
	}
}
