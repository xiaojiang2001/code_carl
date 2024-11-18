#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findLength(vector<int>& nums1, vector<int>& nums2) {
    // nums1为主数组 nums2为次级的比较数组
    // dp[i][j]: 当nums1以i为下标，nums2以j为下标形成的最长重复子数组长度
    // vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size()));

    // dp[i][j]: 当nums1以 i-1 为下标，nums2以 j-1 为下标形成的最长重复子数组长度
    vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1));
    int res = 0;

    // 遍历两个数组
    for (int i = 1; i <= nums1.size(); i++)
    {
        for (int j = 1; j <= nums2.size(); j++)
        {
            if (nums1[i-1] == nums2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;

            // 记录最大值
            if (dp[i][j] > res)
                res = dp[i][j]; 
        }   
    }

    // 打印dp数组
    for (int i = 0; i <= nums1.size(); i++) {
        for (int j = 0; j <= nums2.size(); j++) {
            cout << dp[i][j] << " ";
        }   
        cout << endl;
    }
    cout << endl;
    return res;
}

int main()
{
    vector<int> nums1{1,2,3,2,1};
    vector<int> nums2{3,2,1,4,7};
    int ret = findLength(nums1, nums2);
    cout << "ret: " << ret << endl;
    return 0;
}