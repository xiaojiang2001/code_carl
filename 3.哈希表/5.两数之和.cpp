#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

 // ☆☆☆ map + 哈希
//为什么用哈希表 
//为什么用map系列容器
//为什么选unordered_map
//map中的key和val分别存放什么，为什么这样设置：
//因为要找的是元素是否出现过 find查找针对的是key

vector<int> twoSum(vector<int>& nums, int target) {
    int i;	
    unordered_map<int, int> map;	//创建容器
	    
	for(i = 0; i < nums.size(); i++) 
    {
    	// 遍历当前元素，并在map中寻找是否有匹配的key
    	auto iter = map.find(target- nums[i]);	//用迭代器接收find的结果
    	if(iter != map.end())				
        {
            return {iter->second, i};
        }
        // 如果没找到匹配对，就把访问过的元素和下标加入到map中
        map.insert({nums[i],i});
    }
    return {};
}

int main()
{
	vector<int> nums{2,7,11,15};
	vector<int> ret = twoSum(nums, 9);
	cout << ret[0] << "\t" << ret[1];
	return 0;
} 





