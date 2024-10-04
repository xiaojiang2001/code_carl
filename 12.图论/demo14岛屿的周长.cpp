#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int dir[4][2] = {1,0,0,1,-1,0,0,-1};	
	vector<vector<int>> grid(n, vector<int>(m));
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> grid[i][j];
		}
	}
	
	int res = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			// 遇到陆地
			if(grid[i][j] == 1)
			{
				for(int k = 0; k < 4; k++)
				{
					int nexti = i + dir[k][0];
					int nextj = j + dir[k][1];
					if(	nexti < 0 || nexti >= n || 
						nextj < 0 || nextj >= m ||
						grid[nexti][nextj] == 0
						)
					{
						res++;
					}
				}
			}
		}
	}
	cout << res << endl;
	return 0;
}
