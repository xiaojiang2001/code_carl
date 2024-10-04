#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
	//本题是动规解决的经典题目
	//用二维数组记录两个字符串的所有比较情况
	int findLength(vector<int>& nums1, vector<int>& nums2) 
	{
		// dp[i][j]: 以 i-1 为结尾的nums1, 以 j -1 为结尾的nums2结尾的最长重复子数组的长度
		vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1));
		// 第一行 第一列无意义
		for(int i = 0; i < nums1.size(); i++)
			dp[i][0] = 0;
		for(int j = 0; j < nums2.size(); j++)
			dp[0][j] = 0;
		int result = 0;
		for(int i = 1; i <= nums1.size(); i++)
		{
			for (int j = 1; j <= nums2.size(); j++)
			{
				// 更新最长公共子数组长度
				if(nums1[i-1] == nums2[j-1])
					dp[i][j] = dp[i-1][j-1] + 1;
				// 记录dp[i][j]最大值
				if(dp[i][j] > result)
					result = dp[i][j];
			}
		}
		// 打印dp数组
		for(int i = 0; i <= nums1.size(); i++)
		{
			for(int j = 0; j <= nums2.size(); j++)
				cout << dp[i][j] << " ";
			cout << endl;
		}
		return result;
	}
};


int main()
{
	Solution s;
	vector<int> nums1{1,2,3,2,1};
	vector<int> nums2{3,2,1,4,6};
	int ret = s.findLength(nums1,nums2);
	cout <<"ret: " << ret;
	return 0;
}
