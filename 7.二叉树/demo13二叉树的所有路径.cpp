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
	
	void traversal(TreeNode* node, vector<int>&path, vector<string>& res)
	{
		//中 先把叶子节点的值放入path
		path.push_back(node->val);
		
		//访问到子节点
		if(node->left == NULL && node->right == NULL)
		{
			string buf;
			for(int i = 0; i < path.size()-1; i++)
			{
				buf += to_string(path[i]);
				buf += "->";
			}
			buf += to_string(path[path.size() - 1]);
			res.push_back(buf);
			return;
		}
		
		//左
		if(node->left)
		{
			traversal(node->left, path, res);
			path.pop_back();	//回溯
		}
		
		//右
		if(node->right)
		{
			traversal(node->right, path, res);
			path.pop_back();	//回溯
		}
			
	}
	
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<int> path;
		vector<string> res;
		if(root == NULL)
			return res;
		traversal(root,path,res);
		return res;
    }
    
    vector<string> binaryTreePaths2(TreeNode* root) {
		vector<string> res;
		stack<TreeNode *> st;
		if(root == NULL)
			return res;
		st.push(root);
		while(!st.empty())
		{
			TreeNode* node = st.top();
			st.pop();
			
		}
		
		
		
		return res;
    }
};

int main()
{
	Solution s;
	vector<double> res;
	
	//创建二叉树
	cout << "请以前序遍历方式输入一棵满二叉树,空节点用#表示" << endl;
	TreeNode* root = creat_bitree();
	s.binaryTreePaths(root);
	return 0;
} 

//1#23##65###

