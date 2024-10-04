#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode() : val(0), next(NULL) {}
	ListNode(int x):val(x),next(NULL){}
	ListNode(int x,ListNode* n):val(x),next(n){}
};

void show_link(struct ListNode *head);
int getLen(struct ListNode *head);

//获取索引为index节点的数据 
int getData(struct ListNode *head, int index) 
{
	int n = getLen(head);
	if(index < 0 || index > n-1)
		return -1;
	ListNode* cur = head;
		 
	while(index)
	{
		cur = cur->next;
		index--;
	} 
	return cur->val;
} 

//头插法 
ListNode * addAtHead(struct ListNode *head,int val)
{
	ListNode* newNode = new ListNode(val);
	newNode->next = head;
	return newNode;
}

//尾插法 
void addAtTail(struct ListNode *head, int val) 
{
	ListNode* newNode = new ListNode(val);	 //定义用来插入的节点 
	ListNode* cur = head;
	while(cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = newNode;
}

//对index节点添加新的节点数据val 
ListNode * addAtIndex(struct ListNode *head, int index, int val) 
{
	struct ListNode* newNode = new ListNode(val);	 //定义用来插入的节点 
	struct ListNode* cur = head;
	int n = getLen(head);
	
	if(index<0 || index>n-1)
		return head;
	else if(index == 0)
	{
		newNode->next = head;
		return newNode;
	}
	else
	{
		while(index-1)
		{
			cur = cur->next;
			index--;
		}
		newNode->next = cur->next;
		cur->next = newNode;
		return head;
	}	
}

//删除index节点的数据
void deleteAtIndex(struct ListNode *head, int index) 
{
	int n = getLen(head);
	struct ListNode* cur = head;
	if(index >= 0 && index < n)
	{
		if(index == 0)
			head = head->next;
		while(index-1)
		{
			cur = cur->next; 
			index--;
		}
		cur->next = cur->next->next;
	}
}



int main()
{
	//MyLinkedList link;
	//vector<int> nums{5,7,7,8,8,10};	// C++ 98 不允许这样 
	int a[] ={1,2,3,4,5};
	vector<int> nums(a,a+sizeof(a)/sizeof(a[0]));
	
	struct ListNode t1(1, NULL);
    struct ListNode t2(2, NULL);
    struct ListNode t3(6, NULL);
    struct ListNode t4(3, NULL);
    struct ListNode t5(4, NULL);
    struct ListNode t6(5, NULL);
    struct ListNode t7(6, NULL);
    t1.next = &t2;
    t2.next = &t3;
    t3.next = &t4;
    t4.next = &t5;
    t5.next = &t6;
    t6.next = &t7;
    
    //int ret = getData(&t1,2);
	//ListNode * ret = addAtHead(&t1,100);
	//addAtTail(&t1,100);
	//ret = s.removeElements(&t1,3);
	//struct ListNode * ret = addAtIndex(&t1,5,200);
	deleteAtIndex(&t1,5);
	show_link(&t1);
	
	return 0;
} 


//打印链表 
void show_link(struct ListNode *head)
{
    struct ListNode *point;
    point = head;
    while(point != NULL)
    {
    	cout <<  point->val << " ";
        point=point->next;
    }
    cout << endl;
}

//计算链表长度 
int getLen(struct ListNode *head)
{
	int cnt = 0;
	struct ListNode *point;
    point = head;
    while(point != NULL)
    {
    	cnt++;
        point=point->next;
    }
    return cnt;
}

