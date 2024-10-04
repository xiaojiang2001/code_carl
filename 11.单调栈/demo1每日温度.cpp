#include <iostream>
#include <stack>
#include <vector>
using namespace std;


class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) 
	{
        vector<int> result(temperatures.size(), 0);
        stack<int> st;			// 单调递增存放遍历过的数据的下标
        st.push(0);				// 把第一个元素下标先加入
        //数组遍历完毕
        for(int i = 1; i < temperatures.size(); i++)
        {
        	if(temperatures[i] <= temperatures[st.top()])
        		st.push(i);
        	else
        	{
	        	while(!st.empty() && temperatures[i] > temperatures[st.top()])	// 如果遍历数据比栈顶数据大
	        	{
	        		result[st.top()] = i - st.top();			// 计算下标差
	        		st.pop();									// 移除元素下标
				}
				st.push(i);
			}
		}
        return result;
    }
};



int main()
{
	
	return 0;
}