#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

typedef int data_t;

//结点定义
typedef struct node{
	data_t data;		//结点数据域
	struct node *next;	//结点后继指针域
}listNode;

/*****************链表基础功能函数声明*******************/
listNode* link_create();						// 建立一个空链表
int link_show(listNode* head)					// 显示链表数据
listNode* link_free(listNode* head)				// 释放链表内存空间

/*****************链表增删改查函数声明*******************/
int link_push_back(listNode* head, data_t value);	// 链表尾插法
int link_push_front(listNode* head, data_t value);	// 链表头插法
int link_insert(listNode* head, data_t value, int index)//在链表特定位置插入一个元素
int link_getVal(listNode* head, int index)			// 查找某个下标的值
int link_search(listNode* head, data_t val)			// 查找某个元素的下标索引
int link_delete_val(listNode* head, int val)		//根据数据值 删除某个节点
int link_delete_index(listNode* head, int index)//根据索引 删除某个节点 (链表其实无索引，即第几个节点-1)

/******************链表的复杂操作函数声明****************/
int link_reverse(listNode* head)						//单链表的反转
listNode *list_adjmax(listNode *head, data_t *value)	//求相邻节点最大值，返回最大值第一个节点地址
int link_merge(listNode *head1, listNode *head2)		//合并两个链表，合并至head1
int link_sort(listNode *head )							//链表的排序
int link_purge(listNode *head)							//删除有序链表中重复元素



/********************函数实现*******************/	
/*
功能：创建一个空链表  node为虚拟头节点
参数：void
返回值：头节点地址
*/
listNode* link_create()
{
	//申请内存空间
	listNode* node = (listNode *)malloc(sizeof(listNode));
	if(node == NULL){
		printf("link_create: malloc error\n");
		return NULL;
	}
	
	//链表成员变量赋值
	node->data = 0;
	node->next = NULL;
	
	//返回链表地址
	return node;
}

/*
功能：链表尾插法插入数据
参数：para1；   链表头    para2；插入的数据
返回值：成功返回0;    失败返回-1
*/
int link_push_back(listNode* head, data_t value)
{
	//入口参数检查
	if(head == NULL)
		return -1;
		
	//封装节点
	listNode *node = (listNode *)malloc(sizeof(listNode));
	if(node == NULL){
		printf("link_push_back malloc error\n");
		return -1;
	}
	//新节点赋值
	node->data = value;
	node->next = NULL;
	
	//遍历链表 
	while(head->next != NULL)
	{
		head = head->next;
	}
	
	//尾插入节点
	head->next = node;
	
	return 0;
}

/*
功能：链表头插法插入数据
参数：para1；   链表头    para2；插入的数据
返回值：成功返回0;    失败返回-1
*/
int link_push_front(listNode* head, data_t value)
{
	//入口参数检查
	if(head == NULL)
		return -1;
			
	//封装节点
	listNode* node = (listNode *)malloc(sizeof(listNode));
	if(node == NULL){
		printf("link_push_front malloc error\n");
		return -1;
	}
	
	//头插法
	node->data = value;			//插入行节点数据
	node->next = head->next;	//将新节点连接到原来的头
	head->next = node;			//更新链表头
	
	return 0;
}

/*
功能：显示链表数据
参数：para： 链表头   
返回值：成功返回0;    失败返回-1
*/
int link_show(listNode* head)
{
	//入口参数检查
	if(head == NULL)
		return -1;
	
	//遍历链表 
	while(head->next != NULL)
	{
		printf("%d ", head->next->data);
		head = head->next;
	}
	printf("\n");
	return 0;
}

/*
功能：释放链表内存空间
参数：para :链表头          
返回值： NULL
*/
listNode* link_free(listNode* head)
{
	//入口参数检查
	if(head == NULL){
		printf("list_insert: para error\n");
		return NULL;
	}
	
	//封装临时节点
	listNode *temp = head;
	while(head != NULL)
	{
		temp = head;
		//printf("free: %d\n", head->data);
		//这两行不能反 必须先指向下一个再释放当前地址
		head = head->next;	
		free(temp);
	}
	
	return NULL;
}

