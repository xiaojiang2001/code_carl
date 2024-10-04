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

ListNode* removeElements(ListNode* head, int val) 
{  
	//分删除头节点和非头节点
	//注意这里不是if 是要遍历开头一样要删除的数字 如Node: 1 1 1 val: 1
	while(head != NULL && head->val == val)        //删除头节点
	{
	  ListNode* tmp = head;   //暂存头节点
	  head = head->next;      //头节点指向下个节点
	  delete tmp;             //删除暂存的头节点
	}
	ListNode* current = head;
	
	while(current != NULL && current->next != NULL)
	{
		//cout << current->val << endl;
	  if(current->next->val == val){
	    ListNode* tmp = current->next;        //暂存要删除的节点（下个节点）
	    current->next = current->next->next;  //删除下个节点 即下个节点为为下下个节点
	    delete tmp;                           //删除暂存的下个节点
	  }
	  else{
	    current = current->next;
	  }
	}
	return head;


/* 
//设置虚拟头节点
		ListNode* dummyHead = new ListNode(0);	//定义一个虚拟头节点 
		dummyHead->next = head;					//虚拟头节点的下一个指向真正的头节点
		ListNode* cur = dummyHead;				//定义遍历节点 思考为什么为 dummyHead
		
		while(cur->next != NULL)
		{
			//cout << cur->val << endl;
			if(cur->next->val == val){
				ListNode* tmp = cur->next;
				cur->next = cur->next->next;
				delete tmp;
			}
			else
				cur = cur->next;
		}
		head =  dummyHead->next;
		delete dummyHead;
        return head;
*/
} 




int main()
{
	struct ListNode t1(1, NULL);
    struct ListNode t2(1, NULL);
    struct ListNode t3(1, NULL);
    struct ListNode t4(4, NULL);
    struct ListNode t5(5, NULL);
    struct ListNode t6(6, NULL);
    struct ListNode t7(7, NULL);
    t1.next = &t2;
    t2.next = &t3;
    t3.next = &t4;
    t4.next = &t5;
    t5.next = &t6;
    t6.next = &t7;
    
    ListNode * ret = removeElements(&t1,6);
	show_link(ret);
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

