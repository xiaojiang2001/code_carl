#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 判断当前字符串是否合法
bool isValid(string s)
{
    if (s.size() >= 4)
        return false;
    if (s.size() > 1 && s[0] == '0')
        return false;

    int num = 0;
    for (int i = 0; i < s.size(); i++)
    {
        num *= 10;
        num += s[i] - '0';
    }
    if (num >= 0 && num <= 255)
        return true;

    return false;
}


vector<string> res;
// 通过数组保存ip 为了好回溯
vector<int> path;  
void backtracking(string s, int startIdx)
{
    if (startIdx >= s.size())
    {
        if (path.size() == 4)
        {
            // 拼接字符串
            string str;
            for (int i = 0; i < path.size() - 1; i++)
            {
                str += to_string(path[i]) + ".";
            }
            str += to_string(path[path.size() - 1]);

            res.push_back(str);
            return;
        }
    }

    for (int i = startIdx; i < s.size(); i++)
    {
        // 获取当前字符串
        string sub = s.substr(startIdx, i - startIdx + 1);
        if(isValid(sub))
            path.push_back(stoi(sub));
        else
            continue;
        // 递归 进入下层
        backtracking(s, i + 1);
        // 回溯
        path.pop_back();
    }

    return;
}

vector<string> restoreIpAddresses(string s) 
{
    path.clear();
    res.clear();
    backtracking(s,0);
    return res;
}

int main()
{
    string s = "25525511135";
    vector<string> dst = restoreIpAddresses(s);
    for (auto str: dst)
        cout << str << endl;
    return 0;    
}