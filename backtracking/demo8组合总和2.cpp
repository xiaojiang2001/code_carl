#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> path;
vector<vector<int>> res;
// 本题类似于哈希表中的三数之和 去重是关键
void backtracking(vector<int>& candidates, int target, int start, vector<bool>& used)
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
        // 从第二个元素起 后面元素和前面元素相等 且 树枝上不用前面那个相同的数
        if (i > 0 && candidates[i] == candidates[i-1] && used[i-1] == false)
            continue;
        path.push_back(candidates[i]);
        used[i] = true;
        backtracking(candidates, target, i+1, used); 
        // 回溯
        path.pop_back();
        used[i] = false;    
    }
    return;
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    path.clear();
    res.clear();
    // 记录每一个元素的使用情况
    vector<bool> used(candidates.size(), false);
    sort(candidates.begin(), candidates.end());
    backtracking(candidates, target, 0, used);
    return res;
}

int main()
{
    vector<int> nums{10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> dst = combinationSum2(nums, target);
    for (auto vec: dst)
    {
        for (int num: vec)
            cout << num << " ";
        cout << endl;
    }
    return 0;
}