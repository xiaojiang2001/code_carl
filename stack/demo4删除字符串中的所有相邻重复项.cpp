#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

string removeDuplicates(string s) 
{
    stack<char> stack;
    //拼接结果 反向
    for(auto ch: s)
    {
        // 相邻字母不相等
        if (stack.empty() || stack.top() != ch){
            stack.push(ch);
        }   
        // 字母相等
        else {  
            stack.pop();
        }
    }    
    string res = "";
    while (!stack.empty());
    {
        res = stack.top() + res;
        stack.pop();
    }
    reverse(res.begin(), res.end());

    return res;
}


int main()
{
    string s = "abbaca";  
    cout << "stack success" << endl;
    removeDuplicates(s);
    //cout << res << endl;
    return 0;
}