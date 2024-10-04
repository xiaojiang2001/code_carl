#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	// 暴力求解
	int largestRectangleArea1(vector<int>& heights) 
	{
		int sum = 0;
		for(int i = 0; i < heights.size(); i++)
		{
			int left = i;
			int right = i;
			// 往左找第一根比自身矮的柱子
			for(; left >= 0; left--)
			{
				if(heights[left] < heights[i])
					break;
			}
			// 往右找第一根比自身矮的柱子
			for(; right < heights.size(); right++)
			{
				if(heights[right] < heights[i])
					break;
			}
			int w = right - left - 1;
			int h = heights[i];
			sum = max(sum, w * h);
		}
		return sum;
	}
	
	// 暴力求解 - 双指针优化
	int largestRectangleArea2(vector<int>& heights) 
	{
		int result = 0;
		int size = heights.size();
		
		vector<int> minLeftIndex(heights.size(),  -1);
		vector<int> minRightIndex(heights.size(), -1);
		
		// 记录每个柱子 左边第一个小于该柱子的下标
        minLeftIndex[0] = -1; 	// 注意这里初始化，防止下面while死循环
        for (int i = 1; i < size; i++) {
            int t = i - 1;
            // 这里不是用if，而是不断向左寻找的过程
            while (t >= 0 && heights[t] >= heights[i]) 
				t--;
            minLeftIndex[i] = t;
        }
        
        // 记录每个柱子 右边第一个小于该柱子的下标
        minRightIndex[size - 1] = size; 	// 注意这里初始化，防止下面while死循环
        for(int i = 0; i < size - 1; i++)
        {
        	int t = i + 1;
        	while(t < size && heights[t] >= heights[i]	)
        		t++;
        	minRightIndex[i] = t;
		}
        
        for(int i = 0; i < size; i++)
        {
        	int w = minRightIndex[i] - minLeftIndex[i] - 1;
        	int h = heights[i];
        	result = max(w * h, result);
		}
		return result;
	}
	
	int largestRectangleArea(vector<int>& heights) 
	{
		int result = 0;
		stack<int> st;		
		heights.insert(heights.begin(), 0);
		heights.push_back(0);
		
		st.push(0);	
		// 记录每一个数值左右两边比自身小的数值 即矩形面积
		for(int i = 1; i < heights.size(); i++)
		{
			if(heights[i] >= heights[st.top()])
				st.push(i);
			else
			{
				while(!st.empty() && heights[i] < heights[st.top()])
				{
					int mid = st.top();			// 中间元素的下标 为基准
					st.pop();
					
					// 左边第一个比他小的元素为栈里面第二个元素
					if(!st.empty())
					{
						int left = st.top();
						int right = i;				// 右边比中间小的 下标
						int h = heights[mid];
						int w = right - left - 1;
						result = max(h * w, result);
					}
				}
				st.push(i);
			}
		}
		return result;	
	}
};

int main()
{
	Solution s;
	vector<int> height{9,0};
	int ret = s.largestRectangleArea2(height);
	cout << "ret: " << ret << endl;
	return 0;
}