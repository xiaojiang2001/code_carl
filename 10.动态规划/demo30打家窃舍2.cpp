#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) 
	{
		if(nums.size() == 1)
			return nums[0];
		// 最后一个数据的下标为 nums.size() - 1
		int ret1 = robRange(nums, 0, nums.size() - 2);
		int ret2 = robRange(nums, 1, nums.size() - 1);
		return max(ret1,ret2);
	}
	
	//计算一个区间上的打家窃舍的最大值
	int robRange(vector<int>& nums, int start, int end)
	{
		// dp[i] : 考虑包括下标 i 之前所偷的最大金币 dp[i];
		//（nums[i]不一定偷，只考虑到）
		// 结果：dp[end]
		// 偷i: dp[i-2] + nums[i]
		// 不偷i: dp[i-1]
		// dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
		//dp[start] = nums[start];
		//dp[start +1 ] = max(nums[start],nums[start+1]);
		if(start == end)
			return nums[start];
		vector<int> dp(nums.size(),0);
		dp[start] = nums[start];
		dp[start + 1] = max(nums[start], nums[start+1]);
		for(int i = start + 2; i <= end; i++)
			dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
		return dp[end];
	}
};

int main()
{
	Solution s;
	vector<int> nums{0,0};
	int ret = s.rob(nums);
	cout << "ret: " << ret;
	return 0; 
}

