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
	
	void backtracking(vector<int>& candidates, int target, int sum, int startIdx) 
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
			sum += candidates[i];
			path.push_back(candidates[i]);
			backtracking(candidates, target, sum, i);
			sum -= candidates[i];
			path.pop_back();
		}
		return;
	}
	
	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		backtracking(candidates,target,0,0);
		return res;
	}
};


int main()
{
	Solution s;
	vector<vector<int>> res;
	vector<int> data = {2,3,5,6,7};
	res = s.combinationSum(data,12);
	showDoubleVector(res);
	return 0;
}
