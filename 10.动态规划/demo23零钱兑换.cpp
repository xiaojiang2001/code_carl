#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) 
	{
		// dp[i] :  可凑成总金额为 i 的最少硬币数 最终求dp[amount]
		vector<int> dp(amount + 1, INT_MAX);
		// 物品重量 coins[i]  物品价值 coins[i]
		// 背包大小 amount
		dp[0] = 0;
		// 遍历物品
		for(int  i = 0; i < coins.size(); i++)
		{
			// 遍历背包
			for(int j = coins[i]; j <= amount; j++)
			{	
				if(dp[j - coins[i]] != INT_MAX)
					dp[j] = min(dp[j - coins[i]]+1,dp[j]);
			}
		}
		for(int num:dp)
			cout << num << " ";
		if(dp[amount] == INT_MAX)
			return -1;
		return dp[amount];
	}
};

int main()
{
	Solution s;
	vector<int> nums{1, 2, 5};
	int ret = s.coinChange(nums,11);
	cout << "ret: " << ret;
	return 0; 

}

