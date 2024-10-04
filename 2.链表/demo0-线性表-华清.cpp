#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

//线性表示包含若干个数据元素的一个线性序列
//记为：L=(a0,a1,...ai-1,ai,ai+1,...an-1)
//L为表名, ai为数据元素, n为表长


//线性表的特征：
//(1)对非空表，a0是表头，无前驱
//(2)an-1是表尾，无后继
//(3)其他的每个元素ai有且仅有一个直接前驱ai-1，和一个直接后继ai+1


//顺序存储结构的不足
//对表的插入和删除等运算的时间复杂度较差

//在C语言中，可借助一维数组类型来描述线性表的顺序存储结构
//主程序
//typedef struct{
//	int id;
//	char *name;
//	float price;
//}book;

//变量与顺序表结构定义
#define N 100
typedef int data_t;

typedef struct{
	data_t data[N];	//表的存储空间
	int n;			//线性表中最后一个元素下标
}sqlist;



/*****************函数声明*******************/
/*************顺序表的基本属性***************/
sqlist* list_create(int n);		//建立一个空表
int list_clear(sqlist* list);	//清空表
int list_empty(sqlist* list);	//判断表是否为空
int list_length(sqlist* list);	//求线性表长度
void list_show(sqlist* list);	//显示线性表
int list_free(sqlist* list);	//释放线性表空间

/*************顺序表的相关运算***************/
data_t list_getVal(sqlist* list, int pos); 				//根据索引获取值
int list_locate(sqlist* list, data_t value);			//确定元素value的索引值
int list_push_back(sqlist* list, data_t value);			//尾插法
int list_push_front(sqlist* list, data_t value);		//头插法
int list_insert(sqlist* list, int pos, data_t value);	//在特定位置插入元素
int list_delete(sqlist* list, int index);				//删除一个元素
int list_merge(sqlist* list1, sqlist* list2);			//线性表合并 list2并入list1
int list_purge(sqlist* list1);							//删除线性表中重复元素

/********************函数实现*******************/
/*
功能：建立一个空的线性表
参数：void
返回值：线性表指针
*/
sqlist* list_create()
{
	//申请内存空间
	sqlist* list = (sqlist *)malloc(sizeof(sqlist));
	if(list == NULL){
		printf("list_create: malloc error\n");
		return NULL;
	}
	
	//线性表成员变量赋值
	list->n = -1;
	
	return list;
}

/*
功能：清空线性表
参数：线性表指针
返回值：-1---参数错误   成功返回 0
*/
int list_clear(sqlist* list)
{
	//入口 参数检查
	if(list == NULL){
		printf("list_clear: list is NULL");
		return -1;
	}
	
	//清空数组数据
	int len = list_length(list);
	memset(list->data, '\0', sizeof(data_t) * len);
	list->n = -1;
	
	return 0;
}

/*
功能：判断线性表是否为空
参数：线性表指针
返回值：空：返回1  非空: 返回0
*/
int list_empty(sqlist* list)
{
	if(list->n == -1)
		return 1;
	else
		return 0;
}

/*
功能：求线性表长度
参数：线性表指针
返回值：-1---参数错误   >0 表长
*/
int list_length(sqlist* list)
{
	//入口 参数检查
	if(list == NULL){
		printf("list_length: list is NULL");
		return -1;
	}
	
	//返回线性表长度
	return list->n + 1;
}



/*
功能：显示线性表
参数：线性表指针
返回值：void
*/
void list_show(sqlist* list)
{
	if(list->n == -1)
		printf("list is NULL");
	if(list != NULL)
	{
		for(int i = 0; i <= list->n; i++)
			printf("%d ",list->data[i]);
		printf("\n");
	}
	else
		printf("list is NULL\n");

}

/*
功能：释放线性表内存表空间
参数：线性表指针
返回值：-1： 参数错误/为空  0: 释放成
*/
int list_free(sqlist* list)
{
	if(list == NULL)
		return -1;
	free(list);
	list = NULL;
	return 0;	
}


/*
功能：根据下标获取某个元素
参数：线性表指针
返回值：-1： 参数错误/为空  正常返回获取的元素
*/
data_t list_getVal(sqlist* list, int index) //获取ai的值
{
	//入口 参数检查
	if(list == NULL)
		printf("list_getVal: list is NULL");
	
	return list->data[index];
}

/*
功能：定位运算
参数：线性表指针， 需要定位的元素值
返回值：返回value在表中的下标, 不存在则返回-1
*/
int list_locate(sqlist* list, data_t value)	//确定元素value在表中的下标
{
	if(list == NULL)
		return -1;
	
	//比较value是否在 list内
	for(int i = 0; i <= list->n; i++)
	{
		if(list->data[i] == value)
			return i;
	}
	return -1;
}

/*
功能：尾插法插入元素
参数：para1：线性表指针	para2：待插入的元素
返回值：-1： 参数错误  0: 插入成功
*/
int list_push_back(sqlist* list, data_t value)
{
	//入口参数检查
	if(list == NULL || list->n >= N-1){
		printf("push_back para error\n");
		return -1;
	}
	
	//线性表尾插入数据
	list->n++;
	list->data[list->n] = value;	
	return 0;
}

