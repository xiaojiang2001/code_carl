#include <bits/stdc++.h>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode():val(0),next(nullptr) {}
	ListNode(int x):val(x),next(nullptr) {}
	ListNode(int x, ListNode* next):val(x),next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) 
{
	ListNode* dummyHead = new ListNode(0);
	dummyHead->next = head;
	
	ListNode* slow = dummyHead;
	ListNode* fast = dummyHead;
	// fast先移动n步
	while(n-- && fast != nullptr){
		fast = fast->next;
	}
	fast = fast->next; // fast再提前走一步，因为需要让slow指向删除节点的上一个节点
	// fast slow同时移动 直到fast移到末尾
	while(fast != nullptr){
		fast = fast->next;
		slow = slow->next;
	}
	ListNode* temp = slow->next;
	slow->next = slow->next->next;
	delete temp;
	
	return dummyHead->next;
}

int main()
{
	
	return 0;
}
