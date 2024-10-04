#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>

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

void showVector(vector<int> &vp)
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
	//没有想法 二刷回顾
	//因为是有序树，所以 如果 中间节点是 q 和 p 的公共祖先，那么 中节点的数组 一定是在 [p, q]区间的。
	//即 中节点 > p && 中节点 < q 或者 中节点 > q && 中节点 < p。
	TreeNode* traversal(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if(root == NULL)
			return NULL;	
		
		if(root->val > p->val && root->val > q->val)
			root =  traversal(root->left, p, q);	//左
		else if(root->val < p->val && root->val < q->val)
			root =  traversal(root->right, p, q);	//右
		else
			return root;
		return root;
	}
	
//	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
//	{
//        TreeNode* ret = traversal(root, p, q);
//        return ret;
//	}
	
	//迭代法
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
	{
		if(root == NULL)
			return NULL;
		while(root)
		{
			if(root->val > p->val && root->val > q->val)
				root = root->left;
			else if(root->val < p->val && root->val < q->val)
				root = root->right;
			else
				return root;	
		}
		return root;	
	}
};

int main()
{
	Solution s;
	vector<int> res;
	vector<int> nums = {9,3,15,20,7};
	vector<int> postorder = {9,15,7,20,3};
	//创建二叉树
	cout << "请以前序遍历方式输入一棵满二叉树,空节点用#表示" << endl;
	TreeNode* root = creat_bitree();
	//res = s.findMode(root);
	showVector(res);
	return 0;
} 

//1#23##65###

