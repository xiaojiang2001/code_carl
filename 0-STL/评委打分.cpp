#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <ctime>
using namespace std;

/*
有5名选手：选手ABCDE，10个评委分别对每一名选手打分，
去除最高分，去除评委中最低分，取平均分。
*/


class Person
{
public:
	//构造函数
	Person(string name, float score){
		this->name = name;
		this->score = score;
	}
	
	float score;	//平均分
	string name;	//姓名
};




void show_person(vector<Person> &v)
{
	for(vector<Person>::iterator it = v.begin();it<v.end();it++)
		cout << "name: " << it->name << "\tscore: " << it->score << endl;
}

void create_person(vector<Person> &v)
{
	string nameSeed = "ABCDE";
	for(int i = 0; i < 5; i++)
	{
		//初始化选手信息
		string name = "选手";
		name += nameSeed[i];
		float score = 0;
		
		//实例化选手对象
		Person p(name,score);	
		//将创建的选手对象存入容器
		v.push_back(p);			
	}
}

void set_score(vector<Person> &v)
{
	for(vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//将评委的分数 放入deque容器
		deque<int> d;
		for(int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;	//随机打分[60-100] 
			d.push_back(score);				//10个评委打分存入deque容器
		}
		//对打分进行排序
		sort(d.begin(),d.end());
		
		//去除最高分与最低分
		//deque有现成的去除第一个和最后一个数据的方法
		d.pop_front();
		d.pop_back();
		
		//取平均分
		int sum = 0;
		for(deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
			sum += *dit;
			
		it->score = (float)sum / d.size();
	}
}
int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));
	
	//1. 创建5名选手 存入容器
	vector<Person> v;
	create_person(v);
	
	//show_person(v);	//测试是否创建成功
	//2. 给5名算手打分
	set_score(v);
	
	//3. 显示最后得分
	show_person(v);	
		
	system("pause");

	return 0;
}
