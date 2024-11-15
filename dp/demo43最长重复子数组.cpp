#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findLength(vector<int>& nums1, vector<int>& nums2) {
    // nums1为主数组 nums2为次级的比较数组
    vector<int> dp(nums1.size(), 0);
    // 初始化dp[0]
    if(find(nums2.begin(), nums2.end(), nums1[0]) != nums2.end())
        dp[0] = 1;

    for (int i = 1; i < nums1.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            // 连续了 j 一定 > 0 保证 j-1有效
            if (nums1[i] == nums2[j])
                dp[i] = dp[i-1] + 1;
            // 发现首个相等元素了
        }   
    }

    // 打印dp数组
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;
    return *max_element(dp.begin(), dp.end());
}

int main()
{
    vector<int> nums1{0,1,1,1,1};
    vector<int> nums2{1,0,1,0,1};
    int ret = findLength(nums1, nums2);
    cout << "ret: " << ret << endl;
    return 0;
}