#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;


class Solution {
public:
	
	// 创建K大小的小顶堆 pop出的是小的元素，大的元素留在堆中
	class cmp{
	public:
		bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
		{
			return lhs.second > rhs.second;
		}
	};
	
    vector<int> topKFrequent(vector<int>& nums, int k) 
	{
		//统计元素与元素频率
		unordered_map<int, int> umap;
		for(int i = 0; i < nums.size();i++)
			umap[nums[i]]++;
		//定义一个小顶堆 根据val排序
		priority_queue<pair<int,int>, vector<pair<int, int>>, cmp>  que;
		 // 用固定大小为k的小顶堆，扫面所有频率的数值 遍历umap
		for(auto it = umap.begin(); it != umap.end(); it++) 
		{
			//加入的是整个键值对
			que.push(*it);		
			// 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
			if (que.size() > k) {
				que.pop();
			}
		}
		
		// 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
		 vector<int> result(k);
		for (int i = k - 1; i >= 0; i--) 
		{
			result[i] = que.top().first;
			que.pop();
		}
		return result;
    }
};

//主程序
int main()
{
	Solution* s = new Solution();
	vector<int> nums = {1,3,5,3,6,3,7};
	vector<int> ret = s->topKFrequent(nums,3);
	for(int i = 0; i< ret.size();i++)
		cout << ret[i] << endl;
    return 0;
}

