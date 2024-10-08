#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
/*
	//利用了辅助数组
	vector<int> sortArrayByParityII(vector<int>& nums) 
	{
		vector<int> res(nums.size());
		int i = 0;	//奇数指针
		int j = 0;	//偶数指针
		int idx = 0;	//结果指针
		while(idx < nums.size())
		{
			while(i < nums.size() && nums[i] % 2 == 0){
				i++;
			}
			while(j < nums.size() && nums[j] % 2 == 1){
				j++;
			}
			//奇数
			if(idx % 2)
				res[idx] = nums[i++];
			//偶数
			else
				res[idx] = nums[j++];
			idx++;
		}
		return res;
	}
*/
	
/*
	//遍历判断 nums[i]是奇是偶，非连续的存入结果集
	vector<int> sortArrayByParityII(vector<int>& nums) 
	{
		vector<int> res(nums.size());
		int evenIdx = 0;	// 偶数指针
		int oddIdx  = 1;	// 奇数指针
		for(int i = 0; i < nums.size(); i++)
		{
			if(nums[i] % 2)
			{
				res[oddIdx] = nums[i];
				oddIdx += 2;
			}
			else
			{
				res[evenIdx] = nums[i];
				evenIdx += 2;
			}
		}
		return res;
	}
*/
	// 方式三 不开辟额外的空间 那就是对原数做双指针操作或者函数操作
	vector<int> sortArrayByParityII(vector<int>& nums) 
	{
		int oddIdx = 1;		//奇位
		//哪些数据是要交换的 偶位奇数
		for(int i = 0; i < nums.size(); i += 2)
		{
			if(nums[i] % 2)		//待交换的偶位奇数
			{
				//找第一位 奇位偶数
				while(nums[oddIdx] % 2){	
					oddIdx += 2;
				}
				//交换
				swap(nums[i], nums[oddIdx]);
			}
		}
		return nums;
	}
};


int main()
{
	Solution s;
	vector<int> nums ={4,2,5,7,1,8};
	vector<int> res = s.sortArrayByParityII(nums);
	for(int num:res){
		cout << num << " ";
	}
	return 0;
}

