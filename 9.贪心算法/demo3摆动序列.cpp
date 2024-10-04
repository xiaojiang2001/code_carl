#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
    	int res = 1;			// 最长子序列 默认最右边有坡度
    	int prediff = 0;		// 保存上一轮结果正负
    	int curdiff = 0;		// 暂存当前结果正负
    	bool flag = false;	
    	// 1个
		if(nums.size() == 1)
			return 1;
		for(int i = 0; i < nums.size() - 1; i++)	//去掉最后一个 默认有波动
		{
			curdiff = nums[i+1] - nums[i];
			//波动
			if(prediff >= 0 && curdiff < 0 || prediff <= 0 && curdiff > 0)
			{
				res++;
				prediff = curdiff;
			}
		}
		return res;
	}
};



int main()
{
	Solution solution;
	vector<int> nums{1,2,3,4,5,6,7,8,9,9};
	int res = solution.wiggleMaxLength(nums);
	cout << "res: " << res << endl;
	return 0;
}