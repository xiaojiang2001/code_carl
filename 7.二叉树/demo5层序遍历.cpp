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
	//层序遍历 与层序遍历2  T102 T107
    vector<vector<int>> levelOrder(TreeNode* root) 
	{
		queue<TreeNode*> que;		//定义队列
		vector<vector<int>> res;	//结果容器
		TreeNode* node = root;		//当前节点
		int size = 0;
		//为空
		if(root != NULL)
			que.push(root);
		
		while(!que.empty())		
		{
			vector<int> vec;		//每一层的数组
			size = que.size();		//记录当前层节点数量
		
			//弹出当前层节点数量 并把下一层节点加入队列
			while(size--)
			{
				node = que.front();
				vec.push_back(node->val);	//队列数据加入结果数组
				que.pop();
				//左右子树入队列
				if(node->left)
					que.push(node->left);
				if(node->right)
					que.push(node->right);
			}
			//更新队列大小
			size = que.size();
			//层数组加入结果容器
			res.push_back(vec);
		}
		reverse(res.begin(),res.end());
		return res;
    }
    
    
    //二叉树的右视图  T199
    vector<int> rightSideView(TreeNode* root) 
	{
		queue<TreeNode*> que;	//定义队列
		vector<int> res;		//结果容器
		TreeNode* node = root;	//当前节点
		int size = 0;
		//为空
		if(root != NULL)
			que.push(root);
		
		while(!que.empty())		
		{
			size = que.size();	//记录当前层节点数量
			while(size--)		//弹出当前层节点数量 并把下一层节点加入队列
			{
				node = que.front();
				if(size == 0)	//每一层最右侧节点数据加入结果数组
					res.push_back(node->val);	
				que.pop();	
				
				//左右子树入队列
				if(node->left)
					que.push(node->left);
				if(node->right)
					que.push(node->right);
			}
			size = que.size();	//更新队列大小
		}
		return res;
    }
    
    
    //二叉树的层平均值  T637
    vector<double> averageOfLevels(TreeNode* root) 
	{
		queue<TreeNode*> que;	//定义队列
		vector<double> res;		//结果容器
		int sum = 0;
		TreeNode* node = root;	//当前节点
		int len = 0;
		int size = 0;
		//为空
		if(root != NULL)
			que.push(root);
		
		while(!que.empty())		
		{
			len = size = que.size();	//记录当前层节点数量
			while(size--)		//弹出当前层节点数量 并把下一层节点加入队列
			{
				node = que.front();
				sum += node->val;	
				que.pop();	
				
				//左右子树入队列
				if(node->left)
					que.push(node->left);
				if(node->right)
					que.push(node->right);
			}
			res.push_back(1.0 * sum / len);
			sum = 0;
			size = que.size();	//更新队列大小
		}
		return res;
    }


	//翻转二叉树 T226
    TreeNode* invertTree(TreeNode* root) 
	{
		if(root == NULL)
			return root;
		//前序遍历
		swap(root->left, root->right);	//中
		invertTree(root->left);			//左
		invertTree(root->right);		//右
		return root;
    }
};

int main()
{
	Solution s;
	vector<double> res;
	
	//创建二叉树
	cout << "请以前序遍历方式输入一棵满二叉树,空节点用#表示" << endl;
	TreeNode* root = creat_bitree();
	res = s.averageOfLevels(root);
	showVector(res);
	return 0;
} 


