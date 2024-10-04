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
	//需要调节二叉树的结构最难 题目比较难 情况比较多
	TreeNode* deleteNode(TreeNode* root, int key)
	{
		// 1. 没找到删除的节点
		if(root == NULL)		
			return NULL;
		
		// 找到删除的节点
		if(root->val == key)
		{
			// 2. 删除叶子节点 左为空 右为空
			if(root->left == NULL && root->right == NULL)
			{
				delete root;
				return NULL;	//单层递归时候 root左右子树接收NUULL
			}
					
			// 3. 待删除的节点 左不空 右为空
			if(root->left != NULL && root->right == NULL)
			{
				TreeNode* res = root->left;
				delete root;
				return res;
			}
			// 4. 待删除的节点 左为空 右不空 
			else if(root->left == NULL && root->right != NULL)	
			{
				TreeNode* res = root->right;
				delete root;
				return res;
			}
			// 5. 左不空 右不空 最难的部分 比较难想
			else
			{
				TreeNode* temp = root;			//暂存待删除的节点
				TreeNode* cur = root->right;	//获取右子树的根节点
				while(cur->left !=  NULL)		//右子树不断遍历左节点
				{
					cur = cur->left;
				}
				cur->left = root->left;			//把左子树挂在右子树最左边
				root = root->right;
				delete temp;
				return root;
			}		
		}
	
		
		//单层递归逻辑
		if(key < root->val)
			root->left = deleteNode(root->left, key);
		if(key > root->val)
			root->right = deleteNode(root->right, key);
		return root;
	}
	
	//迭代法
	TreeNode* insertIntoBST(TreeNode* root, int val) 
	{
		if(root == NULL)
		{
			TreeNode* node = new TreeNode(val);
			return node;
		}
		
		TreeNode* cur = new TreeNode();
		TreeNode* pre = root;				//这个很重要，需要记录上一个节点，否则无法赋值新节点
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
