#include <iostream>
#include <string>
#include <string.h>

using namespace std;


//string是C++风格的字符串，而string本质上是一个类
void test01()		//字符串初始化与赋值
{
	string s1;
	string s2="hello world ";
	const char *str = "hello C++ ";
	
	s1 = s2;
	string s3(str);
	
	cout << "s1= " << s1 << endl;
	cout << "s2= " << s2 << endl;
	cout << "s3= " << s3 << endl;
	
	string s4;
	s4.assign(str,5);			//将str的前5个赋值给s4，第一个参数必须为常量
	cout << "s4= " << s4 << endl;
	
	
	//字符串拼接
	string ss;
	ss = s1 + s2;
	cout << "ss= " << ss << endl;
	ss.append(s3);
	cout << "ss= " << ss << endl;
	cout << "------" << endl;
	ss.append(str, 6, 3); 		// 从下标4位置开始 ，截取3个字符，拼接到字符串末尾
	cout << "ss= " << ss << endl;
}


//查找替换
void test02()		
{
	//查找
	//find查找是从左往后，rfind从右往左
	//find找到字符串后返回查找的第一个字符位置，找不到返回-1
	
	string str1 = "abcdefgde";

	int pos = str1.find("de");		// pos = 3
	
	if (pos == -1){
		cout << "未找到" << endl;
	}
	else{
		cout << "pos = " << pos << endl;
	}
	
	pos = str1.rfind("de");		//pos = 7
	cout << "pos = " << pos << endl;
	
	//替换
	//指定从哪个位置起，多少个字符，替换成什么样的字符串
	str1.replace(1, 3, "1111 ");		// str = a1111 efgde
	cout << "str1 = " << str1 << endl;

}


//字符串比较 规则同C语言
void test03()		
{
	//  前者和后者比:  = 返回 0    > 返回 正数   < 返回 负数 		精确而言:返回的是两个ASSIC的差值
	string s1 = "aello";
	string s2 = "cello";

	int ret = s1.compare(s2);    //s1 和 s2 比
	//ret = s2.compare(s1);		 //s2 和 s1 比  两种比较值刚好相反
 	cout << ret << endl;
	
}


//string字符串中单个字符存取有两种方式，利用 [ ] 或 at  
//[]相当于看成字符串char *，数组,  at是str的方法，面向对象思路
void test04()		// string字符存取
{
	string str = "hello";
	int len = str.size();		//字符串通过size()方法获取自身长度
	
	for (int i = 0; i < len; i++)	
	{
		cout << str[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < len; i++)
	{
		cout << str.at(i) << " ";
	}
	cout << endl;


	//字符修改
	str[0] = 'x';
	str.at(1) = 'x';
	cout << str << endl;
	
}


//string插入和删除 这是两个方法
void test05()	
{
	string str = "hello";
	str.insert(1, "111");
	cout << str << endl;		//h111ello

	str.erase(1, 3);  //从1号位置开始3个字符
	cout << str << endl;		//hello
}


//string子串, 从字符串中获取想要的子串
void test06()		
{
	string str = "abcdefg";
	string subStr = str.substr(1, 3);	//bcd
	cout << "subStr = " << subStr << endl;

	string email = "hello@sina.com";
	int pos = email.find("@");	//pos = 5
	string user = email.substr(0, pos);
	cout << "user: " << user << endl;	// hello

	string addr = email.substr(pos, -1);//-1默认表到尾巴
	cout << "addr: " << addr << endl;	// @sina.com

}
int main()
{
//	test01();		//初始化与赋值
//	test02();		//查找与替换	方法: find(str), rfind(str), replace(begin, end, str) 
//	test03();		//两个比较	通C
//	test04();		//字符存取	数组:[index]  方法: at(index)
//	test05();		//插入和删除  方法: insert(index, str), erase(index, len)
	test06();		//从串中获取子串  方法:substr(index, len)
	
	
	
	return 0;
	
}