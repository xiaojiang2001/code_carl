#include <iostream>
#include <map>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

void show_deque(deque<int> &d)
{
	//入口参数检查
	if(d.empty()){
		cout << "容器为空" << endl;
		return;
	}
	
	for(deque<int>::iterator it = d.begin(); it != d.end();it++)
		cout << *it << " ";
	cout << endl;
}



void test01()
{
	//默认无参构造
	deque<int> d1;		
	//有参构造
	deque<int> d2{10,20,30,40,50};	//初始化数据		
	deque<int> d3(5,6);			//10 个 5
	
	//尾插
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	
	//头插
	d1.push_front(5);
	d1.push_front(4);
	d1.push_front(3);
	
	//指定位置插入
	d1.insert(++d1.begin(),100);
	show_deque(d1);
	
	//删除一个元素 erase的参数是迭代器
	d1.erase(d1.begin());
	d1.erase(--d1.end());
	show_deque(d1);
		
}
void test02()
{
	
	deque<int> d;
	//插入数据
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);

	//遍历数据
	for (int i = 0; i < d.size(); i++) {
		cout << d[i] << " ";
	}
	cout << endl;
	
	
	sort(d.begin(), d.end());
	
	show_deque(d);
	
}

int main() {

	//test01();
	test02();
	
	system("pause");

	return 0;
}
