#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) 
	{
		int i;
		stack<char> stack;
		
		//长度为奇数 一定不匹配
		if(s.size() % 2 == 1)
			return false;
		
		//遍历字符串
		for(i = 0 ; i < s.size(); i++)
		{
			//如果是左括号，则往栈存入右括号
			if(s[i] == '(' )	
				stack.push(')');
			else if(s[i] == '[')
				stack.push(']');
			else if(s[i] == '{')
				stack.push('}');
				
			//如果是右括号，判断是否为空栈 并判断是否与栈顶匹配 
			else if ( stack.empty() || stack.top() != s[i] )
				return false;
	
			//匹配括号对
			else
				stack.pop();			
		}
		
		//判断栈最后是否完全匹配完
		if(stack.empty())
			return true;
		else
			return false;
			
    }
};

//整理总结C++ STL中的字符串操作，包括字符串的初始化化，
//主程序
int main()
{
	Solution* s = new Solution();
	cout << s->isValid("()()[]{}))") << endl;
		
	
    return 0;
}