#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


vector<int> path;
vector<vector<int>> res;
void backtracking(vector<int>& candidates, int target, int start)
{
    int sum = accumulate(path.begin(), path.end(), 0);
    if (sum > target)
        return;
    else if (sum == target) {
        res.push_back(path);
        return;
    }

    for (int i = start; i < candidates.size(); i++)
    {
        path.push_back(candidates[i]);
        backtracking(candidates, target, i);    // 可以重复 从start 自身递归
        path.pop_back();
    }
    return;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    path.clear();
    res.clear();
    backtracking(candidates, target, 0);
    return res;
}

int main()
{
    vector<int> nums{2,3,5};
    int target = 8;
    vector<vector<int>> dst = combinationSum(nums, target);
    for (auto vec: dst)
    {
        for (int num: vec)
            cout << num << " ";
        cout << endl;
    }
    return 0;
}