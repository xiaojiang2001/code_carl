#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) 
	{
		int cnt = 0;
		int j = 0;	//保存结果的指针
		//快指针 i 遍历
		//慢指针 j 保存结果
		for(int i = 0; i < nums.size(); i++)
		{
			if(nums[i] != 0)
				nums[j++] = nums[i];
			else 
				cnt++;
		}
		//末尾补0
		for(int i = 0; i < cnt; i++){
			nums[j++] = 0;
		}
	}
};


int main()
{
	Solution s;
	vector<int> nums ={0,1,0,3,12};
	s.moveZeroes(nums);
	for(int num: nums)
		cout << num << " ";
	return 0;
}
