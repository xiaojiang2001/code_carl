#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	
	//移动匹配
	bool repeatedSubstringPattern(string s) 
	{
		//拼接字符串 s + s
		string t = s + s;
		// 移除首尾
		t.erase(t.begin());
		t.erase(t.end() - 1);
		//判断拼接后的字符串中有无s
		if(t.find(s) != string::npos)
			return true;
		else
			return false;
	}
	
	
	// KMP算法
	void get_next(string& s, vector<int>& next)
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
	
	bool repeatedSubstringPattern2(string s) 
	{
		if(s.size() == 0){
			return 0;
		}
		
		vector<int> next(s.size());
		get_next(s,next);
		
//		for(int num: next)
//			cout << num << " ";
//		cout << endl;
		
		int len = s.size();
		if(next[len - 1] != 0 && len % (len - next[len - 1]) == 0)
			return true;
		else
			return false;
	}
};


int main()
{
	Solution s;
	string str = {"asdfasdfasdf"};
	bool ret = s.repeatedSubstringPattern2(str);
	cout << ret << endl;
}
