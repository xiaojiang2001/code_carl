#include <iostream>
#include <vector>
#include <string>

using namespace std;


// 判断一个字符串是否为回文串
bool judge(string& s)
{
    int i = 0;
    int j = s.size() - 1;
    while (i <= j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;   
    }
    return true; 
}

vector<vector<string>> res;
vector<string> path;    // 放已经回文的子串 收集可行的路径

// 分割和组合的选取元素过程是一样的
// startIdx: 切割线位置


void backtracking(string& s, int startIdx)
{
    // 切割到末尾了
    if (startIdx >= s.size())
    {
        res.push_back(path);
        return;
    }
    // 子串 [startIdx, i]
    for (int i = startIdx; i < s.size(); i++)
    {
        // 获取子串 subStr: 起始位置 + 长度
        string subStr = s.substr(startIdx, i - startIdx + 1);
        if (judge(subStr))
            path.push_back(subStr);
        else   
            continue;
        // 递归
        backtracking(s, i + 1);
        // 回溯
        path.pop_back();
    }
    return;
}

vector<vector<string>> partition(string s) 
{
    res.clear();
    path.clear();
    backtracking(s, 0);
    return res;
}

int main()
{
    vector<vector<string>> dst = partition("aab");
    for (auto vec : dst)
    {
        for (auto str: vec)
        {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}