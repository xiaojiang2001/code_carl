#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
		if(nums.size() == 1)
			return 0;
		int res = 0;		// 结果：跳跃次数
		int cur = 0;		// 当前覆盖范围
		int next = 0;		// 下一步覆盖范围
		for(int i = 0; i < nums.size(); i++)
		{
			next = max(next, i + nums[i]);		    // 更新下一步覆盖最远距离下标
			if(i == cur)						    // 遇到当前覆盖最远距离下标
			{
				if(cur != nums.size()-1)		    // 如果还未到终点
				{
					res++;                          // 需要走下一步
					cur = next;                     // 更新当前覆盖最远距离下标（相当于加油了）
					if(next >= nums.size() - 1)	    // 当前覆盖最远距到达集合终点，不用做res++操作了，直接结束
						break;
				}
			}
		}
		return res;
    }
};

int main()
{
	Solution solution;
	vector<int> g{2,3,1,1,4};
	vector<int> s{1,1};
	int res = solution.jump(g);
	cout << "res: " << res << endl;
	return 0;
}