#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) 
	{
		vector<vector<int>> dp(m, vector<int>(n,1));
		// 其他块
		for(int i = 1; i < m; i++)
		{
			for(int j = 1; j < n; j++)
			{
				dp[i][j] = dp[i][j-1] + dp[i-1][j]; 
			}
		}
		
//		for(int i = 0; i < m; i++){
//			for(int j = 0; j < n; j++){
//				cout << dp[i][j] << " ";
//			}
//			cout << endl;
//		}
		
		return dp[m-1][n-1];
	}
};

int main()
{
	Solution s;
	s.uniquePaths(3,7);
	//cout << "ret: " << ret << endl;
	return 0;
}
