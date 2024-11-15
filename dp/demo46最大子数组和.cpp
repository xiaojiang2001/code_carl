#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int>& nums) 
{
    // 考虑dp[i] 形成的最大子数组和
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    for (int  i = 1; i < nums.size(); i++)
    {
        if(dp[i-1] > 0)
            dp[i] = dp[i-1] + nums[i];
        else
            dp[i] = nums[i];
    }

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;

    return *max_element(dp.begin(), dp.end());
}

int main()
{
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    int ret = maxSubArray(nums);
    cout << "ret:" << ret << endl;
    return 0;
}