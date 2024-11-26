#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxSubArray(vector<int>& nums) 
{
    int res = INT_MIN;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        // 记录最大
        if (sum > res)
            res = sum;
        // 贪心 累加到负数就放弃
        if(sum < 0)
            sum = 0;
    }
    return res;
}

int main()
{
    vector<int> nums{5,4,-1,7,8};
    int res = maxSubArray(nums);
    cout << "res: " << res << endl;
    return 0;
}