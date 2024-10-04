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
/*********获取二叉树的最大深度********/
	//递归法 递归函数
	int getHeight(TreeNode* node)
	{
		if(node == NULL)
			return 0;
		int leftDepth  = getHeight(node->left);		//左
		int rightDepth = getHeight(node->right);	//右
		return 1 + max(leftDepth,rightDepth);		//中
	}	
//	int maxDepth(TreeNode* root) {
//		return getHeight(root);
//    }
    
    //使用层序遍历
    int maxDepth(TreeNode* root)
    {
    	//入口参数检查
    	if(root == NULL)
    		return 0;
    	int depth = 0;				//树深度
    	int size = 0;				//没一层节点个数
    	queue<TreeNode*> que;	//存放节点队列
    	que.push(root);
    	
    	while(!que.empty())
    	{
    		size = que.size();	 //记录当前层节点数量
			while(size--)
			{	
				TreeNode* node = que.front();
    			que.pop();
	    			
	    		if(node->left)
					que.push(node->left);
				if(node->right)
					que.push(node->right);
			}
			size = que.size();	 //更新队列大小
			depth++;	
		}
		return depth;
	}
/*********获取二叉树的最小深度********/
	//递归法
/*
	int getMinHeight(TreeNode* node)
	{
		if(node == NULL)
			return 0;
		int leftDepth  = getMinHeight(node->left);		//左
		int rightDepth = getMinHeight(node->right);		//右
		
		//中
		//左子树为空 返回右侧深度
		if(node->left == NULL && node->right != NULL)
			return rightDepth + 1;
		//右子树为空 返回左侧深度
		else if(node->left != NULL && node->right == NULL)
			return leftDepth + 1;
		//返回左右子树最深度
		else
			return 1 + min(leftDepth, rightDepth);
	}
	int minDepth(TreeNode* root) {
		return getMinHeight(root);
    } 
*/
	//迭代法 层序遍历
	int minDepth(TreeNode* root) 
	{
		if(root == NULL)
			return 0;
		int depth = 0;
		int size = 0;
		queue<TreeNode*> que;
		que.push(root);
		while(!que.empty())
		{
			size = que.size();	//获取队列大小
			depth++;
			while(size--)
			{
				TreeNode* node = que.front();
				que.pop();
				if(node == NULL)
					continue;
				if(node->left)
					que.push(node->left);
				if(node->right)
					que.push(node->right);
				if(node->left == NULL && node->right == NULL)
					return depth;
			}
		}
		return depth;
	}
};

int main()
{
	Solution s;
	vector<double> res;
	
	//创建二叉树
	cout << "请以前序遍历方式输入一棵满二叉树,空节点用#表示" << endl;
	TreeNode* root = creat_bitree();
	int len = s.minDepth(root);
	cout << "depth:" << len;
	return 0;
} 

//1#23##65###

