#include <iostream>
#include <vector>

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
	// 数组模拟 + 数组优化长度
	bool isPalindrome(ListNode* head) 
	{
		// 先求出链表长度，然后给定vector的初始长度
		// 这样避免vector每次添加节点重新开辟空间
		int len = 0;
		ListNode *cur = head;
		while(cur)
		{
			cur = cur->next;
			len++;
		}
		cout << "len: " << len << endl;
		
		vector<int> vec(len);
		int i = 0;
		cur = head;
		while(cur)
		{
			vec[i++] = cur->val;
			cur = cur->next;
		}
		
		for(int num:vec)
			cout << num << endl;
		
		i = 0;
		int j = vec.size() - 1;
		while(i < j){
			if(vec[i++] != vec[j--]){
				return false;
			}
		}
		return true;
	}
	
	
	// 反转后半部分链表
	// 反转链表
	ListNode * reverse(ListNode *head)
	{
		ListNode *cur = head;
		ListNode *pre = nullptr;
		
		while(cur)
		{
			ListNode *temp = cur->next;
			cur->next = pre;
			
			pre = cur;
			cur = temp;
		}
		
		return pre;
	}
	
	bool isPalindrome2(ListNode* head)
	{
		ListNode* fast = head;
		ListNode* slow = head;
		ListNode* pre = head;
		
		while(fast && fast->next){
			pre = slow;
			fast = fast->next->next;	// 快指针遍历到尾
			slow = slow->next;			// 慢指针遍历到中间
		}
		//构造 cur1
		ListNode* cur1 = head;
		pre->next = nullptr;
		
		//构造 cur2
		ListNode* cur2 = reverse(slow);
		
		while(cur1){
			if(cur1->val != cur2->val){
				return false;
			}
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return true;
	}
	
};

int main()
{
	
	
	
	return 0;
}
