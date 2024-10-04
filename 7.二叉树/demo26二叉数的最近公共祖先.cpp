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
	//p q 从下往上遍历 一旦交汇 则是公共祖先
	//无法从下往上遍历 但可以从下往上处理 判断左右子树是否出现p q
	//往上传递在回溯中处理 遍历顺序为后序 左右中
	TreeNode* traversal(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if(root == NULL)
			return NULL;
		if(root == p || root == q)	//遇到目标值 包含第二种情况
			return root;		
			
		TreeNode* left  = traversal(root->left, p, q);	//左
		TreeNode* right = traversal(root->right, p, q);	//右
		
		//中
		if(left != NULL && right != NULL)		//左右子树包含目标值
			return root;
		else if(left == NULL && right != NULL)	//右子树包含目标值
			return right;
		else if(left != NULL && right == NULL)	//左子树包含目标值
			return left;
		else									//左右子树不包含目标值
			return NULL;
	}
	
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
	{
        TreeNode* ret = traversal(root, p, q);
        return ret;
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

