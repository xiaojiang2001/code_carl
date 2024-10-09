#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode():val(0),next(nullptr) {}
	ListNode(int x):val(x),next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode* dummyHead = new ListNode(0);	//设置一个空的虚拟头节点
		dummyHead->next = head;
		ListNode* cur = dummyHead;
		
		while(cur->next != nullptr && cur->next->next != nullptr)
		{
			ListNode* temp1 = cur->next->next;			//步骤一目标节点
			ListNode* temp2 = cur->next;				//步骤二目标节点
			ListNode* temp3 = cur->next->next->next;	//步骤二目标节点
			
			cur->next = temp1;							// 步骤一
			cur->next->next = temp2;					// 步骤二
			cur->next->next->next = temp3;				// 步骤三
			
			
			cur = cur->next->next;		// cur移动两位，准备下一轮交换
		}
		return dummyHead->next;
	}
};

int main()
{
	
	
	
	return 0;
}
