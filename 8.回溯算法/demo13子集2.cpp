#include <iostream>
#include <vector>
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

	void backtracking(vector<int>& nums, int startIdx, vector<bool>& used)
	{
		res.push_back(path);
		
		//终止条件 剩余集合为空
		if(startIdx >= nums.size())		// 到叶子节点
		{
			return;
		}
		
		//单层递归逻辑
		for(int i = startIdx; i < nums.size(); i++)
		{
			if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false)
				continue;
			path.push_back(nums[i]);
			used[i] = true;
			backtracking(nums, i+1, used);	//递归
			path.pop_back();			//回溯
			used[i] = false;
		}
		return;
	}
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) 
	{
		vector<bool> used(nums.size(), false);
		// 首先把给nums排序，让其相同的元素都挨在一起。
		sort(nums.begin(),nums.end());
		backtracking(nums, 0, used);
		return res;
    }
};


int main()
{
	cout << "hello world C++" << endl;
	Solution s;
	vector< vector<int> >res;
	vector<int> src{1,2,2};
	res = s.subsetsWithDup(src);
	showDoubleVector(res);
	return 0;
}

