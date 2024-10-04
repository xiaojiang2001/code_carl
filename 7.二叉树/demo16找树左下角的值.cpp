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
	//递归法
	int maxDepth = -1;
	int res;
	
	//递归函数
	void traversal(TreeNode* node, int depth)
	{
		//找到叶子节点
		if(node->left == NULL && node->right == NULL)
		{
			if(depth > maxDepth)
			{
				maxDepth = depth;
				res = node->val;
			}	
		}
		
		//中 不需要处理
		
		if(node->left)		//左
		{
			depth++;		//加入左节点 深度+1
			traversal(node->left, depth);
			depth--;		//回溯
		}
		
		if(node->right)		//右
		{
			depth++;		//加入右节点 深度+1
			traversal(node->right, depth);
			depth--;		//回溯
		}
	}
	
	
	int findBottomLeftValue(TreeNode* root) {
		traversal(root,0);
		return res;
	}
/*
	//层序遍历
	int findBottomLeftValue(TreeNode* root) {
		if(root == NULL)
			return 0;
		int size;
		queue<TreeNode*> que;
		int ret;			//记录每层最左边的节点值
		que.push(root);
		while(!que.empty())
		{
			//获取每层的节点个数
			size = que.size();
			ret =  que.front()->val;
			while(size--)
			{
				TreeNode* node = que.front();
				que.pop();
				if(node->left)
					que.push(node->left);
				if(node->right)
					que.push(node->right);
			}
			size = que.size();	//跟新
		}
		return ret;
    }
*/
};

int main()
{
	Solution s;
	vector<double> res;
	
	//创建二叉树
	cout << "请以前序遍历方式输入一棵满二叉树,空节点用#表示" << endl;
	TreeNode* root = creat_bitree();
	s.findBottomLeftValue(root);
	return 0;
} 

//1#23##65###

