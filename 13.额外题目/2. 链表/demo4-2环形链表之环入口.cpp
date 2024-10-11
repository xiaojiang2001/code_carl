#include <bits/stdc++.h>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode():val(0),next(nullptr) {}
	ListNode(int x):val(x),next(nullptr) {}
	ListNode(int x, ListNode* next):val(x),next(next) {}
};
//查找相遇点
ListNode *judgeLoop(ListNode *head)
{
	ListNode* fast = head;
	ListNode* slow = head;
	while(fast && fast->next){
		slow = slow->next;
		
		if(fast == slow){
			return fast;
		}
	}
	return nullptr;
}

ListNode *detectCycle(ListNode *head) 
{
	//获取相遇点
	ListNode *meet = judgeLoop(head);	
	if(meet == nullptr){
		return nullptr;
	}
	
	//从头 和 相遇点往环入口走
	ListNode* cur1 = head;		// 从头开始往环的入口走
	ListNode* cur2 = meet;		// 从相遇点开始向入口走
	while(cur1 != cur2){
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return cur1;
}


int main()
{
	return 0;
}
