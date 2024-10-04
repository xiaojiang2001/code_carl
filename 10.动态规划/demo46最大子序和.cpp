#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
	int maxSubArray(vector<int>& nums) 
	{
		// dp[i]：考虑到下标 i 形成的最大子序列数组和
		// 延续前面的子序列：dp[i-1] + nums[i]
		// 不延续前面子序列：nums[i]
		vector<int> dp(nums.size());
		dp[0] = nums[0];
		int result = dp[0];
		for(int i = 1; i < nums.size(); i++)
		{
			dp[i] = max(dp[i-1] + nums[i], nums[i]);
			if(dp[i] > result)
				result = dp[i];	
		}
		for(int num : dp)
			cout << num << " ";
		return result;
	}
};


int main()
{
	Solution s;
	vector<int> nums1{-2,1,-3,4,-1,2,1,-5,4};
	vector<int> nums2{1,9,2,5,1};
	int ret = s.maxSubArray(nums1);
	cout << "\nret: " << ret;
	return 0;
}




int maxSubArray2(vector<int>& nums)
{
	//dp[i]: 包括下标在内的 i 最大的子序列和
	vector<int> dp(nums.size(),0);
	dp[0] = nums[0];
	for(int i = 1; i < nums.size(); i++)
	{
		dp[i] = max(dp[i-1] +nums[i], nums[i]);
	}
	return *max_element(dp.begin(),dp.end());
}




















