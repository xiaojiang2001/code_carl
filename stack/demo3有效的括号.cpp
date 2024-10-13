#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s) {
    stack<char> stack;
    for (int i = 0; i < s.size(); i++)
    {
        // 左括号 入栈
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stack.push(s[i]);
        }
        // 右括号 匹配
        else 
        {
            // 匹配成功 
            if (!stack.empty() && stack.top() == '(' && s[i] == ')' ||
                !stack.empty() && stack.top() == '[' && s[i] == ']' ||
                !stack.empty() && stack.top() == '{' && s[i] == '}' )
            {
                stack.pop();
            }
            else {  // 匹配失败 
                return false;
            }
        }
    }
    // 还有左括号
    if (!stack.empty()){
        return false;
    }
    return true;
}


int main()
{

    return 0;
}