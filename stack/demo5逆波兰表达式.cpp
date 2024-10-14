#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int getNum(string S)
{
    int res = 0;
    for (char s : S){
        res *= 10;
        res += s - '0';
    }
    return res;
}


int evalRPN(vector<string>& tokens) {
    stack<int> st;
    int num1;
    int num2;
    for (auto token: tokens)
    {
        //遇到符号啦
        if (token == "+" || token == "-" || token == "*" || token == "/" )
        {
            num1 = st.top();    st.pop();
            num2 = st.top();    st.pop();
            if (token == "+")   st.push(num2 + num1);
            else if (token == "-")  st.push(num2 - num1);
            else if(token == "*")   st.push(num2 * num1);
            else if (token == "/")   st.push(num2 / num1);
        }
        //遇到数字
        else {  
            st.push(stoi(token));
        }
    }

    int res = st.top();
    st.pop();
    return res;
}


int main()
{
    vector<string> arg{"4","13","5","/","+"};
    int res = evalRPN(arg);
    cout << res << endl;
    return 0;
}

