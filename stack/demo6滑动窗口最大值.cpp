#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

class Solution
{
private:
    // 自定义单调队列
   class Myqueue
   {
    public:
        deque<int> que;
        // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
        void pop(int x)
        {
            if (!que.empty() && x == que.front()){
                que.pop_front();
            }
        }

        // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。
        // 这样就保持了队列里的数值是单调从大到小的了。
        void push(int x)
        {
            while (!que.empty() && x > que.back()){
                que.pop_back();    
            }
            que.push_back(x); 
        }
        //获取队列中的最大值
        int getMax()
        {
            return que.front();
        }
   };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        Myqueue que;    //默认大顶堆
        vector<int> res;

        //初始化滑动窗口
        for (int i = 0; i < k; i++){
            que.push(nums[i]);
        }
       res.push_back(que.getMax());
        // 开始滑动
        for(int i = k; i < nums.size(); i++) 
        {
            que.pop(nums[i-k]);
            que.push(nums[i]);
            res.push_back(que.getMax());
        }
        return res;
    }
};


int main()
{
    Solution s;
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> res = s.maxSlidingWindow(nums, k);
    for (int n:res)
        cout << n << " ";
    cout << endl; 
    return 0;
}