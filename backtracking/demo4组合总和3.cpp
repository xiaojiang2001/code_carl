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
    for (int i = start; i <= 9; i++)
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
}


// 主函数
int main()
{
    int k = 4;
    int n = 9;
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