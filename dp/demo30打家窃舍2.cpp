#include <iostream>
#include <vector>

using namespace std;

// 计算子区间 [start, end] 的最大打家窃舍最大值
int subRob(vector<int>& nums, int start, int end)
{
    if (start > end)
        return -1;
    if (start == end)
        return nums[start];

    // dp[i] 表示截止到下标i所能偷的最大值 2,7,9,3,1
    vector<int> dp(nums.size());
    dp[start] = nums[start];
    dp[start + 1] = max(nums[start], nums[start + 1]);
    for (int i = start + 2; i <= end; i++)
    {
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }
    return max(dp[end], dp[end-1]);
} 

int rob(vector<int>& nums) 
{
    int len = nums.size();
    if (len <= 1)
        return nums[0];

    int left  = subRob(nums, 0, len - 2);   // [0, len-2] 取首 不取尾
    int right =  subRob(nums, 1, len - 1);  // [1, len-1] 取尾 不取首

    return max(left, right);
}




int main()
{
    vector<int> nums{1,2,3};
    int ret = rob(nums);
    cout << ret << endl;
    return 0;
}