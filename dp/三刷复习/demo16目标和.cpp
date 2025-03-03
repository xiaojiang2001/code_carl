#include <bits/stdc++.h>

using namespace std;

// 计算装满背包有几种方法，组合问题
int findTargetSumWays(vector<int>& nums, int target) {
    int sum = accumulate(nums.begin(), nums.end() , 0);
    if(abs(target) > sum)   return 0;
    if((target + sum) % 2 == 1) return 0;

    int bagSize = (target + sum) / 2;
    // 装满target背包有dp[i]种方法 
    // 组合数
    vector<int> dp(bagSize+1,0); 
    dp[0] = 1;                  // 累加初值
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = bagSize; j >= nums[i]; j--)
        {
            dp[j] += dp[j-nums[i]];    
        }
    }
    return dp[bagSize];
}

int main()
{
    vector<int> nums{1,0};
    int target = 1;
    int ret = findTargetSumWays(nums, target);
    cout << ret << endl;
    return 0;
}