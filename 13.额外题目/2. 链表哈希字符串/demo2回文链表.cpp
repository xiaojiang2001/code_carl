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
};

int main()
{
	
	
	
	return 0;
}
