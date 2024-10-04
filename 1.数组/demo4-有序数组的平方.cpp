#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		int left = 0;
		int right = nums.size()-1;
		int n = nums.size();
		vector<int> result(n);
		
		for(int i=n-1;i>=0;i--)
		{
			if(nums[right]*nums[right] >= nums[left]*nums[left])
			{
				result[i] = nums[right]*nums[right];
				right--;
			}
			else
			{
				result[i] = nums[left]*nums[left];
				left++;
			}
		}
		return result;
	}
};


int main()
{
	Solution s;
	vector<int> nums{-4,-1,0,3,10};
	vector<int> ret;
	ret = s.sortedSquares(nums);
	for(auto num: ret)
		cout << num << " ";
	return 0;
} 
