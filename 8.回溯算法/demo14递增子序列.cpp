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
	// 4 6 7 7
	void backtracking(vector<int>& nums, int startIdx)
	{
		if(path.size() > 1)
			res.push_back(path);
		
		//终止条件 剩余集合为空
		if(startIdx >= nums.size())		// 到叶子节点
		{
			return;
		}
		
		//单层递归逻辑
		unordered_set<int> uset; 		// 使用set对本层元素进行去重
		for(int i = startIdx; i < nums.size(); i++)
		{
			if(!path.empty() && nums[i] < path.back() || uset.find(nums[i])  != uset.end())
				continue;
			uset.insert(nums[i]);
			path.push_back(nums[i]);
			backtracking(nums, i+1);	//递归
			path.pop_back();			//回溯
		}
		return;
	}
public:
	vector<vector<int>> findSubsequences(vector<int>& nums) 
	{
		backtracking(nums, 0);
		return res;
    }
};


int main()
{
	cout << "hello world C++" << endl;
	Solution s;
	vector< vector<int> >res;
	vector<int> src{4,7,6,7};
	res = s.findSubsequences(src);
	showDoubleVector(res);
	return 0;
}

