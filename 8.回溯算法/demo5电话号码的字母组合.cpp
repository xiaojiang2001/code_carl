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


class Solution {
public:
	vector<string> res;
	string path;
	string map[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	
	void backtracking(string digits, int idx)	// idx 记录当前递归在哪个数字
	{
		if(idx == digits.size())				// 遍历结束
		{
			res.push_back(path);
			return;
		}
		
		int dgit = digits[idx] - '0';		// 获取数字
		string letter = map[dgit];			// 获取数字对应的字符串
		for(int i = 0; i < letter.size(); i++)
		{
			path.push_back(letter[i]);
			backtracking(digits, idx + 1);
			// 回溯
			path.pop_back();
		}
		return;
	}
	
	vector<string> letterCombinations(string digits) 
	{
		if(digits.size() == 0)
			return res;
		backtracking(digits,0);
		return res;
	}
};



int main()
{
	Solution s;
	vector<string> res;
	res = s.letterCombinations("23");
	showVector(res);
	return 0;
}
