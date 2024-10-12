#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) 
{
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	
	// a = nums[i], b = nums[left], c = nums[right]
	for(int i = 0; i < nums.size(); i++){
		if(nums[i] > 0)
			return res;
		
		// a 去重
		// 错误去重a方法，将会漏掉-1,-1,2 这种情况
		// if (nums[i] == nums[i + 1]) 	continue;
		// 正确去重a方法
		if (i > 0 && nums[i] == nums[i - 1]) 	
			continue;
		
		int left = i + 1;
		int right = nums.size() - 1;
		while(left < right)
		{
			// 去重复逻辑如果放在这里，0，0，0 的情况，
			// 可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
			/*
				while (right > left && nums[right] == nums[right - 1]) right--;
				while (right > left && nums[left] == nums[left + 1]) left++;
			*/
			
			//判断三数和
			if(nums[i] + nums[left] + nums[right] > 0) 		right--;
			else if(nums[i] + nums[left] + nums[right] < 0) left++;
			//找到一组后 去重 双指针同时偏移
			else{
				//回收答案
				res.push_back(vector<int>{nums[i], nums[left], nums[right]});
				//去重
				while(left < right && nums[left] == nums[left+1])	left++;
				while(left < right && nums[right] == nums[right-1]) right--;
				// 找到答案时，双指针同时收缩
				left++;
				right--;
			}
		}
	}
	return res;
}

int main()
{
	vector<int>  nums {2,7,11,15};
	//vector<vector<int>> resr= threeSum(nums);

	return 0;
}
