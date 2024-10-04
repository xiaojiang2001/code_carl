#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> &v)
{
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


//vector 构造(定义) 无参构造和拷贝构造用的较多
void test01()
{
	int i;
	
	//1. 默认构造	无参构造 
	vector<int>v1;
	
	for(i =0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	
	//2.拷贝构造
	vector<int> v2(v1);
	printVector(v2);
	
	//3.通过区间方式进行构造
	vector<int> v3(v1.begin(), v1.end());	//前闭后开
	v3 = v2;
	printVector(v3);
	
	//4. n个elem方式进行构造
	vector<int> v4(10, 100);	//10个100, 顺着读, x个y
	printVector(v4);
	
	//赋值
	vector<int> v5;
	v5 = v1;						  //方式一
	v5.assign(v1.begin(), v1.end());  //方式二
	v5.assign(10,6);		//10个6		方式三
	printVector(v5);
	
}


//容量和大小	容量>=大小
void test02()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	printVector(v);
	
	if (v.empty()){
		cout << "v为空" << endl;
	}
	else
	{
		cout << "v不为空" << endl;
		cout << "v的容量 = " << v.capacity() << endl;
		cout << "v的大小 = " << v.size() << endl;
	}
	
	
	//resize 重新指定大小 ，若指定的更大，默认(不写)用0填充新位置，可以利用重载版本替换默认填充
	v.resize(15,10);		//指定大小为15，用10填充剩下
	printVector(v);
	cout << "v的容量 = " << v.capacity() << endl;
	
	//resize 重新指定大小 ，若指定的更小，超出部分元素被删除
	v.resize(5);
	printVector(v);
	
}


//插入和删除
void test03()
{
	vector<int> v1;
	//尾插
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	printVector(v1);
	
	//尾删
	v1.pop_back();
	printVector(v1);
	
	//插入		注意第一个参数是迭代器 
	v1.insert(v1.begin(), 100);		//开头插入100
	printVector(v1);

	v1.insert(v1.begin(), 2, 1000);	//开头插入2个1000
	printVector(v1);
	
	//删除  参数也是一个迭代器
	v1.erase(v1.begin());		//删除开头1个数
	printVector(v1);
	
	//erase也可以是区间
	v1.erase(v1.begin(),v1.begin()+3);	//删除开头3个数
	printVector(v1);
	
	v1.erase(v1.begin(),v1.end());	//相当于清空
	v1.clear();				//清空
	printVector(v1);
}


//数据存取 
//除了用迭代器获取容器元素，[ ]和at也可以
// []相当于看成数组,  at是str的方法，面向对象思路
void test04()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << " ";
	}
	cout << endl;

	cout << "v1的第一个元素为： " << v1.front() << endl;
	cout << "v1的最后一个元素为： " << v1.back() << endl;
}



int main()
{
//	test01();	//构造初始化与赋值
//	test02();	//容量和大小  方法：empty(), capacity(), size(), resize(newSize,elem)
//	test03();	//插入和删除 	方法，
	//尾插: push_back(num)  尾删:pop_back(num)  插入: insert(迭代器, n, num)   删除: erase(迭代器或迭代器区间)
//	test04();	//v[index], v.at(index), v.front(), v.back()

	return 0;
}
