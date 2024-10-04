#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int area = 0;	// 统计当前遍历岛屿的面积
int dir[4][2] = {1,0,0,1,-1,0,0,-1};
void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int landIdx)
{
	// 给陆地标记新标签
	grid[x][y] = landIdx;
	//四个方向都会递归
	for(int i = 0; i < 4; i++)
	{
		int nextx = x + dir[i][0];
		int nexty = y + dir[i][1];
		//越界
		if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
			continue;
		//统计相连陆地的面积
		if(!visited[nextx][nexty] && grid[nextx][nexty] == 1)
		{
			area++;
			visited[nextx][nexty] = true;
			dfs(grid, visited, nextx, nexty, landIdx);
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	int isAllLand = true;		//记录是否全部为陆地
	vector<vector<int>> grid(n, vector<int>(m));
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	for(int i = 0;i < n; i++){
		for(int j = 0; j < m; j++){
			cin >>grid[i][j];
		}
	}
	unordered_map<int, int> landArea;
	int landIdx = 2;				//标记岛屿的编号
	for(int i = 0;i < n; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j] == 0)
				isAllLand = false;		//有海洋
			//遍历到新的岛屿 计算每个新陆地形成的岛屿面积
			if(!visited[i][j] && grid[i][j] == 1)
			{
				area = 1;
				visited[i][j] = true;
				// 将与其连接的陆地都标记上 true 同时给每个岛屿编个号 landIdx
				dfs(grid, visited, i, j, landIdx);	
				landArea[landIdx++] = area;	// 标记每一块编号为 landIdx 的面积为 area
			}
		}
	}
	
	// 全是陆地 不用建造了
	if(isAllLand == true)
	{
		cout << n * m << endl;
		return 0;
	}
	
//	cout << "area: " << endl;
//	for(int i = 2; i < landIdx; i++)
//	{
//		cout << landArea[i] << endl;
//	}
//	
//	cout << "landIdx: " << endl;
//	for(int i = 0; i < n; i++){
//		for(int j = 0; j < m; j++){
//			cout << grid[i][j] << " ";
//		}
//		cout << endl;
//	}
//	
	int result = 0;					 // 记录最后结果
	unordered_set<int> visitedGrid;  // 标记访问过的岛屿 特别容易疏忽
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			area = 1;				// 记录连接之后的岛屿面积
			visitedGrid.clear(); 	// 每次使用时，清空
			//访问到海洋了 
			//计算这个海洋节点变成陆地后拼接周围四个方向岛屿的面积
			if(grid[i][j] == 0)
			{
				for(int k = 0; k < 4; k++)
				{
					// 计算周围的相邻坐标
					int nexti = i + dir[k][0];
					int nextj = j + dir[k][1];
					//越界
					if(nexti < 0 || nexti >= grid.size() || nextj < 0 || nextj >= grid[0].size())
						continue;	
					// 添加过的岛屿不要重复添加
					if(visitedGrid.count(grid[nexti][nextj])) 
						continue; 
					//周围遇到新的陆地
					if(grid[nexti][nextj] > 0)
					{
						area += landArea[grid[nexti][nextj]];	// 拼接面积
						visitedGrid.insert(grid[nexti][nextj]); // 标记该岛屿已经添加过
					}	
				}
				//cout << area << endl;
				result = max(result,area);
			}
		}
	}
	cout << "res: " << result << endl;
}
