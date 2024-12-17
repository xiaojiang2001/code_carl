#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
{
    stack<int> st;
    vector<int> nums2Res(nums2.size(), -1);

    for(int i = 0; i < nums2.size(); i++)
    {
        if(st.empty()) {
            st.push(i);
            continue;
        }
        // 当前元素大于栈顶元素 这里可能连续大于
        while(!st.empty() && nums2[i] > nums2[st.top()]) {
            nums2Res[st.top()] = nums2[i];    
            st.pop();                           // 移除栈顶元素
        }
        st.push(i);                             // 添加新元素
    }
    // 将nunms与nums2Res进行映射
    unordered_map<int, int> umap;
    for (size_t i = 0; i < nums2.size(); i++) {
        umap[nums2[i]] = nums2Res[i];
    }
    
    // 获取nums1的结果
    vector<int> res(nums1.size(), -1);
    for (size_t i = 0; i < nums1.size(); i++)
    {
        res[i] = umap[nums1[i]];
    }
    
    return res;
}

int main()
{
    vector<int> nums1{2,4};
    vector<int> nums2{1,2,3,4};

    vector<int> res = nextGreaterElement(nums1, nums2);
    for(int num : res)
        cout << num << " ";

    return 0;
}