/*
功能：头插法插入元素
参数：para1：线性表指针	para2：待插入的元素
返回值：-1： 参数错误  0: 插入成功
*/
int list_push_front(sqlist* list, data_t value)
{
	//入口参数检查
	if(list == NULL || list->n >= N-1){
		printf("push_front para error\n");
		return -1;
	}
	
	//右移 
	list->n++;	//线性长+1
	for(int i = list->n; i > 0; i--)
		list->data[i] = list->data[i-1];
	
	//插入新数据
	list->data[0] = value;
	return 0;
}


/*
功能：特定位置插入元素
参数：para1：线性表指针	para2：待插入的元素
返回值：-1：参数错误  0: 插入成功
*/
int list_insert(sqlist* list, int index, data_t value)
{
	//入口参数检查
	if(list == NULL  || list->n >= N-1){
		printf("list_insert para error\n");
		return -1;
	}
	//线性表满了
	if(index < 0 || index > N){
		printf("index index error\n");
		return -1;
	}
	
	//插入位置大，放表尾
	else if(index > list->n){
		list->n++;
		list->data[list->n] = value;	
		return 0;
	}
	else
	{
		list->n++;	//表长+1
		//右边数据后移 从后往前
		for(int i = list->n; i > index; i--)	
			list->data[i] = list->data[i-1];
		//插入数据
		list->data[index] = value;
		return 0;
	}
}



/*
功能：删除索引为index的元素
参数：para1：线性表指针， para2：待删除的下标位置
返回值：-1： 参数错误  0: 删除成功
*/
int list_delete(sqlist* list, int index)
{
	//入口参数检查: 表空 / 删除索引非法
	if(list == NULL || list->n == -1 || index < 0 || index > list->n ){
		printf("list_delete para error\n");
		return -1;
	}
	
	//数据左移 覆盖即删除
	for(int i = index; i < list->n; i++){
		list->data[i] = list->data[i+1];
	}
	
	//线性表长度减1
	list->n--;	
	return 0;
}

/*
功能：线性表合并 list2并入list1
参数：参数1：线性表1指针 参数2： 线性表2指针
返回值：--1： 参数错误  0： 合并成功
*/
int list_merge(sqlist* list1, sqlist* list2)
{
	//入口参数错误
	if(list1 == NULL || list2 == NULL)
		return -1;
	
	for(int i = 0; i <= list2->n; i++)
	{
		int ret = list_locate(list1, list2->data[i]);
		//找到list2中有元素不在list1,尾插数据
		if(ret == -1){
			list_push_back(list1, list2->data[i]);	
		}		
	}
	return 0;
}

/*
功能：删除线性表中重复元素
参数：线性表指针
返回值：-1： 参数错误  	0： 删除成功
*/
//依次取i [1,n],判断ai是否在[0,ai-1]内
//若不在，i++,若在，删除ai,重新比ai
int list_purge(sqlist* list)
{
	//入口参数检查
	if(list == NULL){
		printf("list_purge: list error\n");
		return -1;
	}
	
	//只有1个数
	if(list->n == 0)
		return 0;
		
	int i = 1;
	//开始遍历 i [1,n]的元素
	while(i <= list->n)
	{
		int j = i-1;
		//开始遍历 [0,ai-1]元素
		while(j >= 0)
		{
			if(list->data[i] == list->data[j])
			{
				list_delete(list, i);
				break;
			}	
			else
				j--;	
		}
		
		//没找到 
		if(j < 0)
			i++;
	}
	return 0;
}


void test_inert_delete();	//测试插入与删除
void test_merge();			//测试线性表的合并
void test_purge();			//测试删除重复元素
int main()
{
	//test_inert_delete();
	//test_merge();
	test_purge();
    return 0;
}

//线性表插入与删除测试
void test_inert_delete()
{
	sqlist* list = list_create();
	if(list == NULL){
		printf("list create error\n");
		return;
	}
	
	//头插 尾插 中间插 并显示
	list_push_back(list, 66);
	list_push_back(list, 100);
	list_push_back(list, 22);
	list_push_front(list,12);
	list_insert(list,3,76);
	list_show(list);
	
	//删除数据并显示
	list_delete(list,2);
	list_show(list);
	
	//释放表
	list_free(list);
}

//线性表合并测试函数
void test_merge()
{
	//创建线性表1
	sqlist* list1 = list_create();
	list_push_back(list1,10);
	list_push_back(list1,20);
	list_push_back(list1,30);
	
	//创建线性表2
	sqlist* list2 = list_create();
	list_push_back(list2,30);
	list_push_back(list2,50);
	
	//将表2合并至表1
	list_merge(list1,list2);
	list_show(list1);
	
	list_free(list1);
	list_free(list2);
}
//测试删除重复元素
void test_purge()
{
	//创建线性表1
	sqlist* list = list_create();
	list_push_back(list,10);
	list_push_back(list,10);
	list_push_back(list,10);
	list_push_back(list,10);
	list_push_back(list,10);
	list_push_back(list,10);
	
	list_show(list);
	list_purge(list);
	list_show(list);
	list_free(list);
}




			