#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef char data_t;		//节点数据类型

typedef struct node{
	data_t data;			//节点数据
	struct node *left;		//左子树
	struct node *right;		//右子树
}Bitree;


Bitree* creat_bitree()
{
	data_t ch;
	Bitree* root;
	scanf("%c",&ch);
	//空树
	if(ch == '#')
		return NULL;
	//封装节点
	root = (Bitree*)malloc(sizeof(Bitree));	
	if(root == NULL)
	{
		printf("malloc failed\n");
		return NULL;
	}
	//数据域 左右子树地址赋值
	root->data = ch;
	root->left = creat_bitree();
	root->right = creat_bitree();
	return root;
}

//功能：先序遍历
//参数：根节点指针
void preorder(Bitree* root)
{
	if(root == NULL)
		return;
	//根左右
	printf("%c",root->data); 	//获取根节点数据
	preorder(root->left);		//继续遍历左子树
	preorder(root->right);		//继续遍历右子树
}

//功能：中序遍历
//参数：根节点指针
void inorder(Bitree* root)
{
	if(root == NULL)
		return;
	//左根右
	inorder(root->left);
	printf("%c",root->data); 
	inorder(root->right);
}


//功能：后序遍历
//参数：根节点指针
void postorder(Bitree* root)
{
	if(root == NULL)
		return ;
	//左右根
	postorder(root->left);		
	postorder(root->right);		
	printf("%c",root->data); 	
}


int main()
{
	Bitree* root;
	
	root = creat_bitree();
	if(root == NULL){
		printf("creat bitree failed!\n");
		return -1;
	}
	
	//先序
	preorder(root);
	printf("\n");
	
	//中序
	inorder(root);
	printf("\n");
	
	//后序
	postorder(root);
	printf("\n");
	return 0;
}

