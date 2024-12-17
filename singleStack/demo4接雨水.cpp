#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;
// 双指针模拟，竖向考虑接雨水，求当前柱子左右的最大值
/*
int trap(vector<int>& height) {
    // 保存右边的最大高度
    vector<int> left(height.size()); 
    // 保存左边边的最大高度
    vector<int> right(height.size());

    // 记录每个柱子左边柱子最大高度
    // 每个柱子左边的最大值 要么是自己，要么是左边那根的最大值
    left[0] = height[0];
    for (int i = 1; i < height.size(); i++) {
        left[i] = max(height[i], left[i - 1]);
    }

    // 记录每个柱子右边柱子最大高度
    // 每个柱子右边的最大值 要么是自己，要么是右边那根的最大值
    right[height.size() -1] = height[height.size() -1];
    for (int i = height.size() - 2; i >= 0; i--) {
        right[i] = max(height[i], right[i + 1]);
    }

    int sum = 0;
    for (int i = 0; i < height.size(); i++)
    {
        if(left[i] != -1 && right[i] != -1)
        {
            int area = min(left[i], right[i]) - height[i];
            // cout << "i= " << i << ", are = " << area << endl;
            sum += area;
        }
    }

    return sum;   
}
*/


int trap(vector<int>& height) {
    int sum = 0;
    stack<int> st;
    for (int i = 0; i < height.size(); i++)
    {
        if(st.empty()) {
            st.push(i);
            continue;
        }
        if(height[i] < height[st.top()])
            st.push(i);
        // 当前元素 == 栈顶元素
        else if (height[i] == height[st.top()])
        {
            st.pop();
            st.push(i);
        }
        else
        {
            while (!st.empty() && height[i] > height[st.top()])
            {
                int mid = st.top();
                st.pop();
                if(!st.empty())
                {
                    int right = i;
                    int left = st.top();
                    int h = min(height[right], height[left]) - height[mid];
                    int w =  right - left - 1;
                    sum += w * h;
                }
            }
            st.push(i);
        }
    }
    return sum;   
}

int main()
{
    vector<int> nums{0,1,0,2,1,0,1,3,2,1,2,1};

    int res = trap(nums);
    cout << res << endl;

    return 0;
}