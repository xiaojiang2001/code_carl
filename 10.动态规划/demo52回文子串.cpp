#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
	//动规
	int countSubstrings(string s) 
	{
		// dp[i][j]：表示区间范围:[i,j]内的字符串是否为子串
		vector<vector<bool>> dp(s.size(), vector<bool>(s.size(),false));
		int result = 0;
		// s[i] == s[j]		
			//  i == j 		
			//相邻：i + 1 = j	dp[i][j] = true     result++
			// j - i > 1		if(dp[i+1][j-1]) 	dp[i][j] = true    result++
		// s[i] != s[j]			dp[i][j] = false;		
		for(int i = s.size() - 1; i >= 0; i--)
		{
			for(int j = i; j < s.size(); j++)
			{
				//相等
				if(s[i] == s[j])
				{
					//情况1 + 情况2
					if(j - i <= 1)
					{
						dp[i][j] = true;
						result++;
					}
					//情况3
					else
					{
						if(dp[i+1][j-1]) 	
						{
							dp[i][j] = true;
							result++;
						}
					}
						
				}
			}
		}
		return result;
	}
	
	int countSubstrings2(string s) 
	{
		int result = 0;
		for(int i = 0; i < s.size(); i++)
		{
			result += extened(s,i,i,s.size());
			result += extened(s,i,i+1,s.size());
		}
		return result;
	}
	
	int extened(string& s, int i, int j, int n)
	{
		int res = 0;
		while(i >= 0 && j < n && s[i] == s[j])
		{
			i--;
			j++;
			res++;
		}
		return res;
	}
};

int main()
{
	Solution s;
	string s1{"sea"};
	string t1{"eat"};
	int ret = s.countSubstrings2(s1);
	cout << "\nret: " << ret;
	return 0;
}