/*
功能：查找某个下标的值
参数：para1:链表头	para2:查找的某个下标
返回值： 失败返回-1    成功返回对应下标的元素值
*/
int link_getVal(listNode* head, int index)
{
	//入口参数检查
	if(head == NULL || index < 0){
		printf("list_insert: para error\n");
		return -1;
	}
	
	//遍历到目标索引处
	int pos = -1;
	while(pos < index && head->next != NULL)
	{
		pos++; 
		head = head->next;
	}
	
	//索引过大
	if(head->next == NULL && index - pos > 0){
		printf("index invalid\n");
		return -1;
	}
	
	return head->data;	
}

/*
功能：查找某个元素的下标索引
参数：para1:链表头	para2:查找的某个元素值
返回值： 失败返回-1    成功返回元素的下标索引
*/
int link_search(listNode* head, data_t val)
{
	//入口参数检查
	if(head == NULL){
		printf("list_insert: para error\n");
		return -1;
	}
	
	//pos 记录下标位置
	int pos = -1;
	while(head->next != NULL)
	{
		pos++;
		if(head->next->data == val)	//判断是否存在val
			return pos;
		head = head->next;
	}
	return -1;
}

/*
功能：在链表特定位置插入一个元素
参数：	para1:链表头	para2:插入的元素值	para3:特定位置的索引
返回值： 失败返回-1    成功返回0
*/
int link_insert(listNode* head, data_t value, int index)
{
	//入口参数检查
	if(head == NULL || index < 0){
		printf("list_insert: para error\n");
		return -1;
	}
	//封装节点
	listNode* node = (listNode *)malloc(sizeof(listNode));
	if(node == NULL){
		printf("link_push_front malloc error\n");
		return -1;
	}
	node->data = value;
	
	//遍历到目标索引处
	int pos = 0;
	while(pos < index && head->next != NULL)
	{
		pos++; 
		head = head->next;
	}
	
	//索引过大
	if(head->next == NULL && index - pos > 0){
		printf("index invalid\n");
		return -1;
	}
	
	//插入数据
	node->next = head->next;
	head->next = node;
	
	return 0;
}


/*
功能：根据数据值 删除某个节点
参数：	para1:链表头	para2:删除数值
返回值： 失败返回-1    成功返回0
*/
int link_delete_val(listNode* head, int val)
{
	//入口参数检查
	if(head == NULL){
		printf("list_insert: para error\n");
		return -1;
	}
	
	//遍历链表
	while(head->next != NULL && head->next->data != val)
	{
		head = head->next;
	}
	
	//链表中无该数据
	if(head->next == NULL && head->data != val){
		printf("no such value\n");
		return -1;	
	}
	
	listNode *temp = head->next;	//暂存需释放空间的节点
	head->next = head->next->next;	//跳跃拉链，即删除了中间节点
	free(temp);						//释放节点
	temp = NULL;					//避免野指针
	
	return 0;	
}

/*
功能：根据索引 删除某个节点 (链表其实没有所谓的索引，即第几个节点-1)
参数：	para1:链表头	para2:删除的索引
返回值： 失败返回-1    成功返回0
*/
int link_delete_index(listNode* head, int index)
{
	//入口参数检查
	if(head == NULL || index < 0){
		printf("list_insert: para error\n");
		return -1;
	}
	
	//遍历链表
	int pos = 0;
	while(pos < index && head != NULL)
	{
		//节点遍历完了
		if(head->next == NULL){	
			printf("index error\n");
			return -1;
		}
		pos++;					//索引
		head = head->next;		//指针偏移
	}
	//printf("data: %d\n", head->data);
	
	if(head->next == NULL)
	{
		printf("list_insert: para error\n");
		return -1;
	}
	
	
	listNode *temp = head->next;	//暂存需释放空间的节点
	head->next = head->next->next;	//跳跃拉链，即删除了中间节点
	free(temp);						//释放节点
	temp = NULL;					//避免野指针
	
	return 0;	
}

