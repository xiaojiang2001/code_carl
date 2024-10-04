#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define N 15 

//描述单个节点 
typedef struct node{
	int key;
	int value; 
	struct node* next;
}ListNode;
 
//哈希表为一个节点数组
typedef  struct Hash{
	ListNode data[N];
}Hash;

//哈希表的创建 
Hash * hash_create(){
	Hash *HT;
	HT = (Hash *)malloc(sizeof(Hash));
	if(HT == NULL)
		printf("malloc failed\n");
	
	memset(HT, 0, sizeof(Hash));
	
	return HT;
} 

//哈希表的插入 
int hash_insert(Hash *HT, int key){
	ListNode* p;		//封装的独立节点
	ListNode* q;		//哈希表中的节点
	
	//入口参数检查
	if(HT == NULL){
		printf("TH is NULL\n");
		return -1;
	}
	
	//开辟独立节点空间
	p = (ListNode*)(malloc)(sizeof(ListNode));
	if(p == NULL){
		printf("malloc failed\n");
		return -1;
	}
	
	//独立节点赋值
	p->key = key;
	p->value = key % N;
	p->next = NULL;
	
	//检查是否前面有节点
	q = &(HT->data[key % N]);
	while(q->next != NULL && p->key > q->next->key)
	{
		q = q->next;
	}
	
	//插入新节点
	p->next = q->next;
	q->next = p;
	
	return 0;
}
//
////哈希表的查找 
ListNode* hash_search(Hash *HT,int key) {
	ListNode* p;		//p 指具体链的头节点
	//入口参数检查
	if(HT == NULL){
		printf("TH is NULL\n");
		return NULL;
	}
	
	//key % N;
	p = &HT->data[key % N];
	
	//遍历链
	while(p->next != NULL && p->next->key != key){
		p = p->next;
	}
	
	if(p->next == NULL){
		return NULL;
	}
	else{
		printf("found\n");
		return p->next;
	}
}


int main()
{
	Hash *HT;
	int i; 
	int key;
	int data[] = {23,34,14,38,46,16,68,15,7,31,26};
	ListNode* ret;
	
	HT = hash_create();
	if( HT == NULL){
		return -1;
	}
	
	for(i = 0; i < sizeof(data)/sizeof(int); i++)
	{
		hash_insert(HT,data[i]);	//插入数据
	}
	
	
	printf("input: ");
	scanf("%d",&key);
	ret = hash_search(HT,key);	//查找key
	if(ret == NULL)
		printf("not found\n");
	else
	{
		printf("found: %d %d\n",key,ret->key);
	}
	  
	return 0;
} 


