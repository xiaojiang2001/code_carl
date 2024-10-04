#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
	{
        /********************暴力求解 超时  O(n x k)******************/
        /*
        vector<int> ret;
		int i, j, max;
		cout << "nums size: " << nums.size() << endl;;
		for(i = 0; i < nums.size() - k + 1;i++)
		{
			max = i;
			for(j = i; j < i + k; j++)
			{
				if(nums[j] > nums[max])
					max = j;
			}
			
			cout << "max: " << nums[max] << endl;
			ret.push_back(nums[max]);
		}
		return ret;
        */
        /****************单调队列求解******************/
    	MyQueue que;
    	vector<int> ret;
    	// 先将前k的元素放进队列
    	for(int i= 0; i < k; i++)
    	{
    		que.push(nums[i]);
		}
		ret.push_back(que.getMax());		// ret 记录前k的元素的最大值
		for(int i = k; i < nums.size(); i++)
		{
			que.pop(nums[i-k]);				// 滑动窗口移除最前面元素
			que.push(nums[i]); 				// 滑动窗口前加入最后面的元素
            ret.push_back(que.getMax()); 	// 记录对应的最大值
		}
		return ret;
    }
    
//自定义单调队列 从大到小
//po
private:
	class MyQueue
	{
	public:
		deque<int> que;		// 使用deque来实现单调队列
		
		// 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
        // 同时pop之前判断队列当前是否为空。
		void pop(int val)
		{
			if(!que.empty() && val == que.front())
				que.pop_front();
		}
		
		// 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。
        // 这样就保持了队列里的数值是单调从大到小的了。
		void push(int val)
		{
			while(!que.empty() && val > que.back())
				que.pop_back();
			que.push_back(val);
		}
		
		// 查询当前队列里的最大值 直接返回队列前端也就是front就可以了。
        int getMax() 
		{
            return que.front();
        }
	};
};

//主程序
int main()
{
	Solution* s = new Solution();
	vector<int> nums = {1,3,-1,-3,5,3,6,7};
	vector<int> ret = s->maxSlidingWindow(nums,3);
	for(int i = 0; i< ret.size();i++)
		cout << ret[i] << endl;
    return 0;
}

