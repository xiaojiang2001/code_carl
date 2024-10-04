#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		int i,j;
		//通过容器定义一个二维数组 
		vector< vector<int> > data(n, vector<int>(n, 0)); 
		int num = 1;		//填空的数 
		int circle = 0;		//螺旋圈数 
		//循环不变量 左闭右开 
		while(num < n*n)
		{
			//填充上行 从左到右
			for(i = circle; i < n-circle-1; i++)
				data[circle][i] = num++;
			
			//填充右列 从上到下
			for(i = circle; i < n-circle-1; i++)
				data[i][n-circle-1] = num++;
			
			//填充下列 从右到左 
			for(i = n-circle-1; i > circle; i--)
				data[n-circle-1][i] = num++;
			
			//填充左列 从下到上 
			for(i = n-circle-1; i > circle;i--)
				data[i][circle] = num++;
			
			circle++;
		}
		if(n%2==1)
			data[n/2][n/2] = n*n;
		
		return data;
	}
};


int main()
{
	Solution s;
	vector<vector<int>> ret;
	int n = 3;
	ret = s.generateMatrix(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
} 
