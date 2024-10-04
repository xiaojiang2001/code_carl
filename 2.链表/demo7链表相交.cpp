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


//1. 将两链表尾对齐(将长的链表移动长度差个单位，使其尾对齐)
//2. 同时移动，判断是否存在一样的节点 (即相交节点) 
ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) 
{
    ListNode *curA = headA;
	ListNode *curB = headB;
	//计算链表长度 
	int lenA = getLen(headA);
	int lenB = getLen(headB);
	//保证A链表长于B链表 
	if(lenB > lenA)
	{
		swap(lenA,lenB);
		swap(curA,curB);	
	}	 
	int gap = lenA - lenB;	//计算差值 
	//移动A 使A B 链表尾对齐 
	while(gap--)
	{
		curA = curA->next;
	}
	
	//同时遍历A B链表 
	while(curA != NULL)
	{
		if(curA== curB) 	//相交则返回交点节点 
			return curA;
		curA = curA->next;
		curB = curB->next;
	} 
	  
	return NULL; 	//不相交 
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
    struct ListNode t6(6, NULL);
    struct ListNode t7(7, NULL);
    t1.next = &t2;
    t2.next = &t3;
    t3.next = &t4;
    t4.next = &t5;
    t5.next = &t6;
    t6.next = &t7;
    show_link(&t1);
    cout << "----------------------" << endl;
    //ListNode* newLink = removeNthFromEnd(&t1,2); 
    //show_link(newLink);
	
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
    while(head != NULL)
    {
    	cnt++;
        head = head->next;
    }
    return cnt;
}

