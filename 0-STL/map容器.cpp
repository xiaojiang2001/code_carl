#include <iostream>
#include <map>
#include <string>

using namespace std;

void show_map(map<int, int> &m)
{
	//入口参数检查
	if(m.empty()){
		cout << "容器为空" << endl;
		return;
	}
	
	for(map<int,int>::iterator it = m.begin(); it != m.end();it++)
		cout << "key = " << (*it).first << "\tval = " << it->second << endl;
	cout << endl;
}


void show_str_int_map(map<int, string> &m)
{
	//入口参数检查
	if(m.empty()){
		cout << "容器为空" << endl;
		return;
	}
	
	for(map<int, string>::iterator it = m.begin(); it != m.end();it++)
		cout << "key = " << it->first << "\tval = " << it->second << endl;
	cout << endl;
}


void test01()
{
	//默认无参构造
	map<int, int> map1;		
	//有参构造
	map<int, int> map2{{1003,10},{1001,20},{1002,30}};				
	//有参构造
	map<int, string> stu1{{1,"zhangsan"},{2,"lisi"},{8,"wangwu"},{3,"chenliu"}};	
	//拷贝构造
	map<int, string> stu2(stu1);	
	//区间构造
	map<int, string> stu3(++stu1.begin(), --stu1.end());	//区间 左闭右开
	
	
	//插入数据
	//隐式插入法
	map2.insert(pair<int,int>(1004,67));	
	//显示插入法
	pair<int,int> m1={999,12};	//创建队组 将队组插入map容器
	map2.insert(m1);		
	
	show_map(map2);
	cout << "--------------------" << endl;
	show_str_int_map(stu1);
	cout << "--------------------" << endl;
	show_str_int_map(stu3);
	
	//通过[]访问数据
	cout << "map2 key=1001, val= " << map2[1001] << endl;	
	cout << "stu1 key=1, val= " << stu1[1] << endl;	
}

void test02()
{
	map<int, int> map1{{1,10},{2,20},{3,30}};
	map<int, int> map2{{1,10},{2,20},{5,50},{3,30},{4,40}};			
	
	if(map1.empty() || map2.empty())
		cout << "某容器为空" << endl;
	else
	{
		cout << "容器1的大小:" << map1.size() << endl; 
		cout << "容器2的大小:" << map2.size() << endl; 
		cout << "------交换------" << endl;
		map1.swap(map2);
		cout << "容器1的大小:" << map1.size() << endl; 
		cout << "容器2的大小:" << map2.size() << endl; 
	}	
}

//插入数据
void test03()
{
	map<int, int> map1{{1,10},{2,20},{8,100}};
	map<int, int> map2{{1001,10},{1002,20}};

	//不指定位置 直接添加键值对
	map1.insert(pair<int,int>(4,40));
	map1.insert({5,45});
	map1.insert(make_pair(3,30));
	
	//向容器中添加其他map容器的所有键值对
	map1.insert(map2.begin(),map2.end());
	
	//向map容器中一次性添加多个键值对
	map1.insert({ 
					{100,100}, 
					{101,101} 
				});
	
	show_map(map1);
	
}
//删除数据
void test04()
{
	map<int, int> map1{{1,10},{2,20},{8,100},{5,50}};
	
	show_map(map1);
	cout << "--------------" << endl;
	map1.erase(1);				//删除key为1的键值对	
	map1.erase(--map1.end());	//删除最后一个键值对
	show_map(map1);
	map1.clear();				//清空容器
	cout << "--------------" << endl;
	show_map(map1);
}


//查找和统计
void test05()
{
	map<int, int> map1{{1,10},{2,20},{8,100},{5,50}};
	
	//查找
	map<int, int>::iterator pos = map1.find(2);
	if(pos != map1.end())
		cout << "找到该元素：key =" << pos->first << "\tval = " << pos->second << endl;
	else
		cout << "未找到该元素" << endl;
	
 	//统计个数
	int num = map1.count(2);
	if(num == 1)
		cout << "存在该元素 个数为1" << endl;
	else	
		cout << "不存在该元素 " << endl;
}


//map容器内置数据 从大到小的排序仿函数
class Mycompare
{
public:
	//第一个()表重载的符号，第二个()是函数参数列表的括号
	bool operator()(int v1, int v2)	
	{
		return v1>v2;
	}
};

//内置数据排序
void test06()
{
	map<int, int, greater<int>> map1{{1,45},{2,23},{8,12},{5,1}};
	cout << "map容器降序排序: " << endl;
	//遍历map1 迭代器类型为 map<int, int, Mycompare>
	map<int, int, Mycompare>::iterator it;
	for(it = map1.begin(); it != map1.end();it++)
		cout << "key= " << it->first << "\tval= " << it->second << endl;
	cout << endl;
}


//自定义数据类型 Student
class Student{
public:
	Student();		//无参构造
	Student(string name, int age, int score, char sex);		//有参构造
	
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

class compareStudent
{
public:
	//第一个()表重载的符号，第二个()是函数参数列表的括号
	bool operator()(const Student &stu1, const Student &stu2) const	
	{
		return stu1.score > stu2.score;
	}
};

//自定义数据排序
void test07()
{
	//自定义容器
	map<Student, int, compareStudent> map1;	

	//实例化对象
	Student stu1("zhangsan", 22, 80, 'm');
	Student stu2("lisi",     20, 70, 'm'); 
	Student stu3("wangwu",   21, 95, 'm'); 
	Student stu4("chenliu",  22, 86, 'w'); 
	
	//自定义数据存入set容器
	map1.insert({stu1, 1});
	map1.insert({stu2, 3});
	map1.insert({stu3, 2});
	map1.insert({stu4, 4});
	

	//通过迭代器遍历数据
	map<Student, int, compareStudent>::iterator it;
	for(it = map1.begin(); it != map1.end(); it++)
	{
		cout << "key: "<< it->second << "\tvalue: " << "name: " << it->first.name;
		cout << "\tage: " << it->first.age << "\tscore: " << it->first.score << endl;
	}
		
	//cout << "姓名: " << it->name << "\t年龄: " << it->age << "\t成绩: " << it->score << endl;
}


int main() {

	test06();

	system("pause");

	return 0;
}
