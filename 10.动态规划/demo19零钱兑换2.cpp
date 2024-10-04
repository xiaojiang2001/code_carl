#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int change(int amount, vector<int>& coins) 
	{
		// dp[i] :  可凑成总金额为 i 的组合有 dp[i] 种 最终求dp[amount]
		vector<int> dp(amount + 1, 0);
		// 物品重量 coins[i]  物品价值 coins[i]
		// 背包大小 amount
		dp[0] = 1;
		// 遍历物品
		for(int  i = 0; i < coins.size(); i++)
		{
			// 遍历背包 组合问题
			for(int j = coins[i]; j <= amount; j++){
				dp[j] += dp[j - coins[i]];
			}
		}
		return dp[amount];
	}
};

int main()
{
	Solution s;
	vector<int> nums{1, 2, 5};
	int ret = s.change(5,nums);
	cout << "ret: " << ret;
	return 0; 
}

