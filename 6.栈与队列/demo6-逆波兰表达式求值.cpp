#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens)
	{
		//逆波兰表达式，也即后缀表达式，相当于是对二叉树的后续遍历（左右中）
		//遇见数字加入栈; 遇到操作符, 从栈里取出元素进行相应运算后再存入栈
    	stack<long long> stack;		//数据存储栈
    	for(int i = 0; i < tokens.size(); i++)
    	{
    		//遇见操作符取两个元素进行运算
    		if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
    		{
    			//从栈中获取2个元素进行运算
    			long long num1 = stack.top();
    			stack.pop();
    			long long num2 = stack.top();
    			stack.pop();
    			
    			if(tokens[i] == "+")	stack.push(num2 + num1);
    			if(tokens[i] == "-")	stack.push(num2 - num1);
    			if(tokens[i] == "*")	stack.push(num2 * num1);
    			if(tokens[i] == "/")	stack.push(num2 / num1);
 			}
			else	//遇见数字加入栈
				stack.push(stoll(tokens[i]));
		}
		cout << "ret: " << stack.top();
		return stack.top();	
    }
};

//主程序
int main()
{
	Solution* s = new Solution();
	vector<string> tokens["2","1","+","3","*"];
	s->evalRPN(tokens);
    return 0;
}

