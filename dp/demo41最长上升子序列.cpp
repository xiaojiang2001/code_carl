#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lengthOfLIS(vector<int>& nums) 
{
    // dp[i] 形成的最长子序列长度
    vector<int> dp(nums.size(), 1);
    for (int  i = 1; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
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
    vector<int> nums{10,9,2,5,3,7,101,18};
    int ret = lengthOfLIS(nums);
    cout << "ret:" << ret << endl;
    return 0;
}