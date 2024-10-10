#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode():val(0),next(nullptr) {}
	ListNode(int x):val(x),next(nullptr) {}
	ListNode(int x, ListNode* next):val(x),next(next) {}
};


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
	// 计算两根链表的长度
	ListNode* curA = headA;
	ListNode* curB = headB;
	int lenA = 0;
	int lenB = 0;
	while(curA){
		lenA++;
		curA = curA->next;
	}
	while(curB){
		lenB++;
		curB = curB->next;
	}
	
	//保证链表A更长
	if(lenB > lenA){
		swap(headA,headB);
		swap(lenA,lenB);
	}
	
	curA = headA;
	curB = headB;
	int gap = lenA - lenB;
	// 移动A 使A B 链表尾对齐
	while(gap--){
		curA = curA->next;
	}
	
	//尾对齐 还需要遍历 不是尾对齐就相交啊
	//同时遍历A B链表
	while(curA){
		//相交则返回交点节点 
		if(curA == curB){
			return curA;
		}
		curA = curA->next;
		curB = curB->next;
	}
	//不相交
	return nullptr;
}



int main()
{
	
	return 0;
}
