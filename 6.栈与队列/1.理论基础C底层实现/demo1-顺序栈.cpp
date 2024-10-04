#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int data_t;		//定义栈中数据元素类型
//栈的定义
typedef struct{
	data_t * data;	//指针指向栈的存储空间
	int maxlen;		//当前栈的最大元素个数
	int top;		//指示栈顶位置
}sqStack;

sqStack* stack_create(int len);		//创建栈
int stack_push(sqStack* s, data_t value);	//数据入栈
int stack_pop(sqStack* s);			//数据出栈
data_t stack_top(sqStack* s);		//获取栈顶元素
void stack_clear(sqStack * s);		//清空栈
int stack_empty(sqStack * s);		//判断栈是否为空
int stack_full(sqStack * s);		//判断栈是否为满


//创建栈
sqStack* stack_create(int len)
{
	sqStack * stack;		//定义栈 stack
	
	//为栈开辟空间
	stack = (sqStack*)malloc(sizeof(sqStack));	
	if(stack == NULL)
	{
		printf("malloc sqstack faile\n");
		return NULL;
	}
	
	//为栈内数据开辟空间
	stack->data = (data_t *)malloc(sizeof(data_t) * len);
	if(stack->data == NULL)
	{
		printf("malloc data faile\n");
		return NULL;
	}
	
	//初始化数据
	memset(stack->data, 0, len * sizeof(data_t));
	stack->top = -1;		//设置栈顶下标-1
	stack->maxlen = len;	//设置栈最大长度
	
	return 	stack;
}

//入栈 -1: 入栈失败 	0 : 入栈成功
int stack_push(sqStack* s, data_t value)
{
	//入口参数检查
	if(s == NULL){
		printf("stack is NULL\n");
		return -1;
	}
	
	//栈满
	if(s->top == s->maxlen - 1){
		printf("stack is full\n");
		return -1;
	}
	
	//数据入栈
	s->top++;				//栈顶下标+1
	s->data[s->top] = value;//在栈顶存入数据
	return 0;
}

//出栈
int stack_pop(sqStack* s)
{
	//入口参数检查
	if(s == NULL){
		printf("s is NULL\n");
		return -1;
	}
	
	s->top--;					//栈顶下标-1
	return  s->data[s->top+1];	//返回栈顶元素
}

//获取栈顶元素
data_t stack_top(sqStack* s)
{
	if(s->top == -1)
		printf("栈为空\n");
	
	return s->data[s->top];	
	
}

//清空栈
void stack_clear(sqStack * s)
{
	//入口参数检查
	if(s == NULL){
		printf("s is NULL\n");
	}
	s->top = -1;	//将栈顶下标设置为-1, 代表栈为空
}

//判断空栈
/*
1: 空栈  
0: 非空栈
-1: 参数为空
*/
int stack_empty(sqStack * s)
{
	//入口参数检查
	if(s == NULL){
		printf("s is NULL\n");
		return -1;
	}
	
	if(s->top == -1)	//栈为空
		return 1;
	else
		return 0;
}

//判断满栈
/*
1: 满栈
0：非满栈
-1：参数错误
*/
int stack_full(sqStack * s)
{	
	//入口参数检查
	if(s == NULL){
		printf("s is NULL\n");
		return -1;
	}
	
	if(s->top == s->maxlen-1)	//栈满
		return 1;
	else	
		return 0;
}

//释放空间
int stack_free(sqStack * s)
{
	free(s->data);		//释放栈内部成员变量
	free(s);			//释放栈空间
}
int main()
{
	sqStack * s;
	s = stack_create(10);
	if(s == NULL)
		return -1;
	
	//入栈
	stack_push(s,1);
	stack_push(s,2);
	stack_push(s,3);
	stack_push(s,4);

	while(stack_empty(s) == 0)				//栈不为空
	{
		printf("pop: %d\n",stack_pop(s));	//出栈
	}
	stack_free(s);			//释放栈
	return 0;
}

