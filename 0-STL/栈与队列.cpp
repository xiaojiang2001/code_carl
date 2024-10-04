#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

void stack_test()
{
	stack<int> s;	//定义栈
	
	//数据入栈
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	cout << "栈的起始大小为: " << s.size() << endl;
	while(!s.empty())
	{
		//输出栈顶元素
		cout << "栈顶元素为: " << s.top() << endl;
		s.pop();	//出栈
	}
	
	cout << "栈的终止大小为: " << s.size() << endl;
}


class Person
{
public:
	string name;
	int age;
	Person(string name,int age){
		this->name = name;
		this->age = age;
	}
};

void queue_test()
{
	queue<Person> sq;
	
	//实例化对象并入队
	Person p1("张三",18);
	Person p2("李四",22);
	Person p3("王五",20);
	Person p4("陈六",21);
	sq.push(p1);
	sq.push(p2);
	sq.push(p3);
	sq.push(p4);
	
	
	cout << "队列的起始大小为: " << sq.size() << endl;
	while(!sq.empty())
	{
		//获取队头信息
		cout << "name: " << sq.front().name;
		cout << "\tage: " << sq.front().age << endl;
		sq.pop();	//出队
	}
	cout << "队列的终止大小为: " << sq.size() << endl;
}

int main() {

	stack_test();
	//queue_test();
	
	return 0;
}
