#include <iostream>
#include <vector>

using namespace std;



vector<int> path;
vector<vector<int>> res;
void backtracking(vector<int>& nums, int startIdx)
{
    // 收集所有节点的结果
    res.push_back(path);
    // 越界 结束
    if (startIdx >= nums.size()) {
        return;
    }
    // 单层遍历逻辑
    for (int i = startIdx; i < nums.size(); i++)
    {
        path.push_back(nums[i]);
        backtracking(nums, i + 1);      // 递归遍历
        path.pop_back();                // 回溯
    }
    return;
}


vector<vector<int>> subsets(vector<int>& nums) {
    path.clear();
    res.clear();
    backtracking(nums, 0);
    return res;
}
 
int main()
{
    vector<int> nums{1,2,3};
    vector<vector<int>> res = subsets(nums);
    for ( auto vec: res)
    {
        for (int num: vec) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}