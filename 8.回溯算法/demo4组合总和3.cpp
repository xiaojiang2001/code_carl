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


/**************************算法****************************/
class Solution {
public:
	vector< vector<int> >res;
	vector<int>path;
	int temp_sum;
	void backtracking(int k, int targetSum, int sum, int startIdx)
	{
		if(sum > targetSum)		// 减枝1 和过大
			return;		
		//终止条件
		if(path.size() == k)
		{
			if(targetSum == sum)
				res.push_back(path);
			return;
		}
		//单层递归逻辑
		for(int i = startIdx; i <= 9 - (k - path.size()) + 1; i++)	// 减枝2 个数限制
		{
			sum += i;
			path.push_back(i);
			backtracking(k, targetSum, sum, i+1);	//递归
			//回溯
			sum -= i;
			path.pop_back();						
		}
		return;
	}

    vector< vector<int> > combinationSum3(int k, int n) {
		backtracking(k,n,0,1);
		return res;
    }
};


int main()
{
	cout << "hello world C++" << endl;
	Solution s;
	vector< vector<int> >res;
	res = s.combinationSum3(3,7);
	showDoubleVector(res);
	return 0;
}

