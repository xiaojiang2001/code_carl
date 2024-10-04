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
	//递归函数
	
	//T 112
/*
	bool traversal(TreeNode* node, int count)
	{
		//遇到可行路径的叶子节点
		if(node->left == NULL && node->right == NULL && count == 0)
			return true;		//一路减下来 是目标路径
		//其他叶子节点
		if(node->left == NULL && node->right == NULL)
			return false;

		//向左遍历
		if(node->left)
		{
			count -= node->left->val;
			bool ret = traversal(node->left,count);
			if(ret)						//如果存在 一路返回
				return true;
			count += node->left->val;	//回溯count 
		}
		//向右遍历
		if(node->right)
		{
			count -= node->right->val;
			bool ret = traversal(node->right,count);
			if(ret)						//如果存在 一路返回
				return true;
			count += node->right->val;	//回溯count 
		}
		return false;
	}
	
   	bool hasPathSum(TreeNode* root, int targetSum) {
   		if(root == NULL)
   			return false;
		int res = traversal(root, targetSum - root->val);
		return res;
    }
*/
	//T 113
	bool traversal(TreeNode* node, int count)
	{
		//遇到可行路径的叶子节点
		if(node->left == NULL && node->right == NULL && count == 0)
			return true;		//一路减下来 是目标路径
		//其他叶子节点
		if(node->left == NULL && node->right == NULL)
			return false;

		//向左遍历
		if(node->left)
		{
			count -= node->left->val;
			bool ret = traversal(node->left,count);
			if(ret)						//如果存在 一路返回
				return true;
			count += node->left->val;	//回溯count 
		}
		//向右遍历
		if(node->right)
		{
			count -= node->right->val;
			bool ret = traversal(node->right,count);
			if(ret)						//如果存在 一路返回
				return true;
			count += node->right->val;	//回溯count 
		}
		return false;
	}
	
   	 vector<vector<int>> hasPathSum(TreeNode* root, int targetSum) {
   		if(root == NULL)
   			return false;
		int res = traversal(root, targetSum - root->val);
		return res;
    }
};

int main()
{
	Solution s;
	vector<double> res;
	
	//创建二叉树
	cout << "请以前序遍历方式输入一棵满二叉树,空节点用#表示" << endl;
	TreeNode* root = creat_bitree();
	s.hasPathSum(root,22);
	return 0;
} 

//1#23##65###

