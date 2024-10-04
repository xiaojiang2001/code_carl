#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

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

/****************************算法******************************/
class Solution {
public:
//前序遍历
    vector<int> preorderTraversal(TreeNode* root) 
	{
		stack<TreeNode*> st;	//栈
		vector<int> res;		//结果容器
		TreeNode* node;			//栈顶节点
		st.push(root);			//根节点入栈
		while(!st.empty())		
		{
			node = st.top();	//获取栈顶节点并弹出
			st.pop();
			//中
			if(node != NULL)	//非空元素加入数组
				res.push_back(node->val);
			else
				continue;
			//左右节点 先放右子树再放左子树入栈
			//这样出栈才达到中左右顺序
			if(node->right)				//空节点不入栈
				st.push(node->right);
			if(node->left)
				st.push(node->left);
		}
		return res;
    }

    vector<int> postorderTraversal(TreeNode* root) 
	{
		stack<TreeNode*> st;	//栈
		vector<int> res;		//结果容器
		TreeNode* node;			//栈顶节点
		st.push(root);			//根节点入栈
		while(!st.empty())
		{
			node = st.top();	//获取栈顶节点并弹出
			st.pop();
			//中
			if(node != NULL)	//非空元素加入数组
				res.push_back(node->val);
			else
				continue;
			//左右节点 先放左子树再放右子树入栈
			//出栈顺序: 中右左
			if(node->left)				
				st.push(node->left);
			if(node->right)
				st.push(node->right);
		}
		//将结果反转之后就是左右中的顺序了
		reverse(res.begin(), res.end());
		return res;
    }

//中序遍历
 	vector<int> middleorderTraversal(TreeNode* root) 
	{
		stack<TreeNode*> st;	//栈 记录遍历过的节点
		vector<int> res;		//结果容器
		TreeNode* cur = root;	//遍历节点
		while(cur != NULL || (!st.empty()))
		{
			if(cur != NULL)			// 指针来访问节点，访问到最底层
			{
				st.push(cur);		//访问指针入栈
				cur = cur->left;	//左
			}
			else					//到左端极限
			{
				cur = st.top();		//记录栈弹出节点
				st.pop();			
				res.push_back(cur->val);	//节点元素放进数组 中
				cur = cur->right;		//右
			}
		}
		return res;
    }
};

int main()
{
	Solution s;
	vector<int> res;
	
	//创建二叉树
	cout << "请以前序遍历方式输入一棵满二叉树,空节点用#表示" << endl;
	TreeNode* root = creat_bitree();
	res = s.preorderTraversal(root);
	showVector(res);
	return 0;
} 


