#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
	int lengthOfLIS(vector<int>& nums) 
	{
		// 10,9,2,5,3,7,101,18
		// 1  1 1 2 2 3  4   4
		//dp[i]: 表示考虑下标 i 可形成的最长递增子序列长度
		vector<int> dp(nums.size(),1);
		dp[0] = 1;
		for(int i = 1; i < nums.size();i++)
		{
			for(int j = 0; j < i; j++)
			{
				// 遍历0-i,在nums[j]小的的dp中取dp的max + 1
				if(nums[i] > nums[j])
					dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		// 求dp数组中的最大值
		return *max_element(dp.begin(),dp.end());
	}
};


int main()
{
	Solution s;
	vector<int> nums{1,3,5,4,7};
	int ret = s.lengthOfLIS(nums);
	cout <<"ret: " << ret;
	return 0;
}
