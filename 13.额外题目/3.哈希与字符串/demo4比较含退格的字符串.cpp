#include <bits/stdc++.h>

using namespace std;

bool backspaceCompare(string s, string t) {
    stack<char> st1;
    stack<char> st2;
    // 栈获取结果字符串
    for (int i = 0; i < s.size(); i++) {
        if(s[i] == '#' && !st1.empty())
            st1.pop();
        else if(s[i] != '#')
            st1.push(s[i]);
    }
    for (int j = 0; j < t.size(); j++) {
        if(t[j] == '#' && !st2.empty())
            st2.pop();
        else if(t[j] != '#')
            st2.push(t[j]);
    }
    // 判断
    if(st1.size() != st2.size())
         return false;
    while(!st1.empty() && !st2.empty()) 
    {
        if(st1.top() != st2.top())
            return false;
        else {
            st1.pop();
            st2.pop();
        }
    }
    return true;
}

int main()
{
    string s = "abcd";
    string t = "bbcd";
    bool ret = backspaceCompare(s, t);
    cout << ret << endl;
    return 0;
}