#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class MyStack {
public:
	queue<int> queue1;	//队列1  主队列
	queue<int> queue2;	//队列1
	
    MyStack() {

    }
    
    //栈顶插入数据 即队尾插入数据 
    void push(int x) {
        queue1.push(x);
    }
    
    //移除栈顶数据
    int pop() 
	{
		//1. 将主队列中的 size-1 个数据先暂存到另一个队列2中
		while(queue1.size() !=1)
		{
			queue2.push(queue1.front());	//数据暂存队列2
			queue1.pop();					//主队列弹出数据
		}
		
		//2. 移除主队列中的最后一个元素
		int val = queue1.back();
		queue1.pop();
		
		//3. 将备用队列中的元素全部移回主队列
		while(!queue2.empty())
		{
			queue1.push(queue2.front());	//数据移回主队列
			queue2.pop();					//备用队列弹出数据
		}	
		
		return val;
    }
    
    //获取栈顶数据 即获取队尾数据
    int top() 
	{
		return queue1.back();
    }
    
    //栈为空即主队列为空
    bool empty() {
    	return queue1.empty();
    }
};


//主程序
int main()
{
	MyStack* myStack = new MyStack();
	myStack->push(1);
	myStack->push(2);
	cout << myStack->top() << endl; // 返回 2
	cout << myStack->pop() << endl; // 返回 2
	cout << myStack->empty()<< endl; // 返回 False
    return 0;
}