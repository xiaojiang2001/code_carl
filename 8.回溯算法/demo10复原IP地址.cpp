#include <iostream>
#include <vector>
using namespace std;


void showVector(vector<string> &vp)
{
	//创建对应的迭代器，遍历容器 
	for(auto it = vp.begin(); it < vp.end();it++)
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
	vector<string> res;
	
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
	// 左闭右闭 判断数字是否合法
	bool isValid(string& s, int startIdx, int endIdx)	
	{
		if(startIdx > endIdx)
			return false;
		if(s[startIdx] == '0' && startIdx != endIdx)
			return false;
		
		int sum = 0;
		for(int i = startIdx; i <= endIdx; i++)
		{
			if(s[i] < '0' || s[i] > '9')
				return false;
		
			sum = sum * 10 + (s[i] - '0');
				if(sum > 255)
					return false;
		}	
		return true;
	}
	
	void backtracking(string &s, int startIdx, int pointSum) 
	{
		if(pointSum == 3)
		{
			if(isValid(s,startIdx,s.size()-1))			//判断最后一个数字知否为合法IP
			{
				res.push_back(s);
				return;
			}
		}
		
		for(int i = startIdx; i <= s.size(); i++)
		{
			// 是合法的IP地址
			if(isValid(s,startIdx,i))
			{
				s.insert(s.begin()+i+1,'.');
				pointSum++;
			}
			else	 // 跳过
				continue;
			
			// 递归
			backtracking(s, i + 2, pointSum);
			//回溯
			s.erase(s.begin()+i+1);
			pointSum--;
		}
		return;
	}
	
public:
	vector<string> restoreIpAddresses(string s) 
	{
		backtracking(s,0,0);
		return res;
	}
};

int main()
{
	Solution s;
	vector<string> res;
	string data = {"25525511113"};
	res = s.restoreIpAddresses(data);
	showVector(res);
	return 0;
}
