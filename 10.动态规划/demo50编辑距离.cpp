#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
	// 动规
	int minDistance(string word1, string word2)
	{
		// dp[i][j]：由下标 i-1 结束的word1, j-1结束的word2 最少的操作次数为dp[i][j]
		vector<vector<int>> dp(word1.size() + 1,vector<int>(word2.size() + 1, 0));
		for(int i = 0; i <= word1.size();i++)
			dp[i][0] = i;
		for(int j = 0; j <= word2.size();j++)
			dp[0][j] = j;
		
		for(int i = 1; i <= word1.size(); i++)
		{
			for(int j = 1; j <= word2.size(); j++)
			{
				if(word1[i-1] == word2[j-1])
					dp[i][j] = dp[i-1][j-1];
				else
				{
				//删除word1[i-1]:	dp[i-1][j] + 1    
				//删除word2[j-1]:	dp[i][j-1] + 1    
				// 替换 dp[i-1][j-1] + 1 	
					dp[i][j] = min(dp[i-1][j] + 1,min(dp[i][j-1] + 1, dp[i-1][j-1] + 1 ));
				}
			}
		}
		
		for(int i = 0; i <= word1.size(); i++)
		{    
			for(int j = 0; j <= word2.size(); j++)
			{
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		
		return dp[word1.size()][word2.size()];
	}
};

int main()
{
	Solution s;
	string s1{"sea"};
	string t1{"eat"};
	int ret = s.minDistance(s1,t1);
	cout << "\nret: " << ret;
	return 0;
}
