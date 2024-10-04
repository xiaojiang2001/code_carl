#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
	{
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		
//		vector<vector<int>> dp(m, vector<int>(n));
//		int flag = 0;			// 标记第一行和第一列是否遇到了石头
//		// 第一列
//		for(int i = 0; i < m; i++)
//		{
//			if(obstacleGrid[i][0] == 1 && flag == 0)	// 第一次遇到石头
//			{
//				dp[i][0] = 0;
//				flag = 1;
//			}
//			else										// 遇到石头了以后或者本身为空	
//			{
//				if(flag)
//					dp[i][0] = 0;
//				else
//					dp[i][0] = 1;
//			}
//		}
//			
//		// 第一行
//		flag = 0;
//		for(int  j = 0; j < n; j++)
//		{
//			if(obstacleGrid[0][j] == 1 && flag == 0)
//			{
//				dp[0][j] = 0;
//				flag = 1;
//			}	
//			else
//			{
//				if(flag)
//					dp[0][j] = 0;
//				else
//					dp[0][j] = 1;
//			}	
//		}
		
		// 初始化程序优化
		vector<vector<int>> dp(m, vector<int>(n,0));
		// 第一列
		for(int i = 0; i < m; i++)
		{
			if(obstacleGrid[i][0])
				break;
			else
				dp[i][0] = 1;
		}
		// 第一行
		for(int  j = 0; j < n; j++)
		{
			if(obstacleGrid[0][j])
				break;
			else
				dp[0][j] = 1;
		}
			
		// 其他块
		for(int i = 1; i < m; i++)
		{
			for(int j = 1; j < n; j++)
			{
				if(obstacleGrid[i][j] == 0)
					dp[i][j] = 0;
				else
					dp[i][j] = dp[i][j-1] + dp[i-1][j]; 
			}
		}		
		return dp[m-1][n-1];
	}
};

int main()
{
	Solution s;
	vector<vector<int>> obstacleGrid{{0,1},{0,0}};
	cout << obstacleGrid[0].size();
	int ret = s.uniquePathsWithObstacles(obstacleGrid);
	cout << "ret: " << ret << endl;
	return 0;
}
