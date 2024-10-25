#include <vector>
#include <string>
#include <iostream>

using namespace std;

// 数字 字母映射
string numMap[10] = {
    "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
};

vector<string> res;
string path;
void backtracking(const string& digits, int start)
{
    // 收集到结果了
    if (path.size() == digits.size())
    {
        res.push_back(path);
        return;
    }

    // 处理单个数字逻辑
    for (int i = start; i < digits.size(); i++)
    {
        // 处理每个数字的字母组合
        for (auto ch: numMap[digits[i] - '0'])
        {
            path.push_back(ch);
            backtracking(digits, i + 1);    // 递归每个字母
            path.pop_back();    // 回溯
        }
    }
    return;
}


vector<string> letterCombinations(string digits) 
{
    res.clear();
    path.clear();
    if (digits.size() == 0)
        return res;    
    backtracking(digits, 0);
    return res;
}

int main()
{
    vector<string> res = letterCombinations("2");
    for (auto str:res)
        cout << str << endl;
    return 0;
}