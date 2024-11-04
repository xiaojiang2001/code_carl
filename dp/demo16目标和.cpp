#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

    
int findTargetSumWays(vector<int>& nums, int target) 
{
    // 设加+的和为 left, 加-的和为 right
    // 则有 left + right = sum    left - right =target
    // left = (sum + atrget) / 2
    int sum =  accumulate(nums.begin(), nums.end(), 0);
    if (abs(target) > sum)
        return 0;
    if ((sum + target) % 2)
        return 0;

    int bagWeigt = (sum + target) / 2;
    
    // dp[j] 表示装满大小为i的背包有 dp[j] 种方法
    vector<int> dp(bagWeigt + 1, 0); 
    dp[0] = 1;          // 带入场景 累加根基
    for (int i = 0; i < nums.size(); i++)           // 遍历物品
    {
        for (int j = bagWeigt; j >= nums[i]; j--)   // 遍历背包
        {
            dp[j] += dp[j-nums[i]];
        }
    }
    return dp[bagWeigt];
}

int main()
{
    vector<int> nums{1,1,1,1,1};
    int target = 3;
    int ret = findTargetSumWays(nums, target);
    return 0;
}