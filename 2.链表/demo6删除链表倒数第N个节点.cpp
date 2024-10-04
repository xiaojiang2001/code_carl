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


//1. 将两链表尾对齐(将长的链表移动长度差个单位，使其尾对齐)
//2. 同时移动，判断是否存在一样的节点 (即相交节点) 
ListNode* getIntersectionNode(ListNode* head, int n) 
{
	
    
    //1.先让快指针移动n+1步
	while(n+1 && fast != NULL)
	{
		fast = fast->next;
		n--;
	} 
	
	//2.快慢指针同时移动 当快指针移到尾 慢指针在需要删除的前一个节点
    while(fast != NULL)
    {
    	fast = fast->next;
    	slow = slow->next;
	}
	
	//3. 开始移除  C++释放内存的逻辑 释放内存似乎会卡死 
	//ListNode* temp = slow->next;
	slow->next = slow->next->next;
	//delete temp;
	
	//4.返回新链表的节点 
	return dummyHead->next; 
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
    ListNode* newLink = removeNthFromEnd(&t1,2); 
    show_link(newLink);
	
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

