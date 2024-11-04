#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

//二维dp
/*
bool canPartition(vector<int>& nums) 
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2)
        return false;

    int bagWeight;
    bagWeight = sum / 2;
    // 遍历物品 重量 nums[i]    价值nums[i]
    // 背包大小 bagWeight 能否装满这个背包
    vector<vector<int>> dp(nums.size(), vector<int>(bagWeight+1,0));
    // 背包够大 放物品0
    for (int j = nums[0]; j <= bagWeight; j++) {
        dp[0][j] = nums[0];
    }

    for (int i = 1; i < nums.size(); i++)    // 遍历物品
    {
        for (int j = 1; j <= bagWeight; j++)
        {
            // 若当前背包重量j小于nums[i]，则其值等于只考虑0到i-1物品时的值
            if(j < nums[i])
                dp[i][j] = dp[i-1][j];
            // 否则，背包重量等于在背包中放入num[i]/不放入nums[i]的较大值
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-nums[i]] + nums[i]);
        }
    }
    if (dp[nums.size() -1][bagWeight] == bagWeight)
        return true;
    else   
        return false;
}
*/

//一维dp
bool canPartition(vector<int>& nums) 
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2)
        return false;
    int bagWeight;
    bagWeight = sum / 2;
    // 遍历物品 重量 nums[i]    价值nums[i]
    // 背包大小 bagWeight 能否装满这个背包
    vector<int> dp(bagWeight + 1, 0);

    // 遍历物品
    for (int i = 0; i < nums.size(); i++)
    {
        // 遍历背包
        for (int j = bagWeight; j >=  nums[i]; j--)
        {
            dp[j] = max(dp[j] , dp[j - nums[i]] + nums[i]);
        }      
    }
    if (dp[bagWeight] == bagWeight)
        return true;
    else
        return false;
}


int main()
{
    vector<int> nums{1,5,11,5};
    bool ret = canPartition(nums);
    cout << ret << endl;
}