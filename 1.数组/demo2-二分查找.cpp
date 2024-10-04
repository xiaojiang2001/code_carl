#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

//nums{5,7,7,8,8,10};
class Solution {
public:
	int search(vector<int>& nums, int target) 
	{
		int left  = 0;
		int right = nums.size() - 1;
		int mid;
		while(left <= right)
		{
			mid = left + (right - left) / 2;
			if(nums[mid] > target) 
				right = mid - 1;
			else if(nums[mid] < target)
				left = mid + 1;
			else   
				return mid;
		} 
		return -1;
	}
};
int main()
{
	Solution s;
	vector<int> nums{-1,0,3,5,9,12};
	int target = 9;
	int ret = s.search(nums,target);
	cout << ret << endl;
	return 0;
} 
