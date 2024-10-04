#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	
	void build_next(string &s, vector<int> &next)
	{
		int i;		// 后缀末尾位置
		int j;   	// 前缀末尾位置
		
		//1. 初始化
		j = 0;
		next[0] = 0;
		
		for(int i = 1; i < s.size(); i++)
		{
			//2. 处理前后缀不对称的情况
			while(j > 0 && s[j] != s[i]){
				j = next[j-1];
			}
			
			//3. 处理前后缀对称的情况
			if(s[j] == s[i])
				j++;
			
			// 4.更新next数组
			next[i] = j;
		}
	}
	
	
	int strStr(string haystack, string needle) 
	{
		if(needle.size() == 0){
			return 0;
		}
		
		vector<int> next(needle.size());
		build_next(needle, next);
		
		// 因为next数组里记录的起始位置为0
		int j = 0;
		// 注意i就从0开始
		for(int i = 0; i < haystack.size(); i++)
		{
			// 不匹配
			while(j > 0 && haystack[i] != needle[j])
				j = next[j-1];		// j 寻找之前匹配的位置
			// 匹配，j和i同时向后移动
			if(haystack[i] == needle[j])
				j++;	// i的增加在for循环里
			
			// 文本串s里出现了模式串t
			if(j == needle.size())
				return i - needle.size() + 1;
		}
		return -1;
	}
};


int main()
{
	Solution s;
	string haystack = {"sadbutsad"};
	string needle = {"but"};
	int ret = s.strStr(haystack, needle);
	cout << ret << endl;
}
