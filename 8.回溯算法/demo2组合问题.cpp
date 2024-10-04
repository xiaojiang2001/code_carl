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
	vector< vector<int> > res;
	vector<int> path;

	void backtracking(int n, int k, int startIdx)
	{
		//终止条件
		if(path.size() == k)		//找到一个大小为k的组合
		{
			res.push_back(path);	//path加入结果数组中 收割结果
			return;
		}
		//单层递归逻辑
		for(int i = startIdx; i <= n; i++)
		{
			if(path.size() < k)			//数据加入组合
				path.push_back(i);
			backtracking(n, k, i+1);	//递归
			path.pop_back();			//回溯
		}
		return;
	}

    vector< vector<int> > combine(int n, int k) {
		backtracking(n, k, 1);
		return res;
    }
};


int main()
{
	//cout << "hello world C++" << endl;
	Solution s;
	vector< vector<int> >res;
	res = s.combine(4,2);
	showDoubleVector(res);
	return 0;
}

