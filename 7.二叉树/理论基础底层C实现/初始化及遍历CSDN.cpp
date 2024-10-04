#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct BiTree{
	char data;
	BiTree *left;
	BiTree * right;
	BiTree() : data(0), left(nullptr), right(nullptr) {}
    BiTree(int x) : data(x), left(nullptr), right(nullptr) {}
    BiTree(int x, BiTree *left, BiTree *right) : data(x), left(left), right(right) {}
}; 


class Solution {
public:
    void postorder(BiTree* node, vector<int>& res)
    {
    	if(node == NULL)
    		return;
    	postorder(node->left,res);
    	postorder(node->right,res);
    	res.push_back(node->data);
	}

    vector<int> postorderTraversal(BiTree* root) 
	{
		 vector<int> res;
		 postorder(root,res);
		 return res;
    }
};

BiTree* creat_bitree()
{
	char dat;
	BiTree* root;
	scanf("%c",&dat);
	//空树
	if(dat == '#')
		return NULL;
	//封装节点
	root = (BiTree*)malloc(sizeof(BiTree));	
	if(root == NULL)
	{
		printf("malloc failed\n");
		return NULL;
	}
	//数据域 左右子树地址赋值
	root->data = dat;
	root->left = creat_bitree();
	root->right = creat_bitree();
	return root;
}



void ShowNodeData(BiTree *treeNode)
{
	cout<<treeNode->data<<"    ";					//直接输出结点数据 
} 

void DLRTree(BiTree *treeNode)
{
	if(treeNode)
	{
		//cout<<"e";
		ShowNodeData(treeNode);					//显示结点内容
		//cout<<"333";
		DLRTree(treeNode->left);				//显示左子树内容
		//cout<<"5555";
		DLRTree(treeNode->right);				//显示右子树内容 
	}
} 


BiTree * sTree()
{
	BiTree * node;
	node = new BiTree;
	return node;
}

BiTree * InitTree()
{
	BiTree * node;
	if(node = new BiTree)		//申请内存 
	{
		cout<<"请先输入一个根节点数据："<<endl;
		cin>>node->data;
		node->left=NULL;
		node->right=NULL;

		return node;
	}
	return NULL;
}

void AddTreeNode(BiTree * & TreeNode)//初始化并构造二叉树 
{
	cout<<"请先输入一个根节点数据："<<endl;
	cin>>TreeNode->data;
	TreeNode->left=NULL;
	TreeNode->right=NULL;
	string isit;
	cout<<"是否继续"; 
	cin>>isit;
	if(isit == "yes")
	{
		BiTree *s = new BiTree;
		cout<<"左边是1 ，右边是2";
		int n;
		cin>>n;
		if(n == 1)
		{
			TreeNode->left = s;
			AddTreeNode(s);
		}
		else if(n == 2)
		{
			TreeNode->right = s;
			AddTreeNode(s);
		}
		else if(n == 3)
		{
			TreeNode->left = s;
			AddTreeNode(s);
			BiTree *ss = new BiTree;
			TreeNode->right = ss;
			AddTreeNode(ss);
		}	 
	}
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

int main()
{
	Solution s;
	vector<int> res;
	
	//创建二叉树
	BiTree* root = creat_bitree();
	res = s.postorderTraversal(root);
	showVector(res);
	return 0;
} 




