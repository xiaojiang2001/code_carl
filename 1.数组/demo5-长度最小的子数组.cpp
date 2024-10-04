#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		//二刷
		//难点一：j是起始还是终止位置 j代表终止位置 
		//难点二：如何移动起始位置 i
		int i = 0;
		int j = 0;
		int minlen = nums.size();
		int len;
		int sum = 0;
		int total = 0;
		//滑动窗口 j表终点
		for(j=0;j<nums.size();j++)
		{
			sum = sum + nums[j];
			total = total + nums[j];
			//实时更新起点
			while(sum >= target)
			{
				sum = sum - nums[i];    //更新窗口内总和
				len = j - i + 1;        //更新窗口长度
				i++;                    //更新窗口起点     
			}
			if(len < minlen)
				minlen = len;
		}
		if(total < target)
			return  0;
		else
			return minlen;
	}
};


int main()
{
	Solution s;
	vector<int> nums{2,3,1,2,4,3};
	int target = 7;
	int ret = s.minSubArrayLen(target, nums);
	cout << ret << endl;
	return 0;
} 
