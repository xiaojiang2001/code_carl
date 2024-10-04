#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
		int cover = 0;
		if(nums.size() == 1)		 // 只有一个元素，就是能达到
			return true;
		for(int i = 0; i <= cover; i++)			// 注意这里是小于等于cover
		{
			cover = max(i + nums[i], cover);	// 得到最大的覆盖范围
			if(cover >= nums.size() - 1)			// 覆盖完所有
				return true;
		}
		return false;
    }
};


int main()
{
	Solution solution;
	vector<int> g{3,2,1,0,4};
	vector<int> s{1,1};
	bool res = solution.canJump(g);
	cout << "res: " << res << endl;
	return 0;
}