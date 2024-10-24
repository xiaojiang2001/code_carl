#include <iostream>
#include <vector>

using namespace std;

vector<int> path;
vector<vector<int>> res;
void backtracking(int n, int k, int start)
{
    if (path.size() == k)
    {
        res.push_back(path);
        return;
    }  
    // 总共元素: n
    // 当前选了: path.size()
    // 还需选取: k - path.size()
    // 至多从哪里开始搜索：n - (k-path.size()) + 1
    for (int i = start; i <= n - (k-path.size()) + 1; i++)
    {
        path.push_back(i);
        backtracking(n, k, i + 1);
        path.pop_back();
    }
    return;
}

vector<vector<int>> combine(int n, int k) {
    path.clear();
    res.clear();
    backtracking(n, k , 1);
    return res;
}


int main()
{
    vector<vector<int>> res = combine(4,2);
    for (auto vec : res)
    {
        for (auto num: vec)
            cout << num << " ";
        cout << endl;
    }
    return 0;
}

