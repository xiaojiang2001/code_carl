#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode():val(0),next(nullptr) {}
	ListNode(int x):val(x),next(nullptr) {}
	ListNode(int x, ListNode* next):val(x),next(next) {}
};


bool hasCycle(ListNode *head) 
{
	ListNode *fast = head;
	ListNode *slow = head;
	while(fast != nullptr && fast->next != nullptr){
		fast = fast->next->next;
		slow = slow->next;
		if(slow == fast){
			return true;
		}
	}
	return false;
}



int main()
{
	
}
