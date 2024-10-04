#include<iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


//方式二遍历
void func(int val)
{
	cout << val << endl;
}


//vector存放自定义数据类型
class Person
{
public:
	string name;
	int age;
	
	Person(string name, int age)
	{
		this->name = name;
		this->age  = age;
	}
};

//容器存放int数据类型并遍历
void test01()
{
	vector<int> v;				//创建vector容器对象 v
	
	//每一个容器都有自己的迭代器，迭代器是用来遍历容器中的元素
	//v.begin()返回迭代器，这个迭代器指向容器中第一个数据
	//v.end()返回迭代器，这个迭代器指向容器元素的最后一个元素的下一个位置
	//vector<int>::iterator 拿到vector<int>这种容器的迭代器类型
	
	
	//向容器中放数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	
	cout << "1.容器存放int数据类型并遍历  方式一" << endl;
	//遍历方式1
	vector<int>::iterator it;	//创建vector容器迭代器
	for(it=v.begin(); it!=v.end(); it++)
	{
		cout << *it << endl;
	}
	
	cout << "1.容器存放int数据类型并遍历  方式二" << endl;
	//遍历方式2
	for_each(v.begin(), v.end(), func);
}

//2. 容器存放自定义数据
void test02()
{
	vector<Person> v;		//创建vector容器对象，存放自定义数据
	
	
	Person p1("张三", 21);
	Person p2("李四", 22);
	Person p3("王五", 23);
	
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	
	cout << "2. 容器存放自定义数据并遍历" << endl;	
	//存放自定义数据 遍历
	vector<Person>::iterator it;
	for(it = v.begin(); it != v.end(); it ++)
	{
		cout << (*it).name << " " << (*it).age << endl;		//*it代表<>内的数据类型
		//或者 因为it2本质为指针
		//cout << it->name << " " << it->age << endl;
	}
}


//3. 容器存放自定义数据 指针
void test03()
{
	vector<Person *> v;		//创建vector容器对象，存放自定义数据
	
	vector<Person *>::iterator it;	//创建vector容器迭代器
	
	Person p1("张三", 21);
	Person p2("李四", 22);
	Person p3("王五", 23);
	
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);

	cout << "3. 容器存放自定义数据指针并遍历" << endl;
	//存放自定义数据 遍历
	for(it = v.begin(); it != v.end(); it++)
	{
		cout << (*it)->name << " " << (*it)->age << endl;		//*it代表<>内的数据类型
		
	}
}


//4. 容器嵌套容器  容器~=数组    容器嵌套 ~= 二维数组
void test04()
{
	//创建大容器
	vector< vector<int> > v;		//创建大容器，存放小容器
	
	//创建小容器
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	vector<int>v4;
	
	//小容器添加数据
	for(int i=0; i<4; i++)
	{
		v1.push_back(i+1);
		v2.push_back(i+2);
		v3.push_back(i+3);
		v4.push_back(i+4);
	}
	
	//将小容器放入大容器
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	
	
	//循环遍历
	cout << "循环遍历大小容器内数据" << endl;
	for(vector< vector<int> >::iterator it = v.begin(); it != v.end(); it++)	//创建大容器迭代器
	{
		//*it ------vector<int> 还是个容器
		for(vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)	//创建小容器迭代器
		{
			cout << *vit << " ";
		}
		cout << endl;
	}
}




int main()
{
	test01();
	test02();
	test03();
	test04();
	
	return 0;

}
