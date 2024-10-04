#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) 
	{
		unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
		// dp[i] :  字符串长度为 i 能组成则为 true  结果dp[s.size()]
		vector<bool> dp(s.size() + 1, false);
		// 物品   wordDict  wordDict[i]
		// 背包 	s	
		// 物品能否把背包装满 物品可以重复使用  
		// 递推公式
		/*
		if((j,i) && dp[j]) // j-i是在字典单词 且dp[j] = true
			dp[i] = true;
		*/
		// 排列 先遍历背包
		dp[0] = true;		// 递推公式的基础
		for(int i = 1; i <= s.size() ; i++)
		{
			// 遍历物品
			for(int j = 0; j < i; j++)
			{
				// 起始位置   距离
				string word = s.substr(j, i-j);
				// i-j的单词在字典中
				if(wordSet.find(word) != wordSet.end() && dp[j] == true)
					dp[i] = true;	
			}
		}
		for(int i = 0; i < dp.size(); i++)
			cout << dp[i] << " ";
		return dp[s.size()];
	}
};

int main()
{
	Solution s;
	vector<int> nums{1, 2, 5};
	return 0; 
}

