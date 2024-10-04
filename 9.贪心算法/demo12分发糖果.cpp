#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	// 每个孩子至少分配到 1 个糖果。
	// 相邻两个孩子评分更高的孩子会获得更多的糖果。
	int candy(vector<int>& ratings) {
		int sum = 0;
		vector<int> candyVec(ratings.size(),1);
		// 右孩子比左孩子大
		for(int i = 0; i < ratings.size() - 1; i++)
		{
			if(ratings[i] < ratings[i+1])
				candyVec[i+1] = candyVec[i] + 1;
		}
		
		// 左孩子比右孩子大
		for(int i = ratings.size() - 1; i > 0; i--)
		{
			if(ratings[i-1] > ratings[i])
				candyVec[i-1] = max(candyVec[i-1], candyVec[i] + 1);
		}
		
		for(int num: candyVec)
			sum += num;
			
		return sum;
    }
};

int main()
{
	Solution solution;
	vector<int> score{1,2,2,5,4,3,2};
	vector<int> cost{3,4,5,1,2};
	int res = solution.candy(score);
	cout << "res: " << res << endl;
	return 0;
}