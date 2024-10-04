#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
	//动规
	int longestPalindromeSubseq(string s) 
	{
		// dp[i][j]：表示区间范围:[i,j]内的最长回文子序列长度为 dp[i][j]
		vector<vector<int>> dp(s.size(), vector<int>(s.size(),0));
		// s[i] == s[j]		dp[i][j] = dp[i+1][j-1] + 2 
		// s[i] != s[j]			
			// 加入s[i]		dp[i][j-1]	
			// 加入s[j]		dp[i+1][j]	
		// i 和 j 相等的情况下: dp[i][j] = 1
		for (int i = 0; i < s.size(); i++) 
			dp[i][i] = 1;
		
		for(int i = s.size() - 1; i >= 0; i--)
		{
			for(int j = i + 1; j < s.size(); j++)
			{
				if(s[i] == s[j])
					dp[i][j] = dp[i+1][j-1] + 2;
				else
					dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
			}
		}
		
		for(int i = 0; i < s.size(); i++)
		{
			for(int j = 0; j < s.size(); j++){
				cout << dp[i][j] << " ";
			}
			cout <<  endl;
		}
		
		return dp[0][s.size()-1];
	}
};

int main()
{
	Solution s;
	string s1{"cbbd"};
	string t1{"eat"};
	int ret = s.longestPalindromeSubseq(s1);
	cout << "\nret: " << ret;
	return 0;
}
