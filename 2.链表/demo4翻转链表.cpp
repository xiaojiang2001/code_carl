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


//递归实现 晦涩难懂 参照双指针编写 
struct ListNode* reverseListC(struct ListNode* pre, struct ListNode* cur) 
{
	if(cur == NULL)	
		return pre;
		
	ListNode* temp = cur->next;
	cur->next = pre;
	// 可以和双指针法的代码进行对比，如下递归的写法，其实就是做了这两步
    // pre = cur;
    // cur = temp;
	return reverseListC(cur,temp);
}


//双指针 更易理解 
ListNode* reverseList(ListNode* head) 
{
	ListNode* cur = head;
	ListNode* pre = NULL;	//翻转后的尾节点为NULl 
	ListNode* temp = NULL;
	while(cur != NULL)
	{
		temp = cur->next;	//暂存cur的下个节点 使得cur可以往右偏移 
		cur->next = pre;	//翻转链表方向 
		pre = cur;			//pre指针右移 
		cur = temp;			//cur指针右移 
	}
	return pre;
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
    show_link(&t1);
    cout << "----------------------" << endl;
    ListNode* newLink = reverseListC(NULL,&t1); 
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

