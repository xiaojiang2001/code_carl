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
	TreeNode* traversal(vector<int>& inorder, vector<int>& postorder)
	{
		//1. 后续数组为空 返回
		if(postorder.empty())
			return NULL;
		
		//2. 获取根节点的值(后续数组中的最后一个值)
		int val = postorder[postorder.size() - 1];

		TreeNode* root = new TreeNode(val);
		if(postorder.size() == 1)		//只有1个叶子节点
			return root;

		//3. 找切割点 计算根节点的值在中序数组中的下标 
		int idx;		//根节点值在中序数组中的下标
		for(idx = 0; idx < postorder.size(); idx++)
		{
			if(inorder[idx] == val)
				break;			
		}
		
	

		
		//要确定顺序得看后序，因为中序不知道中间节点在哪
		//4. 切割中序数组
		vector<int> inleft;		//左中序	[0,idx)
		vector<int> inright;	//右中序	[idx+1,size)
		for(int i = 0; i < idx; i++)		
			inleft.push_back(inorder[i]);	
		for(int i = idx+1; i < inorder.size(); i++)	
			inright.push_back(inorder[i]);

		//5. 切割后续数组
		vector<int> postleft;		//左后序	[0,size)
		vector<int> postright;		//右后序	[inleft.size, size)
		for(int i = 0; i < inleft.size(); i++)	
			postleft.push_back(postorder[i]);
		//左侧数组长度是一样的
		for(int i = inleft.size(); i < postorder.size() - 1; i++)	
			postright.push_back(postorder[i]);
		

/*
		cout << "------------debug------------------" << endl;
		cout << "------------inorder------------------"<< endl;
		for(int i = 0; i < inorder.size();i++)
			cout << inorder[i] << " ";
		cout << endl;
		cout << "------------postorder------------------"<< endl;
		for(int i = 0; i < postorder.size();i++)
			cout << postorder[i] << " ";
		cout << endl;

		cout << "val = " << val << endl;
		cout << "idx = " << idx << endl;

		cout << "------------inleft------------------"<< endl;
		for(int i = 0; i < inleft.size();i++)
			cout << inleft[i] << " ";
		cout << endl;

		cout << "------------inright------------------"<< endl;
		for(int i = 0; i < inright.size();i++)
			cout << inright[i] << " ";
		cout << endl;

		cout << "------------postleft------------------"<< endl;
		for(int i = 0; i < postleft.size();i++)
			cout << postleft[i] << " ";
		cout << endl;

		cout << "------------postright------------------"<< endl;
		for(int i = 0; i < postright.size();i++)
			cout << postright[i] << " ";
		cout << endl;
*/		
		
		
		
		//6. 递归处理左区间、右区间
		root->left = traversal(inleft,postleft);
		root->right = traversal(inright,postright);
		return root;
	}
	
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
	{
	
		if(inorder.size() == 0 || postorder.size() == 0)
			return NULL;
		return traversal(inorder, postorder);
    }
};

int main()
{
	Solution s;
	vector<double> res;
	vector<int> inorder = {9,3,15,20,7};
	vector<int> postorder = {9,15,7,20,3};
	//创建二叉树
	//cout << "请以前序遍历方式输入一棵满二叉树,空节点用#表示" << endl;
	//TreeNode* root = creat_bitree();
	s.buildTree(inorder,postorder);
	return 0;
} 

//1#23##65###

