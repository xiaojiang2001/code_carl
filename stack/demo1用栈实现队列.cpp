#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> stack1;      // 入栈口  
    stack<int> stack2;      // 出栈口
public:
    MyQueue() {

    }
    
    void push(int x) {
        stack1.push(x);
    }
    
    int pop() 
    {
        //stacl1 数据放入stack2
        while (!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }

        //获取栈顶元素 及出队数据
        int res = stack2.top();
        stack2.pop();

        // 数据存回stack1
        while (!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
        return res;
    }
    
    int peek() {
        //stacl1 数据放入stack2
        while (!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }

        //获取栈顶元素 及出队数据
        int res = stack2.top();

        // 数据存回stack1
        while (!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
        return res;
    }
    
    bool empty() {
        return stack1.empty();
    }
};



int main()
{

}