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
	/****************递归法 数据存入数组******************/
/*
	vector<int> res;
	void traversal(TreeNode* node)
	{
		if(node == NULL)
			return;

		traversal(node->left);		//左
		res.push_back(node->val);	//中
		traversal(node->right);		//右
	}

    int getMinimumDifference(TreeNode* root) 
	{
		traversal(root);
		if(res.size() < 2)
			return 0;
    	int minDiff	= abs(res[1] - res[0]);
    	for(int i = 2; i < res.size(); i++)
 			minDiff = min(minDiff, res[i] - res[i-1]);
 
		return minDiff;
    }
*/
    /************************************************/

    /*******************递归双指针法 ***************/
/*
    TreeNode* pre = NULL;
    int minDiff = INT_MAX;
    void traversal(TreeNode* node)
	{
		if(node == NULL)
			return;

		traversal(node->left);		//左

		//中
		if(pre != NULL)
			minDiff = min(minDiff, node->val - pre->val);
		pre = node;		//跟新慢指针

		traversal(node->right);		//右
	}

	int getMinimumDifference(TreeNode* root) 
	{
		traversal(root);
		return minDiff;
    }
*/
	/************************************************/
	
	
	 /****************迭代法***************/
	int getMinimumDifference(TreeNode* root) 
	{	
		if(root == NULL)
			return 0;
		stack<TreeNode*>st;
		TreeNode* pre = NULL;
		TreeNode* cur = root;
		int minDiff = INT_MAX;
		while(cur != NULL || !st.empty())
		{
			if(cur != NULL)
			{
				st.push(cur);
				cur = cur->left;	//左
			}
			else
			{
				cur = st.top();		//中
				st.pop();
				if(pre != NULL)
					minDiff = min(minDiff, cur->val - pre->val);
				pre = cur;
				
				cur = cur->right;	//右
			}
		}
		return minDiff;
    }
};

int main()
{
	Solution s;
	vector<double> res;
	vector<int> nums = {9,3,15,20,7};
	vector<int> postorder = {9,15,7,20,3};
	//创建二叉树
	//cout << "请以前序遍历方式输入一棵满二叉树,空节点用#表示" << endl;
	//TreeNode* root = creat_bitree();
	return 0;
} 

//1#23##65###

