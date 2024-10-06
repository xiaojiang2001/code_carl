#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 创建K大小的小顶堆 pop出的是小的元素，大的元素留在堆中



class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
	{
		//统计元素与元素频率
		unordered_map<int, int> umap;
		for(int i = 0; i < nums.size();i++)
			umap[nums[i]]++;
		
		
		
		
		priority_queue<> 
		
		

		cout << umap[3];
    }
};

//主程序
int main()
{
	Solution* s = new Solution();
	vector<int> nums = {1,3,5,3,6,3,7};
	vector<int> ret = s->topKFrequent(nums,3);
//	for(int i = 0; i< ret.size();i++)
//		cout << ret[i] << endl;
    return 0;
}

