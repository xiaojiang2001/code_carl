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
	 //做完106 再独立做这题 显得轻而易举 对比学习
	TreeNode* traversal(vector<int>& nums) 
	{
		//1. 数组为空 返回
		if(nums.size() == 0)
			return NULL;
	
		//2. 获取最大值与最大值的下标
		int maxValue = *max_element(nums.begin(),nums.end());
		int maxPosition = max_element(nums.begin(),nums.end()) - nums.begin();
		TreeNode* root = new TreeNode(maxValue);
		
		//如果只有一个节点
		if(nums.size() == 1)
			return root;
		
		//3. 分割数组 形成左数组与右数组
		vector<int> leftNums;		//[0,pos)
		vector<int> rightNums;		//[Pos+1,size)
		for(int i = 0; i < maxPosition; i++)
			leftNums.push_back(nums[i]);
		for(int i = maxPosition + 1; i < nums.size(); i++)
			rightNums.push_back(nums[i]);
		
		//4. 递归处理左右区间
		root->left  = traversal(leftNums);
		root->right = traversal(rightNums);
			
		return root;
	}
	
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
	{
		if(nums.size() == 0)
			return NULL;
		return traversal(nums);
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
	s.constructMaximumBinaryTree(nums);
	return 0;
} 

//1#23##65###

