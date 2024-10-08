#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) 
	{
		vector<int> res(2,-1);
		res[0] = letfIdx(nums,target);
		res[1] = rightIdx(nums,target);
		return res;
	}
	
// 5 7 7 7 7 7 7 8 8 10
	int letfIdx(vector<int>& nums, int target)
	{
		int leftIdx = -1;
		int left = 0;
		int right = nums.size() - 1;
		int mid;
		while(left <= right)
		{
			mid = left + (right - left) / 2;
			if(target < nums[mid])
				right = mid - 1;
			else if(target > nums[mid])
				left = mid + 1;
			//找到了 继续往左找 看看是否还有
			else
			{
				leftIdx = mid;
				right = mid - 1;
			}
			
		}
		return leftIdx;
	}
	
	int rightIdx(vector<int>& nums, int target)
	{
		int rightIdx = -1;
		int left = 0;
		int right = nums.size() - 1;
		int mid;
		while(left <= right)
		{
			mid = left + (right - left) / 2;
			if(target < nums[mid])
				right = mid - 1;
			else if(target > nums[mid])
				left = mid + 1;
			//找到了 继续往右找 看看是否还有
			else
			{
				rightIdx = mid;
				left = mid + 1;
			}
		}
		return rightIdx;
	}
};


int main()
{
	Solution s;
	vector<int> nums ={5,7,7,7,7,7,7,8,8,10};
	vector<int>  res = s.searchRange(nums,7);
	cout << res[0] << " , "  << res[1]<< endl;
	return 0;
}

