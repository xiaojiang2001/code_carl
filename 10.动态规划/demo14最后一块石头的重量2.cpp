#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lastStoneWeightII(vector<int>& stones) 
	{
		int sum = 0;
		int target = 0;
		for(int num:stones)
			sum += num;
		target = sum / 2;
		
		vector<int> dp(1501, 0);
		for(int i = 0; i < stones.size(); i++)			// 遍历物品
		{ 
			for(int j = target; j >= stones[i]; j--)	// 遍历背包
			{
				dp[j] = max(dp[j], dp[j-stones[i]] + stones[i]);	
			}
		}
		// 一堆石头 dp[target] 另一堆 sum - dp[target] 
		return  sum - dp[target] - dp[target];
	}
};

int main()
{
	Solution s;
	vector<int> nums{2,7,4,1,8,1};
	int ret = s.lastStoneWeightII(nums);
	cout << "ret: " << ret << endl;
	return 0;
}

