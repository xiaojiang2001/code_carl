#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> path;
vector<vector<int>> res;
void backtracking(int k, int n, int start)
{
    // 终止条件
    if (path.size() == k)
    {
        int sum = accumulate(path.begin(), path.end(), 0);
        if (sum == n)
            res.push_back(path);
        return;        
    }
    // 单层递归逻辑
    // 当前用了 path.size()个
    // 还需要 k - path.size个
    // 最多从 9 - (k - size) + 1开始
    for (int i = start; i <= 9 - (k - path.size()) + 1; i++)
    {
        path.push_back(i);
        backtracking(k , n, i+1);//
        path.pop_back(); // 回溯
    }
    return;
}


vector<vector<int>> combinationSum3(int k, int n) {
    path.clear();
    res.clear();
    backtracking(k, n, 1);
    return res;
}


// 主函数
int main()
{
    int k = 3;
    int n = 7;
    vector<vector<int>> res = combinationSum3(k, n);
    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}