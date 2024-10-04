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
	//递归 生成节点函数 返回左右区间下的根节点 左闭右闭
	
	//1. 为什么强调平衡二叉树
	//2. 关键性思路  选取中间节点 构造左右区间
	//3. 切割区间的定义 
	
	TreeNode* traversal(vector<int>& nums, int left, int right) 
	{
		if(left > right)	
			return NULL;
		int mid = left + (right - left) / 2;
		TreeNode* node = new TreeNode(nums[mid]);
		node->left =  traversal(nums, left, mid - 1);	
        node->right = traversal(nums, mid + 1, right);
        return node;
	}
	
    TreeNode* sortedArrayToBST(vector<int>& nums) 
	{
		TreeNode* root = traversal(nums, 0, nums.size()-1);
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
