#include <iostream>
#include <set>
#include <string>

using namespace std;

void show_set(set<int> &s)
{
	for(set<int>::iterator it = s.begin(); it != s.end();it++)
		cout << *it << " ";
	cout << endl;
}

//set所有元素都会在插入时自动被排序
//set和multiset区别：
//set不允许容器中有重复的元素
//multiset允许容器中有重复的元素

//set容器特点：
/*
所有元素插入时候会被自动排序
set容器不允许插入重复值

*/
//初始化容器并插入数据 获取大小并交换两个容器
void test01()
{
	set<int> s1{10,20,45,30};	//默认构造 
	set<int> s2{1,2,3};		//构造容器并初始化
	s2.insert(5);
	s2.insert(4);
	
	if(!s1.empty()){
		cout << "s1.size= " << s1.size() << endl;
		cout << "s1: ";
		show_set(s1);
	}
		
	if(!s2.empty()){
		cout << "s2.size= " << s2.size() << endl;
		cout << "s2: ";
		show_set(s2);
	}
	cout << "swap(s1,s2)" << endl;
	cout << "s1: ";
	show_set(s1);
	cout << "s2: ";
	show_set(s2);
}

//set容器的插入与删除
void test02()
{
	set<int> s1{2,5,3,8,0,3,6};		//构造容器并初始化
	//容器实际排序 0 2 3 5 6 8
	
	//删除某个元素
	s1.erase(100);	//若该元素不存在，则容器不变
	
	//删除某个迭代位置 删除第一个
	s1.erase(s1.begin());	// 2 3 5 6 8
	//删除最后一个
	s1.erase(--s1.end());	
	show_set(s1);			// 2 3 5 6
	
	//删除某个迭代区间
	s1.erase(++s1.begin(), --s1.end());	
	show_set(s1);			// 2 6
	
	s1.clear();		//清空容器
}

//set容器的查找和统计
void test03()
{
	set<int> s1{2,5,3,8,0,3,6};		//构造容器并初始化
	//set容器实际排序 0 2 3 5 6 8
	//查找
	set<int>::iterator pos = s1.find(3);
	if(pos != s1.end())
		cout << "找到该元素：" << *pos << endl;
	else
		cout << "未找到该元素" << endl;
		
 	//统计个数
	int num = s1.count(3);
	if(num == 1)
		cout << "存在该元素 个数为1" << endl;
	else	
		cout << "不存在该元素 " << endl;
		
}

//set和multiset的区别
/*
set不可以插入重复数据，而multiset可以
set插入数据的同时会返回插入结果，表示插入是否成功
multiset不会检测数据，因此可以插入重复数据
*/
void test04()
{
	/*
	cout << "-----------set----------" << endl;
	set<int> s1{2,5};	
	pair<set<int>::iterator, bool> ret = s1.insert(3);
	if(ret.second == true)	//通过ret.second 读取对组里面的第二个值
		cout << "第一次插入成功"<< endl;
	else
		cout << "第一次插入失败"<< endl;
	
	ret = s1.insert(3);
	if(ret.second == true)
		cout << "第二次插入成功"<< endl;
	else
		cout << "第二次插入失败"<< endl;
	*/
	cout << "-----------multiset----------" << endl;
	multiset<int> ms{2,5};
	ms.insert(10);
	ms.insert(10);
	ms.insert(10);
	
	for(multiset<int>::iterator it=ms.begin(); it != ms.end(); it++)
		cout << *it << " ";
	cout << endl;
}

//对组的创建
void test05()
{
	pair<string, int> stu;							//默认构造函数
	pair<string, int> stu1("zhangsan", 22);			//有参构造
	pair<string, int> stu2 = make_pair("lisi", 20);	//使用make_pair函数
	pair<string, int> stu3(stu2); 				//拷贝（复制）构造函数
	
	stu.first = "lihua";
	stu.second = 18;			//对stu对组数据赋值
	stu3.first = "wangwu";		//修改stu3第一个数据，第二个数据拷贝的stu2
	
	//读取对组数据	
	cout << "stu name=  " << stu.first << "\tage= " << stu.second << endl;
	cout << "stu1 name= " << stu1.first << "\tage= " << stu1.second << endl;
	cout << "stu2 name= " << stu2.first << "\t\tage= " << stu2.second << endl;
	cout << "stu3 name= " << stu3.first << "\tage= " << stu3.second << endl;
}

//set容器的排序
//从大到小的排序仿函数
class Myset
{
public:
	bool operator()(int v1, int v2)	//第一个()表重载的符号，第二个()是函数参数列表的括号
	{
		return v1>v2;
	}
};

void test06()
{
	set<int> s1{2,5,3,8,0,3,6};		//构造容器并初始化
	//set容器实际排序 0 2 3 5 6 8
	cout << "---------原s1容器为: ----------" << endl;
	show_set(s1);
	//现在s1已经确定了排序规则，无法再进行更改
	//因此要在容器插入数据之前就设置排序规则	
	//指定排序规则为从大到小 对s2容器起作用
	set<int, Myset> s2{2,5,3,8,0,3,6};		//仿函数本质是个类型
	
	//遍历s2容器
	//s2 容器类型为set<int, Myset>, 所以迭代器类型也为set<int, Myset> 
	cout << "---------新s2容器为: ----------" << endl;
	for(set<int, Myset>::iterator it = s2.begin(); it != s2.end();it++)
		cout << *it << " ";
	cout << endl;
}


//自定义数据类型 Student
class Student{
public:
	Student();		//无参构造
	Student(string name, int age, int score, char sex);		//有参构造 类外实现(略)
	
	string name;
	int age;
	int score;
	char sex;
};

Student::Student(string name, int age, int score, char sex)
{
	this->name = name;
	this->age  = age;
	this->score = score;
	this->sex  = sex;
}

//根据学生成绩从高到低排序的仿函数
class compareStudent
{
public:
	bool operator()(const Student &stu1, const Student &stu2)	//第一个()表重载的符号，第二个()是函数参数列表的括号
	{
		return stu1.score > stu2.score;
	}
};

void test07()
{
	//自定义数据 都要先指定排序规则 编译器不清楚如何排
	set<Student, compareStudent> s1;
	
	//实例化对象
	Student stu1("zhangsan", 22, 80, 'm');
	Student stu2("lisi",     20, 70, 'm'); 
	Student stu3("wangwu",   21, 95, 'm'); 
	Student stu4("chenliu",  22, 86, 'w'); 
	
	//自定义数据存入set容器
	s1.insert(stu1);
	s1.insert(stu2);
	s1.insert(stu3);
	s1.insert(stu4);
	
	//通过迭代器遍历数据
	for(set<Student, compareStudent>::iterator it = s1.begin(); it != s1.end(); it++)
		cout << "姓名: " << it->name << "\t年龄: " << it->age << "\t成绩: " << it->score << endl;
}


int main() {

	test07();

	system("pause");

	return 0;
}
