#include <iostream>
#include <vector>
using namespace std;


void showVector(vector<int> &vp)
{
	//创建对应的迭代器，遍历容器 
	for(vector<int>::iterator it = vp.begin(); it < vp.end();it++)
	{
		//*it 对应的是容器<>内的数据类型
		cout << *it  << " ";	
	}
	cout << endl;
}

void showDoubleVector(vector< vector<string> > &vp)
{
	//创建对应的迭代器，遍历容器 
	for(auto it = vp.begin(); it < vp.end();it++)
	{
		for(auto vit = it->begin(); vit < it->end(); vit++)
		{
			cout << *vit   << " ";	
		}
		cout << endl;	
	}
	cout << endl;
}

class Solution {
private:
	vector<vector<string>> res;
	vector<string> path;
	
	bool isPalindrome(string& s, int startIdx, int endIdx)
	{
		int i = startIdx;
		int j = endIdx;
		for(;i < j; i++,j--)
		{
			if(s[i] != s[j])
				return false;
		}
		return true;
	}
	
	void backtracking(string &s, int startIdx) 
	{
		if(startIdx >= s.size())
		{
			res.push_back(path);
			return;
		}
		for(int i = startIdx; i <= s.size(); i++)
		{
			// 是回文子串
			if(isPalindrome(s,startIdx,i))
			{
				// 获取[startIndex,i]在s中的回文子串
				string str = s.substr(startIdx, i - startIdx + 1);
				path.push_back(str);
			}
			else	 // 不是回文，跳过
				continue;
			
			// 寻找i+1为起始位置的子串
			backtracking(s, i+ 1);
			// 回溯过程，弹出本次已经添加的子串
			path.pop_back();
		}
		return;
	}
	
public:
	vector<vector<string>> partition(string s) 
	{
		backtracking(s,0);
		return res;
	}
};


int main()
{
	Solution s;
	vector<vector<string>> res;
	string data = {"aab"};
	res = s.partition(data);
	showDoubleVector(res);
	return 0;
}
