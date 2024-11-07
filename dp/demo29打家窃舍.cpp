#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums) 
{
    if (nums.size() == 1)
        return nums[0];    
    // dp[i] 表示截止到下标i所能偷的最大值 2,7,9,3,1
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++)
    {
        // 不偷当前一个 dp[i-1]
        // 偷当前一个 dp[i-2] + nums[i];
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }
    return dp[nums.size() - 1];
}

int main()
{
    vector<int> nums{2,7,9,3,1};
    int ret = rob(nums);
    cout << ret << endl;
}