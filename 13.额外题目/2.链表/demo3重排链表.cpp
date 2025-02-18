#include <iostream>
#include <vector>
#include <deque>

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
/*
	// 方法一 数组模拟 节点存入容器 双指针 拼接
	void reorderList(ListNode* head) {
		if(head == nullptr)
			return;
		//节点存入容器
		vector<ListNode*> vec;
		ListNode* cur = head;
		while(cur){
			vec.push_back(cur);
			cur = cur->next;
		}
		//初始化
		cur = head;
		int i = 1; 
		int j = vec.size() - 1;
		int conut = 0;
		while(i <= j){
			if(conut % 2 == 0){
				cur->next = vec[j];
				j--;
			}
			else{
				cur->next = vec[i];
				i++;
			}
			cur = cur ->next;
			conut++;
		}
		cur->next = nullptr;	 //注意结尾
	}
*/
/*
	// 方法二 双向队列 拼接
	void reorderList(ListNode* head)
	{
		//节点顺序入队 1 2 3 4 5
		deque<ListNode*> que;
		ListNode* cur = head;
		while(cur){
			que.push_back(cur);
			cur = cur->next;
		}
		//初始化并把头弹出
		cur = head;
		que.pop_front();
		
		//拼接链表
		int count = 0;		//计数 偶数去后面 奇数去前面
		while(que.size())
		{
			//偶数去后面
			if(count % 2 == 0){
				cur->next = que.back();
				que.pop_back();
			}
			// 奇数去前面
			else{
				cur->next = que.front();
				que.pop_front();
			}
			cur = cur -> next;
			count++;
		}
		cur->next = nullptr;
	}
*/
	// 方法三 分割链表 翻转 拼接
	//翻转链表
	ListNode* reverse(ListNode* head)
	{
		ListNode* cur = head;
		ListNode* pre = nullptr;
		while(cur){
			ListNode* temp = cur->next;
			cur->next = pre;	// 改变方向
			// 指针偏移
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
