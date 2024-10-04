#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) 
	{
    	stack<char> stack;		//备份栈
    	int i;
    	string ret = "";
    	
    	//遍历字符串
    	for(i = 0; i < s.size(); i++)
		{
			 //如果栈为空 先入栈
			if(stack.empty())
			{
				//字符入栈
				stack.push(s[i]);
				//cout << "stack_push: " << s[i] << endl;
			}
			//函数不为空 判断是否相邻
			else
			{
				//存在相邻重复项
				if(s[i] == stack.top())
				{
					//cout << "pop: " << stack.top() << endl;
					stack.pop();
				}
				//不存在相邻重复项 数据入栈  
				else
				{
					stack.push(s[i]);
					//cout << "stack_push: " << s[i] << endl;
				}	
			}	
		}
    		
		//栈中数据转化为字符串
		while(!stack.empty())
		{
			ret = ret + stack.top();
			cout << "stack_top: " << stack.top() << endl;
			stack.pop();
		}
		
		//反转ret结果
		reverse(ret.begin(),ret.end());		
		//cout << "ret: " << ret << endl;
		return ret;
    }
};

//主程序
int main()
{
	Solution* s = new Solution();
	s->removeDuplicates("abbaca");
    return 0;
}