/******************链表的复杂操作****************/
/*
单链表的反转
算法思路: 依次取原链表中各结点，将其作为新链表首结点插入H结点
即获取原链表的每个节点，在新链表进行头插法插入
1. 判断是否为空 / 是否只有1个节点
2. 断开链表，一分为二，分为第一个节点和后面链表
3. 遍历从第二个后面起的节点，头插法循环插入
*/
/*
功能：单链表的反转
参数：	par1:链表头	
返回值： 失败返回-1    成功返回0
*/
int link_reverse(listNode* head)
{
	//入口参数检查
	if(head == NULL ){
		printf("head is NULL.\n");
		return -1;
	}
	
	//只有一个节点
	if(head->next == NULL || head -> next ->next == NULL ){
		return 0;
	}
	
	//p指向待操作的节点
	listNode *p = head->next->next;		//新链表头
	head->next->next = NULL;			//链表一分为二
	listNode *q = p;
	
	//遍历后续节点，以尾插法插入新的链表
	while(p != NULL)
	{
		q = p;
		p = p->next;
		
		//头插法 插入q
		q->next = head->next;
		head->next = q;
	}
	
	return 0;
}

//求链表中相邻两节点data值之和为最大的第一节点的指针
/*
功能：求相邻节点最大值，返回最大值第一个节点地址
最大值通过参数传递
参数：	para1:链表头 	para2:最大和的值的地址
返回值： 失败返回NULL  成功返回第一个节点指针
*/
listNode *list_adjmax(listNode *head, data_t *value)
{
	if(head == NULL)
	{
		printf("head is NULL\n");
		return NULL;
	}
	
	if(head->next == NULL || head->next->next == NULL || head->next->next->next == NULL)
		return head;

	//构造辅助变量
	listNode *ret = head->next;			//结果链表尾指针
	listNode *p   = head->next->next;	//遍历链表的指针, p在前面
	listNode *q   = head->next;			//遍历链表的指针, q在后
	data_t max = q->data + p->data ;	//初始化两数之和
	
	
	while(p->next != NULL)
	{
		//p q更新
		p = p->next;
		q = q->next;
		
		//比较最大值
		if(q->data + p->data > max)
		{
			max = q->data + p->data;	//更新最大值
			ret = q;					//更新最大值第一个节点
		}
	}
	
	//返回相邻最大值的第一个节点指针，并通过参数传回最大值
	*value = max;
	return ret;
}

//合并两个有序链表
/*
功能：合并两个链表，合并至head1
参数：	para1:链表1头节点	para2:链表2头节点
返回值： 失败返回-1  成功返回0
*/
int link_merge(listNode *head1, listNode *head2)
{
	//入口参数检查
	if( head1 == NULL || head2 == NULL){
		printf("head1 || head2 error\n");
		return -1;
	}
	
	//变量初始化
	listNode *p = head1->next;
	listNode *q = head2->next;
	listNode *ret = head1;
	head1->next = NULL;
	head2->next = NULL;
	
	while(p != NULL && q != NULL)
	{
		if(p->data <= q->data)
		{
			ret->next = p;		//p接入ret链表
			p = p->next;		//更新p
			ret = ret->next;	//更新新表尾
			ret->next = NULL;	//置空新表尾
		}
		else
		{
			ret->next = q;		//q接入ret链表
			q = q->next;		//更新q
			ret = ret->next;	//更新新表尾
			ret->next = NULL;	//置空新表尾
		}
	}
	
	//把多的p或q接入到ret链表
	if( p != NULL)
		ret->next = p;
	if( q != NULL)
		ret->next = q;
		
	return 0;
}

/*
功能：链表的排序
参数：虚拟头节点
返回值： 成功返回0 失败返回-1
*/
int link_sort(listNode *head )
{
	//头节点为空
    if (head == NULL){
        printf("head is NULL\n");
        return -1;
    }
    //只有1个节点
    if (head->next == NULL){
        printf("only one node\n");
        return 0;
    }
    
    listNode *q, *p, temp;
    p = head->next;
    while (p->next != NULL)
    {
        q = p->next;		//q从基准元素的下个元素开始
        while (q != NULL)
        {
            if (p->data > q->data)	//后面的元素小
            {
            	//交换值
                temp = *q;			
                *q = *p;
                *p = temp;
				
				//交换地址
                temp.next = q->next;
                q->next = p->next;
                p->next = temp.next;
            }
            q = q->next;
        }
        p = p->next;
    }
    return 0;
}



