#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int target)
	{
		// 分析
		/*
		left - right = target
		left + right = sum
		left = (sum + target) / 2;
		*/
		int sum = accumulate(nums.begin(), nums.end(),0);
		int left = (sum + target) / 2;
		if(abs(target) > sum)
			return 0;
		if((sum + target) % 2)
			return 0;
		// 问题转化为：装满 left 背包的方法有几种 
		// dp[j]: 装满容量为 j 的背包有 dp[j] 种方法
		// dp[j] += dp[j-nums[i]];	
		vector<int> dp(left + 1, 0);
		dp[0] = 1;
		for(int i = 0; i < nums.size(); i++)		// 遍历物品
		{ 
			for(int j = left; j >= nums[i]; j--)	// 遍历背包
			{
				dp[j] += dp[j-nums[i]];	
			}
		}
		return dp[left];
	}
};

int main()
{
	Solution s;
	vector<int> nums{1,1,1,1,1};
	int ret = s.findTargetSumWays(nums,3);
	cout << "ret: " << ret << endl;
	return 0;
}

