#include <bits/stdc++.h>

using namespace std;

// 能否装满
bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(),nums.end(), 0);
    // 和为奇数 装不满
    if(sum % 2 == 1)
        return false;

    int weight = sum / 2;       // 背包大小
    // dp[j]: 背包大小为j可以装的物品最大重量为dp[j] 
    vector<int> dp(weight+1, 0);       
    for (size_t i = 0; i < nums.size(); i++)    // 先遍历物品
    {
        for (size_t j = weight; j >= nums[i]; j--)    // 遍历背包
        {
            dp[j] = max(dp[j], dp[j-nums[i]] + nums[i]);
        }
    }
    // 装满
    if (dp[weight] == weight) {
        return true;
    }
    return false; 
}

int main()
{
    vector<int> vec{1,5,11,5};
    int res = canPartition(vec);
    cout << "res:" << res << endl;
    return 0;
}