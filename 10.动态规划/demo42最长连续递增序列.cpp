#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
// 动规
	int findLengthOfLCIS(vector<int>& nums) 
	{
		//1,3,5,4,7
		//1 2 3 1 2  	
		//dp[i]: 表示考虑下标 i 可形成的最长连续递增子序列长度
		vector<int> dp(nums.size(),1);
		dp[0] = 1;
		for(int i = 1; i < nums.size();i++)
		{
			// 连续递增
			if(nums[i] > nums[i-1])   
				dp[i] = dp[i-1] + 1;
		}
		return *max_element(dp.begin(),dp.end());
	}
};


int main()
{
	Solution s;
	vector<int> nums{1,3,6,7,9,4,10,5,6};
	int ret = s.findLengthOfLCIS(nums);
	cout <<"ret: " << ret;
	return 0;
}
