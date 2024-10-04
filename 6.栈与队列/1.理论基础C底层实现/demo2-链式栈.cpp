#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int data_t;			//定义栈中数据元素类型

//栈的定义
typedef struct node_t{
	data_t data;			//节点数据域
	struct node_t *next;	//节点指针域
}linkStack;					//定义链式栈
	
	
linkStack* stack_create();					//创建栈
int stack_push(linkStack* s, data_t value);	//数据入栈
int stack_pop(linkStack* s);				//数据出栈
int stack_empty(linkStack * s);				//判断栈是否为空
data_t stack_top(linkStack* s);				//获取栈顶元素
linkStack* stack_free(linkStack * s);		//释放栈空间

//创建栈
linkStack* stack_create()
{
	linkStack * stack;		//定义栈 stack
	
	//建立空栈(链表)
	stack = (linkStack *)malloc(sizeof(linkStack));	
	if(stack == NULL)
	{
		printf("malloc linkStack failed\n");
		return NULL;
	}
	
	stack->next = NULL;		//下一个节点指向空
	stack->data = 0;		//数据设置0
			
	return 	stack;			//返回当前节点的首地址
}

//入栈 -1: 入栈失败 	0 : 入栈成功
int stack_push(linkStack* s, data_t value)
{
	//入口参数检查
	if(s == NULL){
		printf("stack is NULL\n");
		return -1;
	}
	
	//为新节点开辟空间 封装节点
	linkStack * p = (linkStack *)malloc(sizeof(linkStack));
	if(p == NULL)
	{
		printf("malloc p failed\n");
		return -1;
	}
	p->data = value;
	
	//节点插入链表 头插法
	p->next = s->next;
	s->next = p;
	
	return 0;
}

//出栈 -1:出栈失败   0：出栈成功 
int stack_pop(linkStack* s)
{
	//入口参数检查
	if(s == NULL){
		printf("s is NULL\n");
		return -1;
	}
	data_t t;
	
	linkStack * temp = s->next;		//存储待删除的节点
	s->next = s->next->next;		//指向下下个节点
	t = temp->data;					//获取节点的值
	
	free(temp);						//释放出栈的节点
	temp = NULL;
	
	return t;
}


//判断空栈
/*
1: 空栈  
0: 非空栈
-1:	异常
*/
int stack_empty(linkStack * s)
{	
	if(s == NULL)
	{
		printf("s is NULL\n");
		return -1;
	}
	if(s->next == NULL)
		return 1;
	else
		return 0;
}

//获取栈顶元素
data_t stack_top(linkStack* s)
{
	if(s == NULL)
		printf("s is NULL\n");
	
	return s->next->data;
}


//释放栈空间
linkStack* stack_free(linkStack * s)
{
	if(s == NULL)
	{
		printf("s is NULL\n");
		return NULL;
	}
	
	linkStack * p = s;
	while(s != NULL)	//依次遍历整个链表 进行删除
	{
		p = s;		//暂存s
		s = s->next;	//s偏移
		printf("free: %d\n",p->data);
		free(p);		//释放暂存s
	}
	return NULL;
}


int main()
{
	linkStack * s;
	s = stack_create();		//创建栈
	if(s == NULL)			//创建栈失败
		return -1;
	
	//入栈
	stack_push(s,1);
	stack_push(s,2);
	stack_push(s,3);
	stack_push(s,4);
/*
	while(!stack_empty(s))				//栈不为空
	{
		printf("pop: %d\n",stack_pop(s));	//出栈
	}
*/
	s = stack_free(s);			//释放栈，并避免s出现野指针
	
	return 0;
}

