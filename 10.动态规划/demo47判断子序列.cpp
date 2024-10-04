#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
	bool isSubsequence(string s, string t) 
	{
		// s <= t
		// dp[i][j]：由下标 i-1 结束的s, j-1结束的t 相同子序列的长度为dp[i][j]
		// 类似于最长公共子序列
		vector<vector<int>> dp(s.size() + 1,vector<int>(t.size() + 1,0));
		for(int i = 1; i <= s.size(); i++)
		{
			for(int j = 1; j <= t.size(); j++)
			{
				if(s[i-1] == t[j-1])
					dp[i][j] = dp[i-1][j-1] + 1;
				else
					dp[i][j] = dp[i][j-1];
			}
		}
		
		for(int i = 0; i <= s.size(); i++)
		{
			for(int j = 0; j <= t.size(); j++)
			{
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		if(dp[s.size()][t.size()] == s.size())
			return true;
		else
			return false;
	}
};


int main()
{
	Solution s;
	string s1{"abc"};
	string t1{"ahbgdc"};
	bool ret = s.isSubsequence(s1,t1);
	cout << "\nret: " << ret;
	return 0;
}






