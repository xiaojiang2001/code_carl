#include <iostream>
#include <vector>

using namespace std;

int area;		//当前面积
int dir[4][2] = {1,0,0,1,-1,0,0,-1};
void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y)
{
	//遍历四周的岛屿
	for(int i = 0; i < 4; i++)
	{
		int nextx = x + dir[i][0];
		int nexty = y + dir[i][1];
		if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
			continue;
		//发现没有遍历过的陆地
		if(!visited[nextx][nexty] && grid[nextx][nexty] == 1)
		{
			visited[nextx][nexty] = true;
			area++;			//面积 + 1
			//深度搜索下一个的相连的岛屿
			dfs(grid,visited,nextx,nexty);
		}
	}
}

int main()
{
	int n,m;
	int result = 0;
	cin >> n >> m;
	vector<vector<int>> grid(n,vector<int>(m));
	vector<vector<bool>> visited(n,vector<bool>(m,false));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++){
			cin >> grid[i][j];
		}
	}
	
	//遍历岛屿
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++){
			//没有访问过的陆地
			if(!visited[i][j] && grid[i][j] == 1)
			{
				visited[i][j] = true;
				area = 1;
				dfs(grid,visited,i,j);		//标记相连的陆地为true
				result = max(result,area);	//记录最大的陆地面积
			}
		}
	}
	
	cout << result << endl;
}

