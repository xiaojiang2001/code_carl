#include <iostream>
#include <vector>
#include <climits>

using namespace std;


int combinationSum4(vector<int>& nums, int target) 
{
    // 组合和为i的组合个数(排列数)为 dp[i]
    vector<int>dp(target+1);
    dp[0] = 1;  // 累加根基

    for (int j = 0; j <= target; j++)           // 遍历背包
    {
        for (int i = 0; i < nums.size(); i++)   // 遍历物品
        {
            // 数组下标的有效性 且 保证两个数相加不超过INT_MAX
            if (j-nums[i] >= 0 && dp[j] < INT_MAX - dp[j - nums[i]])
            {
                dp[j] += dp[j - nums[i]];
            }
        }            
    }

    return dp[target];
}


int main()
{
    vector<int> nums {1, 2, 3};
    int target = 4;
    int ret = combinationSum4(nums, target);
    cout << ret << endl;
}
