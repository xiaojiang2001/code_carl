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
	//按照二叉搜索树的规则去遍历，遇到空节点就插入节点就可以了。
	//理解思路 很重要
//    TreeNode* insertIntoBST(TreeNode* root, int val) 
//    {
//        if (root == NULL)
//        {
//            TreeNode* node = new TreeNode(val);
//            return node;
//        }
//        if (val < root->val) 
//			root->left = insertIntoBST(root->left, val);
//        if (val > root->val) 
//			root->right = insertIntoBST(root->right, val);
//        return root;
//	}
	
	//迭代法
	TreeNode* insertIntoBST(TreeNode* root, int val) 
	{
		if(root == NULL)
		{
			TreeNode* node = new TreeNode(val);
			return node;
		}
		
		TreeNode* cur = new TreeNode();
		TreeNode* pre = root;	//这个很重要，需要记录上一个节点，否则无法赋值新节点
		cur = root;
		while(cur != NULL)
		{
			pre = cur;			//跟新慢指针
			
			if(cur->val > val)
				cur = cur->left;
			else if(cur->val < val)
				cur = cur->right;
		}
		//加入新节点
		TreeNode* node = new TreeNode(val);
		if(pre->val > val)
			pre->left = node;	// 此时是用pre节点的进行赋值
		else	
			pre->right = node;
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
