#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
/*
int get(int index) 
void addAtHead(int val) 
void addAtTail(int val) 
void addAtIndex(int index, int val) 
void deleteAtIndex(int index) 
*/
class MyLinkedList {
public:	
	//定义链表结构体 
	struct ListNode{
		int val;
		ListNode* next;
		ListNode(int x):val(x),next(NULL){}
	};
	
	ListNode* dummyHead;
	int size;

	//构造函数  初始化 MyLinkedList 对象 
	MyLinkedList() {
		dummyHead = new ListNode(0);	//定义虚拟头节点
		ListNode* node1 = new ListNode(12);
		ListNode* node2 = new ListNode(44);
		dummyHead->next = node1;
		node1->next = node2;
		size = 2; 
    }
    
    //头插法 
    void addAtHead(int val) 
	{ 
		ListNode* newNode = new ListNode(val);	//创建新节点变量
		//将新节点变量存入链表  
		newNode->next = dummyHead->next;
		dummyHead->next = newNode;				
		size++;
	} 
    
    //尾插法 
    void addAtTail(int val) 
    {
    	ListNode* newNode = new ListNode(val);	//创建新节点 
    	ListNode* cur =  dummyHead;		//创建遍历节点变量 
    	while(cur->next != NULL)	//遍历链表 
    	{
    		cur = cur->next;				
		}
		cur->next = newNode;	//将新节点添加至链表
		size++;		
	} 
	
	//获取索引为index的数据 
	int get(int index) 
	{
		if(index < 0 || index > size-1)
			return -1;
		ListNode* cur = dummyHead->next;	 //定义用来遍历的节点
		while(index--)
		{
			cur = cur->next;
		} 
		return cur->val;
	} 
	
	//在特定位置index 插入数据val 
	void addAtIndex(int index, int val) 
	{
		if(index > size || index < 0)	
			return ;
		ListNode* newNode = new ListNode(val);	//创建插入的新节点 
		ListNode* cur = dummyHead;	 			//定义用来遍历节点的变量指针 
		while(index--)
		{
			cur = cur->next;
		}
		newNode->next = cur->next;
		cur->next = newNode;
		size++;
	}
	
	//删除索引为index的节点 
	void deleteAtIndex(int index) 
	{
		if(index > size-1 || size < 0)
			return; 
		ListNode* cur = dummyHead;	 	//定义用来遍历节点的变量指针 
		while(index--)
		{
			cur = cur->next;
		}
		ListNode* temp = cur->next; 
		cur->next = cur->next->next;
		delete temp;
		//delete命令指示释放了tmp指针原本所指的那部分内存，
        //被delete后的指针tmp的值（地址）并非就是NULL，而是随机值。也就是被delete后，
        //如果不再加上一句tmp=nullptr,tmp会成为乱指的野指针
        //如果之后的程序不小心使用了tmp，会指向难以预想的内存空间
        temp = NULL;
		size--;
	}
	
	void showLink()
	{
        ListNode *point = dummyHead->next;
        while(point != NULL)
        {
        	cout <<  point->val << " ";
            point=point->next;
        }
        cout << endl;
	}
};

int main()
{
	//vector<int> nums{5,7,7,8,8,10};	// C++ 98 不允许这样 
	int a[] ={1,2,3,4,5};
	vector<int> nums(a,a+sizeof(a)/sizeof(a[0]));
	
	MyLinkedList* obj = new MyLinkedList();
	obj->addAtHead(0);
	obj->addAtTail(96); 
	obj->showLink();
	int param_1 = obj->get(2);
	cout << "index =2; val=:" <<  param_1 << endl;
	obj->addAtIndex(0,66);
	obj->showLink();
	obj->deleteAtIndex(0);
	obj->showLink();
	
	return 0;
} 
