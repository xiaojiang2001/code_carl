#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) 
{
    int n = nums.size();        // 数组长度
    stack<int> st;              // 单调栈
    vector<int> res(n, -1);     // 结果集

    // 遍历2遍数组 模拟循环数组
    for(int i = 0; i < n * 2; i++)
    {
        if(st.empty()) {
            st.push(i % n);
            continue;
        }

        // 当前元素大于栈顶元素 这里可能连续大于
        while(!st.empty() && nums[i % n] > nums[st.top()]) {
            res[st.top()] = nums[i % n];    
            st.pop();                           // 移除栈顶元素
        }
        st.push(i % n);                             // 添加新元素
    }
    return res;
}

int main()
{
    vector<int> nums{1,2,3,4,3};

    vector<int> res = nextGreaterElements(nums);
    for(int num : res)
        cout << num << " ";

    return 0;
}