#ifndef __LINK_QUEUE__
#define __LINK_QUEUE__

typedef int data_t;     //定义栈中数据元素类型
#define N 64            //定义队列容量
//链式节点定义
typedef struct node
{
    data_t  data;           //节点数据域
    struct  node *next;     //节点指针域
}listNode;                  //定义链式队列

//队列的定义
typedef struct{
    listNode* front;
	listNode* rear;
}linkqueue;


linkqueue* queue_create();                  //创建空队列
int enqueue(linkqueue *lq, data_t value);   //入队
data_t dequeue(linkqueue *lq);              //出队
int queue_empty(linkqueue *lq);             //判断队列是否为空队列
int queue_clear(linkqueue *lq);             //清空队列
int queue_free(linkqueue *lq);       		//释放队列空间

#endif
