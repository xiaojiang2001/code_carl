#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define MAX_TABLE 100	//哈希表最大长度 

//哈希数组 
void creat_hash(int a[], int n, int table[])
{
	int i;
	for(i = 0; i < n; i++)
		table[a[i]]++;		//哈希数组 桶排序 
}


int find_key(int table[], int key)
{
	if(table[key] != 0)
		return 1;
	else
		return 0;
}

//整型数据哈希函数
int int_Hash(int key)
{
	return key % 19;
}

int string_Hash(const char *key)
{
	int sum;
	while(*key != '\0')	//遍历字符
	{
		sum += *key;	//将ASCII 码相加
		key++;
	}
	return sum % 29;
}



int main()
{
	int a[] = {7, 17, 5, 8, 2, 9, 20 ,3, 2, 5};
	int n = sizeof(a)/sizeof(a[0]);
	int i;
	int table[MAX_TABLE] = {0};
	
	creat_hash(a,n,table);
	
	for(i=0;i<MAX_TABLE;i++)
	{
		if(table[i] > 0)
			printf("%d appear %d times\n",i,table[i]);
	}
	
	  
	return 0;
} 

unsigned int DJBHash(const char *str)
{
	unsigned int hash = 5381;	//非常特殊的一个质数
	while(*str)					//循环遍历字符串中的每个字符
	{
		//将hash值左移5位加上hash,再加字符str的SACII码的值
		hash = (hash << 5) + hash + *str;  		//hash<<5 + hash  => hash * 33
		str++;
	}
	return (hash & 0x7FFFFFFF);
}
