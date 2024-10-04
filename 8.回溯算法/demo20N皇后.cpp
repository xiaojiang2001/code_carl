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
	vector< vector<string> >res;
	
	bool isValid(vector<string>& chessboard, int n, int row, int col)
	{
		//检查列
		for(int i = 0; i < row; i++)
		{
			if(chessboard[i][col] == 'Q')
				return false;
		}
		//检查45° 右上角
		for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
		{
			if(chessboard[i][j] == 'Q')
				return false;
		}
		//检查135° 左上角
		for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
		{
			if(chessboard[i][j] == 'Q')
				return false;
		}
		return true;
	}
		
	void backtracking(vector<string>& chessboard, int n, int row)
	{
		//到叶子节点
		if(row == n)	
		{
			res.push_back(chessboard);			// 收集结果 走到叶子 一定合法
			return;
		}
		//单层递归逻辑
		for(int i = 0; i < n; i++)
		{
			if(isValid(chessboard, n, row, i))
			{
				chessboard[row][i] = 'Q';				// 放皇后
				backtracking(chessboard, n, row + 1);	// 递归遍历下一行
				chessboard[row][i] = '.';				// 回溯
			}
		}
		return;
	}
public:
	vector<vector<string>> solveNQueens(int n) 
	{
		vector<string> chessboard(n, string(n, '.'));
		backtracking(chessboard, n, 0);
		return res;
	}
};

int main()
{
	cout << "hello world C++" << endl;
	Solution s;
	vector< vector<int> >res;
	vector<int> src{1,1,2};
	//res = s.permuteUnique(src);
	//showDoubleVector(res);
	return 0;
}

