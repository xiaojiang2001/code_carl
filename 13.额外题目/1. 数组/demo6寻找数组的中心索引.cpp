#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	int pivotIndex(vector<int>& nums) 
	{
		int sum = 0;
		//总和
		for(int num: nums)
			sum += num;
		int leftSum = 0;
		int rightSum = 0;
		for(int i = 0; i < nums.size(); i++)
		{
			//这里算左右两侧的和都加上nums[i]本身
			leftSum += nums[i];
			rightSum = sum - leftSum + nums[i];
			if(leftSum == rightSum)
				return i;
		}
		return -1;
	}
};


int main()
{
	Solution s;
	vector<int> nums ={2, 1, -1};
	int idx = s.pivotIndex(nums);
	cout << idx << endl;
	
	return 0;
}
