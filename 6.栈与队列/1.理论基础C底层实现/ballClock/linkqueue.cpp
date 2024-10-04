#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkqueue.h"

//创建队列
linkqueue* queue_create()
{
    linkqueue *lq;

    //申请内存空间
    lq = (linkqueue *)malloc(sizeof(linkqueue));
    if(lq == NULL){
        printf("malloc linkqueue failed\n");
        return NULL;
    }

	//队列头尾指针申请内存空间
	lq->front = lq->rear = (listNode *)malloc(sizeof(listNode));
	if(lq->front == NULL){
		printf("malloc listNode failed\n");
		return NULL;
	}

	//节点数据与指针赋值
	lq->front->data = 0;
	lq->front->next = NULL;

    return lq;
}


//入队列 -1: 入队失败   0 : 入队成功
int enqueue(linkqueue *lq, data_t value)
{
    //入口参数检查
    if(lq == NULL){
        printf("linkqueue is NULL\n");
        return -1;
    }
	
	//1.封装孤立节点p
	listNode* p = (listNode*)malloc(sizeof(listNode));
	if(p == NULL){
		printf("malloc listNode failed\n");
		return -1;
    }
	p->data = value;
	p->next = NULL;

	//2.队尾插入节点p
	lq->rear->next = p;
	
	//3.更新队尾指针rear
	lq->rear = p;
	
    return 0;
}

//出队
data_t dequeue(linkqueue *lq)
{
    //入口参数检查
    if(lq == NULL){
        printf("linkqueue is NULL\n");
        return -1;
    }

    //空队
    if(lq->front == lq->rear){
        return -1;
    }
	
	//暂存待删除节点并释放节点空间
	listNode* temp = lq->front;		//暂存队头节点
    lq->front = temp->next;   		//队头指针偏移
	free(temp);						//释放队头空间
	temp = NULL;
	
    return lq->front->data;
}

//判断队列是否为空队列
// 1: 空队   0: 非空队  -1:参数异常
int queue_empty(linkqueue *lq)
{
    //入口参数检查
    if(lq == NULL){
        printf("linkqueue is NULL\n");
        return -1;
    }

    if(lq->front == lq->rear)
        return 1;
    else
        return 0;
}

//清空队列
// -1: 函数失败，0: 函数成功
int queue_clear(linkqueue *lq)
{
    //入口参数检查
    if(lq == NULL){
        printf("linkqueue is NULL\n");
        return -1;
    }
	
	//判断队列是否为空队列
	if(lq->front == lq->rear){
		printf("linkqueue is empty\n");
		return -1;
	}
	
	while(lq->front != NULL)
	{
		lq->front->data = 0;
		lq->front = lq->front->next;
	}
	
    return 0;
}

//释放队列空间
int queue_free(linkqueue *lq)
{
    //入口参数检查
    if(lq == NULL){
        printf("linkqueue is NULL\n");
        return -1;
    }
	listNode * p;
	//循环释放节点
	while(lq->front)
	{
		p = lq->front;			//暂存节点
		lq->front = p->next;	//偏移队列头下标
		printf("free: %d\n",p->data);
		free(p);				//释放暂存节点
	}
	p = NULL; 
}


