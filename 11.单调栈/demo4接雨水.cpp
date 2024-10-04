#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) 
	{
		int result = 0;
		stack<int> st;		
		if(height.size() == 0)
			return result;
		st.push(0);	
		// 记录每个格子左右两边比他的的第一个元素和自身的差值
		for(int i = 1; i < height.size(); i++)
		{
			if(height[i] <= height[st.top()])
				st.push(i);
			else if(height[i] == height[st.top()])
			{
				st.pop();
				st.push(i);
			}
			else
			{
				while(!st.empty() && height[i] > height[st.top()])
				{
					int mid = st.top();			// 中间元素的下标
					st.pop();
					if(!st.empty())
					{
						// 左边第一个比他大的元素为栈里面第二个元素
						int h = min(height[i], height[st.top()]) - height[mid];	
						int w = i - st.top() - 1;
						result += (h * w);
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
	vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
	int ret = s.trap(height);
	cout << "ret: " << ret << endl;
	return 0;
}