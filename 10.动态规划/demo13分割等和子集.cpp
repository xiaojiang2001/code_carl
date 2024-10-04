#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool canPartition(vector<int>& nums) 
	{
		int sum = 0;
		int target;
		for(int num: nums)
			sum += num;
		if(sum % 2 == 0)
			target = sum / 2;	// 计算背包重量
		else
			return false;
		
		vector<int> dp(10001, 0);
		for(int i = 0; i < nums.size(); i++)	// 遍历物品
		{
			for(int j = target; j >= nums[i]; j--)	// 遍历背包
			{
				dp[j] = max(dp[j], dp[j-nums[i]] + nums[i]);	
			}
		}
		
		if(dp[target] == target)
			return true;
		else
			return false;
	}
	
};

int main()
{
	Solution s;
	vector<int> nums{1,5,11,5};
	bool ret = s.canPartition(nums);
	cout << "ret: " << ret << endl;
	return 0;
}
