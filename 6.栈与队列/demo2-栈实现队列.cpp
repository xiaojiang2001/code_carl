#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class MyQueue {
public:
	stack<int> stack1;	//进栈口
	stack<int> stack2;	//出栈口
	
    MyQueue() {

    }
    
    void push(int x) {
        stack1.push(x);
    }
    
    int pop() 
	{
		//将栈1的数据存入栈2
    	while(!stack1.empty())
    	{
    		stack2.push(stack1.top());	
    		stack1.pop();
		}
		
		//暂存stack2的栈顶数据 并移除栈顶元素
		int value = stack2.top();		
		stack2.pop();				
		
		//将stack2的数据还给stack1
		while(!stack2.empty())
		{
			stack1.push(stack2.top());
			cout << "s2->s1: " << stack2.top() << endl;
			stack2.pop();
		}
		
		return value;	
    }
    
    int peek() 
	{
    	while(!stack1.empty())
    	{
    		stack2.push(stack1.top());	//将栈1的数据存入栈2
    		stack1.pop();
		}
		
		int value = stack2.top();		//暂存stack2的栈顶数据
		
		//将stack2的数据还给stack1
		while(!stack2.empty())
		{
			stack1.push(stack2.top());
			stack2.pop();
		}
		return value;
    }
    
    bool empty() {
		if(stack1.empty() && stack2.empty())
			return true;
		else
			return false;
    }
};


//主程序
int main()
{
    MyQueue* obj = new MyQueue();
    obj->push(10);
    obj->push(20);
    obj->push(30);
    
    cout << "para1: " << obj->pop() << endl;
    cout << "para2: " << obj->peek() << endl;
    cout << "para3: " << obj->empty() << endl;
    
    return 0;
}