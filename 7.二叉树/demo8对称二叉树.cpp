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
	//对称二叉树 递归法 T101
	bool compare(TreeNode *left, TreeNode *right)
	{
		//左右一边为空
		if(left == NULL && right != NULL)
			return false;
		else if (left != NULL && right == NULL) 
			return false;
		//都为空
		else if(left == NULL && right == NULL)
			return true;
		//都不为空
		else
		{
			//不对称
			if(left->val != right ->val)
				return false;
			//对称 处理递归单层逻辑
			else
			{
				//判断左右节点是否对称
				bool outSide = compare(left->left,  right->right);	//左子树:	左	//左子树: 右
				bool inSide  = compare(left->right, right->left);	//左子树:	右	//左子树: 左	
				//返回结果到父节点
				if(outSide == true && inSide == true)	//左子树:	中	//左子树: 中
					return true;
				else
					return false;	
				//左子树:	左右中		右子树： 右左中  都是后续遍历
			}
		}
	}
	//掉用递归函数
//    bool isSymmetric(TreeNode* root) 
//	{
//		if(root == NULL)
//			return true;
//		bool ret = compare(root->left, root->right);
//		return ret;
//	}
	
	
	//迭代实现 使用队列
	bool isSymmetric(TreeNode* root) 
	{
		if(root == NULL)
			return true;
		queue<TreeNode*> que;
		//左右
		que.push(root->left);
		que.push(root->right);
		
		while(!que.empty())
		{
			
			TreeNode* leftNode  = que.front();	que.pop();	//左子树根节点
			TreeNode* rightNode = que.front();	que.pop();	//右子树根节点
			if(leftNode == NULL && rightNode == NULL)		//左右子树都为空 对称
				continue;
			else if(leftNode == NULL && rightNode != NULL)
				return false;
			else if(leftNode != NULL && rightNode == NULL)
				return false;
			
			//保证节点不为空
			if(leftNode -> val == rightNode -> val)		//数值相等 继续判断子树
			{
				que.push(leftNode->left);
				que.push(rightNode->right);
				que.push(leftNode->right);
				que.push(rightNode->left);
			}
			else										//都不为空 但数值不等 不对称
				return false;
			
		}
		return	true;
	}		
};

int main()
{
	Solution s;
	vector<double> res;
	
	//创建二叉树
	cout << "请以前序遍历方式输入一棵满二叉树,空节点用#表示" << endl;
	TreeNode* root = creat_bitree();
	s.isSymmetric(root);
	return 0;
} 


