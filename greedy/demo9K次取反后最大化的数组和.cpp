#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace  std;

static bool cmp(int a, int b)
{
    if (abs(a) != abs(b))
        return abs(a) > abs(b);
    return a >= b;
}

int largestSumAfterKNegations(vector<int>& nums, int k) 
{
    // 从绝对值大的排序
    sort(nums.begin(), nums.end(), cmp);
    int res = 0;
    int len = nums.size();
    for (int i = 0; i < len; i++)
    {
        if(k > 0 && nums[i] < 0) {
            nums[i] = -nums[i];
            k--;
        }
    }
    // 处理最后还剩余的 k
    if(k > 0 && k % 2 == 1)
        nums[len - 1] = nums[len - 1] * -1;

    return accumulate(nums.begin(), nums.end(), 0);
}

int main()
{
    vector<int> nums {2,-3,-1,5,-4};
    int k = 2;
    int res = largestSumAfterKNegations(nums, k);
    cout << res << endl;
}
