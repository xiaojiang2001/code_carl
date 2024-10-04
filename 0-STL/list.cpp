#include <iostream>
#include <string>
#include <algorithm>
#include <list>

using namespace std;
//优点： 可以对任意位置进行快速插入或删除元素
//缺点：
//1. 对于元素的遍历速度没有数组快，链表的地址是不连续的
//2. 占用的空间比数组大

void showList(list<int> &list)
{
	for(int item:list)
		cout << item  << " ";
	cout << endl;
}

void test01()
{
	list<int> list1 = {10,20,30};
	list<int> list2 = {2,4,6,8,10};
	
	if(!list1.empty())
	{
		cout << "size: " << list1.size() << endl;
		list1.resize(5);	//重置大小为5个，以默认值填充
		cout << "resize: " << list1.size() << endl;
		showList(list1);
	}
	else
		cout << "容器为空" << endl;
}
void test02()
{
	
	list<int> list1;
	//尾插
	list1.push_back(2);	
	list1.push_back(4);
	//头插
	list1.push_front(10);
	list1.push_front(30);
	cout << "list1 push back + front: ";
	showList(list1);			//30 10 2 4

	//尾删
	list1.pop_back();
	cout << "pop back: ";	
	showList(list1);			//30 10 2

	//头删
	list1.pop_front();
	cout << "pop front: ";	
	showList(list1);			//10 2

	//头+1插
	list1.insert(++list1.begin(), 666);
	cout << "front insert: ";	
	showList(list1);			//10 666 2

	//头+1删
	list1.erase(++list1.begin());
	cout << "front+1 erase: ";	
	showList(list1);			//10  2
	
	

	
}


//用于降序排序
bool myCompare(int v1, int v2)
{
	//降序：让第一个数 > 第二个数
	return v1 > v2;
}

void test03()
{
	list<int> list1 = {6,4,2,10,3};
	cout << "src data: ";	showList(list1);
	
	//降序排序
	list1.sort(myCompare);
	cout << "sort: "; 		showList(list1);
	
	//反转
	list1.reverse();
	cout << "reverse: ";	showList(list1);
}


//自定义Person类
class Person {
public:
	Person(string name, int age , int height)
	{
		this->name = name;
		this->age = age;
		this->height = height;
	}

public:
	string name;  //姓名
	int age;      //年龄
	int height;   //身高
};

bool PersonCompare(Person &p1, Person &p2)
{
	if(p1.age == p2.age)	//年龄相同 按身高降序
	{
		if(p1.height > p2.height)
			return true;
		else
			return false;
	}
	else	//按年龄升序
	{
		if(p1.age < p2.age)
			return true;
		else
			return false;
	}		
}
void showPersonList(list<Person> &list)
{
	auto it = list.begin();
	for( ; it != list.end(); it++)
	{
		cout << "name: " << it->name << "\tage: " << it->age;
		cout << "\t\theight: " << it->height << endl;
	}
}
void test04()
{
	Person p1("张三", 22, 170);
	Person p2("李四", 21, 173);
	Person p3("王五", 20, 168);
	Person p4("陈六", 25, 177);
	Person p5("赵七", 22, 180);
	
	list<Person> list1={p1,p2,p3,p4,p5};
//	list1.push_back(p1);
//	list1.push_back(p2);
//	list1.push_back(p3);
//	list1.push_back(p4);
//	list1.push_back(p5);
	
	//排序前
	cout << "before sort: " << endl; 
	showPersonList(list1);
	
	//自定义排序
	list1.sort(PersonCompare);
	//显示排序后结果
	cout << "after sort: " << endl; 
	showPersonList(list1);
}


int main() {

	test04();

	return 0;
}
