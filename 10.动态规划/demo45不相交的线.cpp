#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
	int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) 
	{
		// dp[i][j]: 以 i-1 为结尾的 nums1, 以 j -1 为结尾的 nums2 的最大连线数
		vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
		// 第一行 第一列无意义 初始化全为 0
		int result = 0;
		for(int i = 1; i <= nums1.size(); i++)
		{
			for (int j = 1; j <= nums2.size(); j++)
			{
				// 元素相同
				if(nums1[i-1] == nums2[j-1])
					dp[i][j] = dp[i-1][j-1] + 1;
				// 元素不相同
				else
					dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
				
				if(dp[i][j] > result)
					result = dp[i][j];
			}
		}
		for(int i = 0; i <= nums1.size(); i++)
		{
			for(int j = 0; j <= nums2.size(); j++)
			{
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		return result;
	}
};


int main()
{
	Solution s;
	vector<int> nums1{1,3,7,1,7,5};
	vector<int> nums2{1,9,2,5,1};
	int ret = s.maxUncrossedLines(nums1, nums2);
	cout << "\nret: " << ret;
	return 0;
}
