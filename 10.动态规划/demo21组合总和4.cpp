#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) 
	{
		// dp[i] :  组成目标数 i 的组合有 dp[i] 个
		vector<int> dp(target + 1, 0);
		// 物品重量 nums[i]  物品价值 nums[i] 
		// 背包大小 target
		dp[0] = 1;
		// 遍历背包
		for(int j = 0; j <= target; j++)
		{
			// 遍历物品
			for(int  i = 0; i < nums.size(); i++)
			{
				if(j - nums[i] >= 0)
					dp[j] += dp[j - nums[i]];
			}
		}
		return dp[target];
	}
};

int main()
{
	Solution s;
	vector<int> nums{1, 2, 3};
	int ret = s.combinationSum4(nums,4);
	cout << "ret: " << ret;
	return 0; 
}

