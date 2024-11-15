#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findLengthOfLCIS(vector<int>& nums) 
{
    // dp[i] 形成的最长子序列长度 默认全为1
    vector<int> dp(nums.size(), 1);
    for (int  i = 1; i < nums.size(); i++)
    {

        if (nums[i] > nums[i-1])
            dp[i] = dp[i-1] + 1;
    }
    return *max_element(dp.begin(), dp.end());
}

int main()
{
    vector<int> nums{1,3,5,4,7};
    int ret = findLengthOfLCIS(nums);
    cout << "ret:" << ret << endl;
    return 0;
}