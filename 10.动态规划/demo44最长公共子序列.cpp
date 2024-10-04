#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
	//用二维数组记录两个字符串的所有比较情况
	int longestCommonSubsequence(string text1, string text2) 
	{
		// dp[i][j]: 以 i-1 为结尾的 text1, 以 j -1 为结尾的 text2 结尾的最长重复子数组的长度
		// 长度为[0, i - 1]的字符串text1与长度为[0, j - 1]的字符串text2的最长公共子序列为dp[i][j]
		vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
		// 第一行 第一列无意义 初始化全为 0
		int result = 0;
		for(int i = 1; i <= text1.size(); i++)
		{
			for (int j = 1; j <= text2.size(); j++)
			{
				// 元素相同
				if(text1[i-1] == text2[j-1])
					dp[i][j] = dp[i-1][j-1] + 1;
				// 元素不相同
				// dp[i][j-1]：abc 和 考虑ac不考虑e
				// dp[i-1][j]：考虑ab不考虑c 和 ace
				else
					dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
				
				if(dp[i][j] > result)
					result = dp[i][j];
			}
		}
//		for(int i = 0; i <= text1.size(); i++)
//		{
//			for(int j = 0; j <= text2.size(); j++)
//			{
//				cout << dp[i][j] << " ";
//			}
//			cout << endl;
//		}
		return result;
	}
};


int main()
{
	Solution s;
	return 0;
}
