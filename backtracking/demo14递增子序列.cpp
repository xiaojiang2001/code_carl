#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;



vector<int> path;
vector<vector<int>> res;
void backtracking(vector<int>& nums, int startIdx)
{
    if (path.size() > 1)
        res.push_back(path);
    if (startIdx >= nums.size()) {
        return;
    }

    // 单层递归逻辑
    unordered_set<int> uset;    // 在这里定义 记录每层递归的使用情况
    for (int i = startIdx; i < nums.size(); i++)
    {   
        if (!path.empty() && nums[i] < path.back() ||       // 非递增
            uset.find(nums[i]) != uset.end())               // 去重
            continue;

        path.push_back(nums[i]);
        uset.insert(nums[i]);

        // 递归 
        backtracking(nums, i + 1);      
        // 回溯
        path.pop_back();
        uset.erase(nums[i]);   
    }
    return;
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
    path.clear();
    res.clear();
    
    backtracking(nums, 0);
    return res;  
}
int main()
{
    vector<int> nums{4,4,3,2,1};
    vector<vector<int>> res = findSubsequences(nums);
    for ( auto vec: res)
    {
        for (int num: vec) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}