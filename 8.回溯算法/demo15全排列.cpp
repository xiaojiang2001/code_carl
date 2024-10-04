#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
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

void showDoubleVector(vector< vector<int> > &vp)
{
	//创建对应的迭代器，遍历容器 
	for(vector< vector<int> >::iterator it = vp.begin(); it < vp.end();it++)
	{
		for(vector<int>::iterator vit = it->begin(); vit < it->end(); vit++)
		{
			cout << *vit  << " ";	
		}
		cout << endl;	
	}
	cout << endl;
}


/**************************算法****************************/
class Solution {
private:
	vector< vector<int> >res;
	vector<int>path;
	void backtracking(vector<int>& nums, vector<bool> used)
	{
		//终止条件 收集结果
		if(path.size() == nums.size())	
		{
			res.push_back(path);
			return;
		}
		//单层递归逻辑
		for(int i = 0; i < nums.size(); i++)
		{
			if(used[i] == true)			//path里已经收录的元素，直接跳过
				continue;
			used[i] = true;
			path.push_back(nums[i]);
			backtracking(nums, used);	//递归
			path.pop_back();			//回溯
			used[i] = false;
		}
		return;
	}
public:
	vector<vector<int>> permute(vector<int>& nums) 
	{
		vector<bool> used(nums.size(), false);
		backtracking(nums, used);
		return res;
	}
};

int main()
{
	cout << "hello world C++" << endl;
	Solution s;
	vector< vector<int> >res;
	vector<int> src{1,2,3};
	res = s.permute(src);
	showDoubleVector(res);
	return 0;
}

