#ifndef __SQ_STACK__
#define __SQ_STACK__

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

#endif
