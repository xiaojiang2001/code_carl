#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<int> st;
    vector<int> res(temperatures.size());

    for(int i = 0; i < temperatures.size(); i++)
    {
        if(st.empty()) {
            st.push(i);
            continue;
        }

        // 当前元素小于栈顶元素
        if(temperatures[i] <= temperatures[st.top()]) {
            st.push(i);         // 直接添加新元素
            continue;
        }

        // 当前元素大于栈顶元素 这里可能连续大于
        while(!st.empty() && temperatures[i] > temperatures[st.top()]) {
            res[st.top()] = i - st.top();    // 计算间距
            st.pop();                       // 移除栈顶元素
        }
        st.push(i);                     // 添加新元素
    }
    // 剩余没有更大的元素的res为0   可忽略 定义本身就是 0
    while (!st.empty()) {
        st.pop();
    }

    return res;
}

int main()
{
    vector<int> temperatures{73,74,75,71,69,72,76,73};
    vector<int> res = dailyTemperatures(temperatures);
    for(int num : res)
        cout << num << " ";

    return 0;
}