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
	//1. 看成有序的数组(中序遍历的结果) 
	//实际累加遍历顺序：右 中 左
	//如果是数组 双指针 那么遍历二叉搜索树 也用双指针
	TreeNode* pre = NULL;			//记录前一个节点
	void traversal(TreeNode* cur) 
	{
		if(cur == NULL)
			return;	

		//右
		traversal(cur->right);
		//中
		if(pre != NULL)
			cur->val += pre->val;
		pre = cur;
		//左
		traversal(cur->left);
	}
//	TreeNode* convertBST(TreeNode* root) {
//		traversal(root);
//		return root;
//    }
	
	
	//迭代法也可以 并且迭代法是个模板题
	TreeNode* convertBST(TreeNode* root)
	{	
		if(root == NULL)
			return NULL;
		TreeNode* cur = root;
		TreeNode* pre = NULL;
		stack<TreeNode*> st;
		while(cur != NULL || !st.empty())
		{
			//右
			if(cur != NULL)
			{
				st.push(cur);
				cur = cur->right;	
			}
			else
			{
				//中
				cur = st.top();
				st.pop();
				if(pre != NULL)
					cur->val += pre->val;
				pre = cur;
				
				//左
				cur = cur -> left;
			}
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
