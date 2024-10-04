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

//程序实现不难 重点在于理解指针的实际偏移与2大难点
//1.判断相遇问题
//2.如何求到起始点的距离
//配合视频和图片理解
ListNode *detectCycle(ListNode *head) {
	ListNode *fast = head;
	ListNode *slow = head;
	while(fast!=NULL && fast->next != NULL)
	{
		fast = fast->next->next;	//快指针每次移动2个节点
		slow = slow->next;			//慢指针每次移动1个节点
		if(fast == slow)			//快慢指针相遇 有环
		{
			//定义两个指针 一个在相遇点 一个在头, 一起偏移，在环起点相遇
			//结合视频和图片理解  x = (n - 1) (y + z) + z 
			//index1 走 (n-1)(y+z) + z的距离，index2走 x 的距离
			ListNode *index1 = fast;
			ListNode *index2 = heas;
			while(index1 != index2)
			{
				index1 = index1->next;	//俩指针一起走 指直到在环起点相遇
				index2 = index2->next;
			}	
			return index1;
		}
	}
	return NULL;
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

