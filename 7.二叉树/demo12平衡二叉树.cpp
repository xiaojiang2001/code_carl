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
	int getHeight(TreeNode* node)
	{
		if(node == NULL)
			return 0;
			
		//计算左子树的高度 并判断是否为平衡二叉树
		int leftHeight  = getHeight(node->left);
		if(leftHeight == -1)	return -1;
		//计算右子树的高度 并判断是否为平衡二叉树
		int rightHeight = getHeight(node->right);
		if(rightHeight == -1)	return -1;
		
		//左右子树是平衡二叉树 但高度差大于1
		if(abs(leftHeight - rightHeight) > 1)
			return -1;
		else
			return 1 + max(leftHeight,rightHeight);
	}
	
	bool isBalanced(TreeNode* root) {
		int ret  = getHeight(root);
		if(ret != -1)
			return true;
		else
			return false;
    }
//迭代求深度
	int getDepth(TreeNode* cur)
	{
		stack<TreeNode*> st;
		if(cur != NULL)
			st.push(cur);
		int depth = 0;
		while(!st.empty())
		{
			TreeNode* node = st.top();	//栈顶节点
			st.pop();
			if(node != NULL)
			{
				if(node->right)	st.push(node->right);
				if(node->left)	st.push(node->left);
			}
			else
			{
				
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
	s.isBalanced(root);
	cout << "node num:" << endl;
	return 0;
} 

//1#23##65###

