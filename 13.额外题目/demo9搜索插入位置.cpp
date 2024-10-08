#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) 
	{
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
			else
				return mid;
		}
		return right + 1;
	}
};


int main()
{
	Solution s;
	vector<int> nums ={1,3,5,6};
	int res = s.searchInsert(nums,7);
	cout << res << endl;
	return 0;
}

