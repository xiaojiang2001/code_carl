#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
	//解法一: 循环遍历， 查找, 整体左移
	int removeElement(vector<int>& nums, int val) 
	{
		int numsSize = nums.size();
		for(int i = 0; i < numsSize; i++ )
		{
			if(nums[i] == val)  //需要移除
			{
				//后面数据全部左移
				for(int j = i + 1; j < numsSize; j++) 
				{
					nums[j-1] = nums[j]; 
				}
				numsSize--;     //长度-1
				i--;            //再次从左移过来的那位数据开始遍历
			}
		}
		return numsSize;
	}

/*
	//解法二 双指针，左指针存放目标数据，右指针循环遍历
	int removeElement(vector<int>& nums, int val) 
	{
		int left=0,right=0;
		for(right = 0; right < nums.size(); right++)
		{
			if(nums[right] != val)   //不移除操作
			{
				nums[left] = nums[right];
				left++;
			} 
		}
		return left;
	}
*/
};


int main()
{
	Solution s;
	vector<int> nums{3,2,2,3};
	int val = 3;
	int ret = s.removeElement(nums,val);
	cout << ret << endl;
	return 0;
} 
