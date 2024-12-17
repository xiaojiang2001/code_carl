#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

int largestRectangleArea(vector<int>& heights) 
{
    int sum = 0;
    stack<int> st;
    // 2 4 保证左右有比他小的柱子
    heights.insert(heights.begin(),0);
    heights.insert(heights.end(),0);

    // 找左右第一根比自己小的柱子
    for (int i = 0; i < heights.size(); i++)
    {
        if(st.empty()) {
            st.push(i);
            continue;
        }
        if(heights[i] > heights[st.top()])
            st.push(i);
        // 当前元素 == 栈顶元素
        else if (heights[i] == heights[st.top()])
        {
            st.pop();
            st.push(i);
        }
        else
        {
            while (!st.empty() && heights[i] < heights[st.top()])
            {
                int mid = st.top();
                st.pop();
                if(!st.empty())
                {
                    int right = i;
                    int left = st.top();
                    int h = heights[mid];
                    int w =  right - left - 1;
                    sum = max(sum, w * h);
                }
            }
            st.push(i);
        }
    }
    return sum;   
}

int main()
{
    vector<int> nums{2,4};

    int res = largestRectangleArea(nums);
    cout << res << endl;

    return 0;
}