#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX_TABLE 11

//单链表的节点结构
struct ListNode{
	int val; 
	ListNode* next;
	ListNode():val(0),next(NULL) {}
	ListNode(int x) : val(x), next(NULL) {}
};

class Hash_Table
{
public:
	Hash_Table(){}
	~Hash_Table();
	
	void insert(int val);	//数据添加
	ListNode* serach(int val);	//数据查找
private:
	ListNode head[MAX_TABLE];
};

//销毁head链表中的全部节点
static void clear_ListNode(ListNode* head)
{
	ListNode* ptr = new ListNode();	//遍历节点
	ptr = head->next;		//遍历
	while(ptr)
	{
		ListNode* del = ptr;	//备份待释放的节点
		ptr = ptr->next;		//pt指向下一个节点
		delete del;				//释放del节点的空间
	}
	head->next = NULL;			//将头节点的next指向空
}


Hash_Table::~Hash_Table()	//析构 各个单链表
{
	int i;
	for(i = 0; i < MAX_TABLE; i++)
		clear_ListNode(&head[i]);	//调用clear_ListNode函数，遍历释放每个单链表
}


//哈希函数
static int hash_func(int key)
{
	return key % MAX_TABLE;
}

void Hash_Table::insert(int key)
{
	ListNode *node = new ListNode(key);	//创建一个新节点
	int hash = hash_func(key);			//获取哈希表下标 index 或 称为 key hash
	
	//链表头插法
	node->next = head[hash].next;
	head[hash].next = node;
}


ListNode* Hash_Table::serach(int key)
{
	int hash = hash_func(key);		//计算哈希值
	//找到hash对应的链表 head-hash 将指针指向他的第一个节点
	ListNode* head = this->head[hash].next;
	ListNode* ptr = head;		//定义遍历节点变量 也可以直接用head
	while(ptr != NULL)	
	{
		if(ptr->val == key)	//当前节点的val和key值相等
		{
			return ptr;
		}
		ptr = ptr->next;		//指针遍历
	}
	return NULL;			//不存在key
}

int main()
{
	Hash_Table table;
	ListNode* ret;
	
	table.insert(10);
	table.insert(6);
	table.insert(7);
	table.insert(13);
	table.insert(8);
	
	ret = table.serach(6);
	
	if(ret != NULL)
		cout << "key in table, val= " << ret->val << endl;
	else
		cout << "key not in table"  << endl;
		
	return 0;
} 


