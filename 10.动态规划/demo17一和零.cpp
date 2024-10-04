#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) 
	{
		//dp[i][j]: i个0 j个1 最大背dp[i][j]个物品
		vector<vector<int>> dp(m+1, vector<int>(n+1,0));
		// 遍历物品
		for(string str:strs)
		{
			// 记录物品 0 和 1 的个数
			int zeroNum = 0;
			int oneNum  = 0;
			for(char c : str)
			{
				if(c == '0')
					zeroNum++;
				else
					oneNum++;
			}
			// 遍历背包 有2个维度
			for(int i = m; i >= zeroNum;i--)
			{
				for(int j = n; j >= oneNum; j--)
				{
					dp[i][j] = max(dp[i][j], dp[i-zeroNum][j-oneNum] + 1);
				}
			}
		}
		return dp[m][n];
	}
};

int main()
{
	Solution s;
	vector<int> nums{2,7,4,1,8,1};
	return 0; 
}

