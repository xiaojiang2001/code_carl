#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode():val(0), next(nullptr) {}
	ListNode(int x):val(x), next(nullptr) {}
	ListNode(int x, ListNode * next):val(0), next(next) {}
};

ListNode* creat(void)
{
	ListNode *newNode = new ListNode();
	return newNode;
}

void show_link(ListNode* head)
{
	if(head == nullptr){
		cout << " show error: head is nullptr" << endl;
	}
	
	while(head)
	{
		cout << head->val << " ";
		head = head->next;
	}
}

void push_back(ListNode* head, int val)
{
	if(head == nullptr){
		cout << " show error: head is nullptr" << endl;
	}
	
	//构造新节点
	ListNode *newNode = new ListNode(val);
	
	//遍历节点
	while(head->next != nullptr)
	{	
		head = head ->next;
	}
	head->next = newNode;
}

void insert_front(ListNode* head, int val)
{
	//构造新节点
	ListNode *newNode = new ListNode(val);
	
	if(head == nullptr){
		head = newNode;
	}
	
	//插入新节点
	newNode->next = head->next;
	head->next = newNode;
}


void insert(ListNode* head, int val, int idx)
{
	if(head == nullptr){
		cout << " show error: head is nullptr" << endl;
	}
	
	//构造新节点
	ListNode *newNode = new ListNode(val);
	for(int i = 0; i < idx; i++)
	{
		head = head ->next;
	}
	
	newNode->next = head->next;
	head->next = newNode;
}


int main()
{
	ListNode *head = creat();

	
	push_back(head,1);
	push_back(head,2);
	//push_back(head,3);
//	cout << head->val << endl;
//	cout << head->next->val << endl;
	
	ListNode* newHead = removeNthFromEnd(head->next,2);
	show_link(newHead);
	
	return 0;
}
