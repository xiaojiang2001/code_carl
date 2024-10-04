#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

/*****************************数据类型定义******************************/
using namespace std;
struct TreeNode {
   int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
			:val(x), left(left), right(right) {}
};


/*****************************初始化数据******************************/
TreeNode* creat_bitree()
{
	char dat;
	TreeNode* root;
	scanf("%c",&dat);
	//空树
	if(dat == '#')
		return NULL;
	//封装节点
	root = (TreeNode*)malloc(sizeof(TreeNode));	
	if(root == NULL)
	{
		printf("malloc failed\n");
		return NULL;
	}
	//数据域 左右子树地址赋值
	root->val = dat;
	root->left = creat_bitree();
	root->right = creat_bitree();
	return root;
}

void showVector(vector<double> &vp)
{
	//创建对应的迭代器，遍历容器 
	for(auto it = vp.begin(); it < vp.end();it++)
	{
		//*it 对应的是容器<>内的数据类型
		cout << *it - '0' << " ";	
	}
	cout << endl;
}

void showDoubleVector(vector<vector<int>> &vp)
{
	//创建对应的迭代器，遍历容器 
	for(auto it = vp.begin(); it < vp.end();it++)
	{
		for(auto vit = it->begin(); vit < it->end(); vit++)
		{
			cout << *vit - '0' << " ";	
		}
		cout << endl;	
	}
	cout << endl;
}



/****************************算法******************************/
class Solution {
public:
//	//获取普通二叉树节点数量 递归算法
//	int getNum(TreeNode* node)
//	{
//		if(node == NULL)
//			return 0;
//		//后续遍历
//		int leftNum  = getNum(node->left);	//左
//		int rightNum = getNum(node->right);	//右
//		return leftNum + rightNum + 1;		//中
//	} 
	
	
	//获取完全二叉树节点数量 
	//递归算法：判断子树是否为满二叉树
	//满二叉树的判断：向左遍历和向右遍历的深度是一致的
	//(前提：已经是一棵完全二叉树)
	int getNum(TreeNode* node)
	{
		if(node == NULL)
			return 0;
		
		//满二叉树 结束
		int leftDepth  = 0;
		int rightDepth = 0;
		TreeNode* leftNode  = node->left;
		TreeNode* rightNode = node->right;	
		//向左遍历
		while(leftNode)
		{
			leftNode = leftNode->left;
			leftDepth++;
		}
		//向右遍历
		while(rightNode)
		{
			rightNode = rightNode->right;
			rightDepth++;
		}
		//满二叉树
		if(leftDepth == rightDepth)	
			return (2<<leftDepth) - 1;
			
		//单层递归逻辑
		int leftNum  = getNum(node->left);	//左
		int rightNum = getNum(node->right);	//右
		return leftNum + rightNum + 1;		//中
	}
	int countNodes(TreeNode* root) 
	{
		return getNum(root);
	}
};

int main()
{
	Solution s;
	vector<double> res;
	
	//创建二叉树
	cout << "请以前序遍历方式输入一棵满二叉树,空节点用#表示" << endl;
	TreeNode* root = creat_bitree();
	int len = s.countNodes(root);
	cout << "node num:" << len;
	return 0;
} 

//1#23##65###

