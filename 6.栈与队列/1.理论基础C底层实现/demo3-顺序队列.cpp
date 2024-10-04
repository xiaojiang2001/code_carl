#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int data_t;		//定义栈中数据元素类型
#define N 64			//定义队列容量
//队列的定义
typedef struct
{
	data_t  data[N];	//用数组作为队列的存储空间
	int front;			//指示队头位置指针
	int rear;			//指示队尾位置指针
}sequeue;				//队列类型定义

//front指向对头元素的位置
//rear指向队尾元素的下一个位置


sequeue* queue_create();				//创建空队列
int enqueue(sequeue *sq, data_t value);	//入队
data_t dequeue(sequeue *sq);			//出队
int queue_empty(sequeue *sq);			//判断队列是否为空队列
int queue_full(sequeue *sq);			//判断队列是否为满队列
int queue_clear(sequeue *sq);			//清空队列
sequeue* queue_free(sequeue *sq);		//释放队列空间

//创建队列
sequeue* queue_create()
{
	sequeue *sq;
	
	//申请内存空间
	sq = (sequeue *)malloc(sizeof(sequeue));
	if(sq == NULL){
		printf("malloc sequeue failed\n");
		return NULL;
	}
	
	//初始化数据
	memset(sq->data, 0, sizeof(sq->data));
	
	//定义队列头尾为0
	sq->front = 0;
	sq->rear  = 0;
	
	return sq;
}				


//入队列 -1: 入队失败 	0 : 入队成功
int enqueue(sequeue *sq, data_t value)
{
	//入口参数检查
	if(sq == NULL){
		printf("sequeue is NULL\n");
		return -1;
	}
	
	//判断队列是否为满队列
	if((sq->rear+1) % N == sq->front){
		printf("sequeue is full\n");
		return -1;
	}
	
	//队尾存入元素
	sq->data[sq->rear] = value;
	sq->rear = (sq->rear + 1) % N;
	
	return 0;
}

//出队
data_t dequeue(sequeue *sq)
{
	//入口参数检查
	if(sq == NULL){
		printf("sequeue is NULL\n");
		return -1;
	}
	
	//空队
	if(sq->front == sq->rear){
		return -1;
	}
	
	//获取队头数据
	data_t ret;
	ret = sq->data[sq->front];			//队头数据
	sq->front = (sq->front + 1) % N;	//队头指针偏移
	return ret;
}

//判断队列是否为空队列
// 1: 空队   0: 非空队  -1:参数异常
int queue_empty(sequeue *sq)
{
	//入口参数检查
	if(sq == NULL){
		printf("sequeue is NULL\n");
		return -1;
	}
	
	if(sq->front == sq->rear)
		return 1;
	else
		return 0;
}			

//判断队列是否为满队列
// 1: 满队   0: 非满队  -1:参数异常
int queue_full(sequeue *sq)
{
	//入口参数检查
	if(sq == NULL){
		printf("sequeue is NULL\n");
		return -1;
	}
	
	//满队
	if((sq->rear + 1) % N == sq->front)
		return 1;
	else	
		return 0;
}

//清空队列
int queue_clear(sequeue *sq)		
{
	//入口参数检查
	if(sq == NULL){
		printf("sequeue is NULL\n");
		return -1;
	}
	
	sq->front = sq->rear = 0;
	return 0;
}

//释放队列空间
sequeue* queue_free(sequeue *sq)	
{
	//入口参数检查
	if(sq == NULL){
		printf("sequeue is NULL\n");
		return NULL;
	}
	free(sq);
	sq = NULL;
}


int main()
{
	sequeue *sq;
	sq = queue_create();
	if(sq == NULL)
		return -1;
	
	//入队
	enqueue(sq,1);
	enqueue(sq,2);
	enqueue(sq,3);
	enqueue(sq,4);

	while(!queue_empty(sq))				//队列不为空
	{
		printf("dequeue: %d\n",dequeue(sq));	//出队
	}
	queue_free(sq);			//释放队列
	return 0;
}