void link_sort_test()
{
	listNode *head = link_create();
	int data1[] = {2, 9, -3, 5, 1};
	
	
	//尾插法插入数据
	for( int i = 0; i < 5; i++)
		link_push_back(head, data1[i]);
	
	//显示原链表
	printf("src link:");
	link_show(head);
	
	link_sort(head);
	printf("sort:  ");
	link_show(head);
}
/*
功能：删除有序链表中重复元素
参数：链表虚拟头节点
返回值：-1： 参数错误  	0： 删除成功
*/
//依次判断相邻元素是否相等，若相等，则删除那个结点
//不相等 节点指针偏移
int link_purge(listNode *head)
{
	if(head == NULL || head->next == NULL){
		printf("head is NULL\n");
		return -1;
	}
	
	if(head->next != NULL && head->next->next ==  NULL){
		printf("oney one node\n");
		return 0;
	}
	
	//初始化
	head = head->next;
	listNode *temp;
	while(head->next != NULL)
	{
		//数据相等 删除节点
		if(head->data == head->next->data)
		{
			temp = head->next;
			head->next = temp->next;
			free(temp);
		}
		else	//不相等 正常遍历
		head = head->next;
	}
	
	temp =NULL;
	return 0;
}



//-------------测试程序-------------
void link_test()
{
	listNode *head = link_create();
	int data1[] = {-3, 2, 9, 5, 101};
	int data2[] = {4, 100, 0};
	
	//尾插法插入数据
	for( int i = 0; i < 5; i++)
		link_push_back(head, data1[i]);
	
	//头插法插入数据
	for( int i = 0; i < 3; i++)	
		link_push_front(head, data2[i]);
	
	//特定位置插入数据
	link_insert(head,66,1);
	
	//显示原链表
	printf("src link:");
	link_show(head);
	
	link_delete_index(head, 2);	//删除下标为2的节点
	link_delete_val(head, 66);	//删除数据为66的节点
	printf("delete:  ");
	link_show(head);
	
	//查找
	int ret = link_getVal( head, 2);
	int idx = link_search( head, 101);
	printf("data[2]: %d\n", ret);
	printf("101's index: %d\n", idx);
	
	head = link_free(head);	
}


void link_reverse_test()
{
	listNode *head = link_create();
	int data1[] = {-3, 2, 9, 5, 3};
	for(int i = 0; i < 5; i++)
		link_push_back(head, data1[i]);
		
	//打印原链表
	printf("link: ");
	link_show(head);
	
	//翻转链表
	link_reverse(head);
	
	//打印翻转后的链表
	printf("reverse: ");
	link_show(head);
	
	//释放内存空间
	head = link_free(head);
}

void list_adjmax_test()
{
	listNode *head = link_create();
	int data1[] = {-3, 2, 9, 5, 3};
	for(int i = 0; i < 5; i++)
		link_push_back(head, data1[i]);
		
	//打印原链表
	printf("link: ");
	link_show(head);
	
	//计算最大两数之和及第一个节点
	int sum;
	listNode *ret = list_adjmax(head, &sum);
	
	//打印新节点数及其两数最大之和
	printf("data: %d\nsum: %d", ret->data, sum);
	
	//释放内存空间
	head = link_free(head);	
}


void link_merge_test()
{
	listNode *head1 = link_create();
	listNode *head2 = link_create();
	int data1[] = {1, 2, 4, 6, 8};
	int data2[] = {2, 5, 6, 22, 96, 128};
	
	//插入数据
	for(int i = 0; i < 5; i++)
		link_push_back(head1, data1[i]);
		
	for(int i = 0; i < 6; i++)
		link_push_back(head2, data2[i]);	
	
	//打印原有序链表
	printf("link1: ");
	link_show(head1);
	printf("link2: ");
	link_show(head2);
	
	//合并
	printf("merge: ");
	link_merge(head1, head2);
	link_show(head1);
	
	//去重
	printf("purge: ");
	link_purge(head1);
	link_show(head1);
	
	head1 = link_free(head1);	
	head2 = link_free(head2);	
}


int main()
{
	//link_test();
	//link_reverse_test();
	//list_adjmax_test();
	//link_merge_test();
	link_sort_test();
	
    return 0;
}	