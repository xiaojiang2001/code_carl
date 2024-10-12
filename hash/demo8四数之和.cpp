#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;
// nums = [1,0,-1,0,-2,2]
vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	for(int i = 0; i < nums.size(); i++){
		//剪枝
		if(nums[i] > target && nums[i] >= 0)	break;
		// a 去重
		if(i > 0 && nums[i] == nums[i-1])		continue;
		for(int j = i + 1; j < nums.size(); j++){
			//二级剪枝
			if(nums[i] + nums[j] > target && nums[i] + nums[j] >= 0)	break;
			// b 去重
			if(j > i + 1 && nums[j] == nums [j-1])			continue;	
			
			// 双指针开始遍历 判断
			int left = j + 1;
			int right = nums.size() - 1;
			while(left < right){
				if((long) nums[i] + nums[j] + nums[left] + nums[right] > target)		right--;
				else if((long) nums[i] + nums[j] + nums[left] + nums[right] < target)	left++;
				// 开始回收
				else{
					res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
					// 去重 c d
					while(left < right && nums[left] == nums[left + 1])		left++;
					while(left < right && nums[right] == nums[right - 1])	right--;
					
					// 找到了 双指针偏移
					left++;
					right--;
				}
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
