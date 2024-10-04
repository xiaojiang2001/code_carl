#include <stdio.h>
#include "linkqueue.h"
#include "sqstack.h"

//检查队列是否升序
int check(linkqueue *lq);

int main()
{
	linkqueue* lq;		//队列名称
	int i;				//时钟球编号
	sqStack * stack_hour;	//定义三个栈容器
	sqStack * stack_five;
	sqStack * stack_min;
	int min = 0;		//分钟计时器
	int value;			//保存出队的值
	
	//创建链式队列
	lq = queue_create();   
	if(lq == NULL){
		printf("lq create failed\n");
		return -1;
	}
	//27个球顺序入队
	for(i = 1; i <= 27; i++)
		enqueue(lq, i);		

	//创建栈
	stack_hour = stack_create(11);
	stack_five = stack_create(11);
	stack_min  = stack_create(4);
	if(stack_hour == NULL || stack_five == NULL || stack_min == NULL){
		printf("create stack failed\n");
		return -1;
	}
	
	while(1)
	{
		min++;					//每过1分钟
		if(!queue_empty(lq))	//队不空
		{
			value = dequeue(lq);//出队
			
			//分钟计时器不满，放分钟计时器
			if(!stack_full(stack_min))
			{
				stack_push(stack_min,value);	//入分钟栈
			}
			else	//分钟计时器满
			{
				//栈不空 出栈入队列
				while(!stack_empty(stack_min))	
				{
					enqueue(lq, stack_pop(stack_min));
				}
				
				//5分钟计时器未满
				if(!stack_full(stack_five))
				{
					stack_push(stack_five, value);
				}
				else	//5分钟计时器满了 例如0:59
				{
					while(!stack_empty(stack_five))	//清空5分钟计时器
					{
						enqueue(lq, stack_pop(stack_five));	//出栈入队列
					}
					
					//小时计时器未满 小时计时器存入数据
					if(!stack_full(stack_hour))
					{
						stack_push(stack_hour, value);
					}
					else	//小时计时器也满了 11:59
					{
						while(!stack_empty(stack_hour))	//清空小时计时器
						{
							enqueue(lq, stack_pop(stack_hour));	//出栈入队列
						}
						enqueue(lq,value);		//栈全满，球放回队列
						//0:00
						if(check(lq) == 1)	//检查队列是否升序
						{
							break;
						}
					}
				}
			}		
		}
	}
	printf("total: %d\n",min);
	
	//队列不空 出队
	printf("dequeue: ");
	while(!queue_empty(lq))
	{
		printf("%d ",dequeue(lq));
	}
	printf("\n");
	
	return 0;
}


//检查队列是否升序
//1: 升序  0：无序
int check(linkqueue *lq)
{
	if(lq == NULL)
	{
		printf("lq is NULL\n");
		return 0;
	}
	
	listNode* p = lq->front->next;	//遍历队列
	while(p != NULL && p->next != NULL)
	{
		if(p->data < p->next->data)
			p = p->next;
		else	
			return 0;
	}
	return 1;
}


