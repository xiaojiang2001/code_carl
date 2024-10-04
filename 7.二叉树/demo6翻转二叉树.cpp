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
	//翻转二叉树 T226 递归法
    TreeNode* invertTree(TreeNode* root) 
	{
		if(root == NULL)
			return root;
		//前序遍历
		swap(root->left, root->right);	//中
		invertTree(root->left);			//左
		invertTree(root->right);		//右
		return root;
    } 
    
    //迭代法翻转二叉树
    TreeNode* invert2Tree(TreeNode* root) 
    {
    	if(root == NULL)
    		return root;
    	stack<TreeNode*> st;
    	st.push(root);
    	while(!st.empty())
    	{
    		TreeNode* node = st.top();
    		st.pop();
    		swap(node->left, node->right);
    		if(node->right)
    			st.push(node->right);
    		if(node->left)
    			st.push(node->left);
		}
	}
	
	
	//层序法翻转二叉树
    TreeNode* invert3Tree(TreeNode* root) 
    {
    	queue<TreeNode*> que;
    	int size;
    	if(root != NULL)
    		que.push(root);
    	while(!que.empty())
    	{
    		size = que.size();
    		while(size--)
    		{
    			TreeNode* node = que.front();
    			que.pop();
    			swap(node->left, node->right);
    			if(node->left)
	    			que.push(node->left);
	    		if(node->right)
	    			que.push(node->right);
			}
		}
		return root;
	}
};

int main()
{
	Solution s;
	vector<double> res;
	
	//创建二叉树
	cout << "请以前序遍历方式输入一棵满二叉树,空节点用#表示" << endl;
	TreeNode* root = creat_bitree();
	s.invertTree(root);
	//showVector(res);
	return 0;
} 


