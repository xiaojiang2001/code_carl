#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int res = 0;
		int profit;
		for(int i = 1; i < prices.size(); i++)
		{	
			profit = prices[i] - prices[i-1];
			if(profit > 0)
				res += profit;
		}
		return res;
    }
};



int main()
{
	Solution solution;
	vector<int> nums{1,2,3,4,5};
	int res = solution.maxProfit(nums);
	cout << "res: " << res << endl;
	return 0;
}