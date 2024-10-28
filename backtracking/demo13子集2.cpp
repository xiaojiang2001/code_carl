#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> path;
vector<vector<int>> res;
void backtracking(vector<int>& nums, int startIdx, vector<bool>& used)
{
    res.push_back(path);
    if (startIdx >= nums.size()) {
        return;
    }
    // 单层处理逻辑
    for (int i = startIdx; i < nums.size(); i++)
    {
        // 树层上去重
        if (i > 0 && nums[i] == nums[i-1] && used[i-1] == false)
            continue;
        // 加入结果集
        path.push_back(nums[i]);
        used[i] = true;
        // 递归处理
        backtracking(nums, i + 1, used);
        // 回溯
        path.pop_back();
        used[i] = false;
    }
    return;
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    path.clear();
    res.clear();
    vector<bool> used(nums.size(), false);
    backtracking(nums, 0, used);
    return res; 
}


int main()
{
    vector<int> nums{1,2,2};
    vector<vector<int>> res = subsetsWithDup(nums);
    for ( auto vec: res)
    {
        for (int num: vec) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}