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


struct ListNode* swapPairs(struct ListNode* head) 
{
    ListNode* dummyHead = new ListNode(0);
    
    dummyHead->next = head;
    struct ListNode* cur = dummyHead;
    //结合代码随想录图理解  
    while(cur->next != NULL && cur->next->next != NULL)
    {
    	ListNode* temp1 = cur->next->next;	// 步骤一的目标节点 
    	ListNode* temp2 = cur->next;		// 步骤二的目标节点 
    	ListNode* temp3 = cur->next->next->next;	// 步骤三的目标节点 
    	
    	cur->next = temp1;				//步骤一 
    	cur->next->next = temp2;		//步骤二 
    	cur->next->next->next = temp3;	//步骤三 
    	
    	cur = cur->next->next;			// cur移动两位，准备下一轮交换
	}
	return dummyHead->next; 	//返回交换后的目标节点 
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
    struct ListNode t7(6, NULL);
    t1.next = &t2;
    t2.next = &t3;
    t3.next = &t4;
    t4.next = &t5;
    t5.next = &t6;
    t6.next = &t7;
    show_link(&t1);
    cout << "----------------------" << endl;
    ListNode* newLink = swapPairs(&t1); 
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

