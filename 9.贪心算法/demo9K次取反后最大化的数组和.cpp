#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;



class Solution {
static bool cmp(int a, int b)
{
	return abs(a) > abs(b);
}
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
    	int sum = 0;
		sort(nums.begin(), nums.end(),cmp);			//按绝对值从大到小排序
		// 把尽可能多的负数转为正数
		for(int i = 0; i < nums.size();i++)
		{
			if(nums[i] < 0 && k > 0)
			{
				nums[i] = nums[i] * -1;
				k--;
			}
		}
		
		if(k % 2)		// 若还需要转奇数次，把最小的数转一次
			nums[nums.size()- 1] = nums[nums.size()- 1] * -1;
			
		for(int num:nums)
			sum += num;
			
		return sum;
    }
};

int main()
{
	Solution solution;
	vector<int> g{-8,-7,-3,-9,1,9,-6,-9,3};
	vector<int> s{1,1};
	int res = solution.largestSumAfterKNegations(g,8);
	cout << "res: " << res << endl;
	return 0;
}