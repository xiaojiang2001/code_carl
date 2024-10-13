#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    queue<int> que1;    // 主队列
    queue<int> que2;    // 备份数据队列
    MyStack() {

    }
    
    void push(int x) {
        que1.push(x);
    }
    
    int pop() {
        // que2入队保存
        while (!que1.empty() && que1.size() != 1) {
            que2.push(que1.front());
            que1.pop();
        }
        // 获取并弹出弹出队尾元素
        int res = que1.front();
        que1.pop();

        // 还原其余元素
        while (!que2.empty()){
            que1.push(que2.front());
            que2.pop();
        }
        
        return res;
    }
    // 队列可以直接获取头尾元素
    int top() {
        return que1.back();
    }
    
    bool empty() {
        return que1.empty();
    }
};


int main()
{

}