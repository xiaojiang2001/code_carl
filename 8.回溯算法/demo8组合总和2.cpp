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

class Solution {
public:
	vector<vector<int>> res;
	vector<int> path;

	// 去重逻辑是关键
	void backtracking(vector<int>& candidates, int target, int sum, int startIdx, vector<bool>& used) 
	{
		if(sum > target)
			return;
		if(target == sum)
		{
			res.push_back(path);
			return;
		}
		for(int i = startIdx; i < candidates.size(); i++)
		{
			//和前一个元素相同 且前面那个元素没有用过
			// used[i - 1] == true， 说明同一树枝candidates[i - 1]使用过
			// used[i - 1] == false，说明同一树层candidates[i - 1]使用过
			// 要对同一树层使用过的元素进行跳过
			if(i > 0 && candidates[i] == candidates[i-1] && used[i-1] == false)
				continue;
			sum += candidates[i];
			path.push_back(candidates[i]);
			used[i] = true;
			backtracking(candidates, target, sum, i+1,used);
			sum -= candidates[i];
			path.pop_back();
			used[i] = false;
		}
		return;
	}
	
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
	{
		vector<bool> used(candidates.size(), false);
		 // 首先把给candidates排序，让其相同的元素都挨在一起。
		sort(candidates.begin(),candidates.end());
		backtracking(candidates,target,0,0,used);
		return res;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> res;
	vector<int> data = {2,2,5,6,7};
	res = s.combinationSum2(data,15);
	showDoubleVector(res);

	return 0;
}
