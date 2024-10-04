#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
	int numDistinct(string s, string t)
	{
		// s >= t
		// dp[i][j]：由下标 i-1 结束的s, j-1结束的t 子序列出现的个数
		vector<vector<int>> dp(s.size() + 1,vector<int>(t.size() + 1));
		for(int i = 0; i <= s.size();i++)
			dp[i][0] = 1;
		for(int j = 1; j <= t.size();j++)
			dp[0][j] = 0;
		
		for(int i = 1; i <= s.size(); i++)
		{
			for(int j = 1; j <= t.size(); j++)
			{
				if(s[i-1] == t[j-1])
					dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
				else
					dp[i][j] = dp[i-1][j];
			}
		}
		
		for(int i = 0; i <= s.size(); i++)
		{    
			for(int j = 0; j <= t.size(); j++)
				cout << dp[i][j] << " ";
			cout << endl;
		}
		
		return dp[s.size()][t.size()];
	}
};


int main()
{
	Solution s;
	string s1{"baegg"};
	string t1{"bag"};
	int ret = s.numDistinct(s1,t1);
	cout << "\nret: " << ret;
	return 0;
}


