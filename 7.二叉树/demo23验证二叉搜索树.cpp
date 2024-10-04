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
	vector<int>result;	//中序遍历 结果数组
	//思路1：中序遍历 数据值是有序的 中序遍历数据存数组 ，判断数组是否单增
	//递归法
	bool traversal(TreeNode* root)
	{
		//假设为空嘛 
		if(root == NULL)
			return true;
		traversal(root->left);			//左
		result.push_back(root->val);	//中
		traversal(root->right);			//右
	}
	
//    bool isValidBST(TreeNode* root) {
//    	traversal(root);
//	    //判断数组是否单增
//	    for(int i = 1; i < result.size(); i++)
//	    {
//	        if(result[i] <= result[i-1])
//	            return false;
//	    }
//	    return  true;
//    }
    
    /****************思路2：直接递归遍历二叉树****************/
    long long maxVal = LONG_MIN;		//相当于记录上一节点的数值
	bool isValidBST(TreeNode* root) {
		//假设为空嘛 
		if(root == NULL)
			return true;
		bool left = isValidBST(root->left);		//左
		if(root->val > maxVal)					//中
			maxVal = root->val;
		else
			return false;
		bool right = isValidBST(root->right);	//右
		
		return left && right;
    }
    
    /**************双指针优化****************/
    TreeNode* pre = NULL;
    bool isValidBST2(TreeNode* root) {
		//假设为空嘛 
		if(root == NULL)
			return true;
		bool left = isValidBST(root->left);			//左
		
		if(pre != NULL && pre->val >= root->val)	//中
			return false;
		pre = root;
			
		bool right = isValidBST(root->right);		//右
		
		return left && right;
    }
    
    
    /*****************迭代法******************/
    //可以用迭代法模拟二叉树中序遍历，且与遍历普通二叉树模板类似
	//迭代法中序遍历稍加改动就可以了，变成二叉搜索树迭代模板，代码如下:
	bool isValidBST3(TreeNode* root)
	{
		stack<TreeNode*> st;
		TreeNode* cur = root;	//当前遍历指针
		TreeNode* pre = NULL;	//慢一步的指针
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
				
				if(pre != NULL && cur->val <= pre->val)
					return false;
					
				pre = cur;			//跟新慢指针,保存前一个访问的结点
				cur = cur->right;	//右
			}
		}
		return true;
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

