#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> res;
vector<int> path;
void backtracking(vector<int>& nums, vector<bool>& used)
{
    if (path.size() == nums.size()) {
        res.push_back(path);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        // 排列需要记录元素的使用情况
        if (used[i] == true)
            continue;
        path.push_back(nums[i]);
        used[i] = true;
        backtracking(nums, used);
        path.pop_back();
        used[i] = false;
    }
    return;
}
vector<vector<int>> permute(vector<int>& nums) 
{
    res.clear();
    path.clear();
    vector<bool> used(nums.size(), false);
    backtracking(nums, used);
    return res;
}

int main()
{
    vector<int> nums{1,2,3};
    vector<vector<int>> res = permute(nums);
    for ( auto vec: res)
    {
        for (int num: vec) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}