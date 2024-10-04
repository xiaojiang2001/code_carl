#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) 
	{
		if(cost.size() <= 1)
			return 0;
		int size = cost.size();
		vector<int> dp(size + 1);		// 到达第 i 层的最小花费
		// 需要跳才需要花费
		dp[0] = 0;
		dp[1] = 0;
		for(int i = 2; i <= size; i++)
			dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
		
		for(int num : dp)
			cout << num << " ";
		cout << endl;
		
		return dp[size];
	}
};

int main()
{
	Solution s;
	vector<int> cost{1,100};
	int ret;
	ret = s.minCostClimbingStairs(cost);
	cout << "ret: " << ret << endl;
	return 0;
}
