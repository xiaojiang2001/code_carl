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

void showDoubleVector(vector< vector<char> > &vp)
{
	//创建对应的迭代器，遍历容器 
	for(auto it = vp.begin(); it < vp.end();it++)
	{
		for(auto vit = it->begin(); vit < it->end(); vit++)
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
	bool isValid(vector<vector<char>>& board, int row, int col, char val)
	{
		//检查行
		for(int i = 0; i < 9; i++)
		{
			if(board[row][i] == val)
				return false;
		}
		//检查列
		for(int i = 0; i < 9; i++)
		{
			if(board[i][col] == val)
				return false;
		}
		//检查内部
		int startRow = (row / 3) * 3;
		int startCol = (col / 3) * 3;
		for(int i = startRow; i < startRow + 3; i++)
		{
			for(int j = startCol; j < startCol + 3; j++)
			{
				if(board[i][j] == val)
					return false;
			}
		}
		return true;
	}
	bool backtracking(vector<vector<char>>& board)
	{
		//单层递归逻辑
		for(int i = 0; i < board.size(); i++)
		{
			for(int j = 0; j < board[0].size(); j++)
			{
				if(board[i][j] == '.')				//空格
				{
					for(char k = '1'; k <= '9'; k++)
					{
						if(isValid(board,i,j,k))	// 判断空格i,j上是否适合放k
						{
							board[i][j] = k;
							if(backtracking(board))	
								return true;		// 可以放k
							board[i][j] = '.';
						}
					}
					return false;					// 9个数都遍历完了 都行不
				}			
			}
		}
		return true;
	}
public:
	void solveSudoku(vector<vector<char>>& board) {
		backtracking(board);
    }
};

int main()
{
	cout << "solveSudoku" << endl;
	Solution s;
	vector< vector<int> >res;
	vector<int> src{1,1,2};
	vector<vector<char>> board{
		{'.','4','.','.','.','3','.','.','1'},
		{'3','.','.','5','.','.','.','9','.'},
		{'.','.','6','.','7','.','.','.','.'},
		{'.','2','.','.','8','4','.','.','.'},
		{'.','.','.','.','6','.','.','4','.'},
		{'.','.','7','.','.','.','.','5','.'},
		{'2','.','.','6','.','.','9','.','.'},
		{'.','.','.','.','.','.','4','.','2'},
		{'9','.','5','1','.','.','.','.','.'},
	};
	s.solveSudoku(board);
	showDoubleVector(board);
	return 0;
}

