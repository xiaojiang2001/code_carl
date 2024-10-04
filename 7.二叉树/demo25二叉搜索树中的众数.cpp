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
	 /*思路1: 遍历树 将数值存入map, 并统计出现的次数，根据次数排序，返回频率最大的几个数*/
/*
	// map<int, int> key:元素，value:出现频率
	void traversal(TreeNode* node,unordered_map<int, int>& mp)
	{
		if(node == NULL)
			return;

		mp[node->val]++;				//中 统计元素频率
		traversal(node->left, mp);		//左 
		traversal(node->right, mp);		//右
		return;
	}
	//排序仿函数
	bool static cmp(const pair<int,int>& a, const pair<int, int> & b)
	{
		return a.second > b.second;
	}
	
    vector<int> findMode(TreeNode* root) 
	{
		vector<int> result;					//结果容器
		unordered_map<int, int> resMap;		//存放键值对的map
		if(root == NULL)
			return result;
		
		traversal(root, resMap);
		//map 转 对组类型的vector
		vector<pair<int,int>> vec(resMap.begin(), resMap.end());
		sort(vec.begin(), vec.end(), cmp); // 给频率排个序
		for(int i = 0; i < vec.size(); i++)
		{
			if(vec[i].second == vec[0].second)	//判断出现频率最大的几个数
				result.push_back(vec[i].first);	//把频率最大的几个数存入结果数组
			else
				break;
		}
		return result;
	}
*/

	/********思路2 利用二叉搜索树 递归遍历 + 双指针遍历********/
	TreeNode* pre = NULL;
	int maxCnt = 0;			//最大频率
	int cnt = 0;			//单个元素频率
	vector<int> res;		//结果集
	void traversal(TreeNode* node)
	{
		if(node == NULL)
			return;
			
		traversal(node->left);	//左
		
		if(pre == NULL)			//最初
			cnt = 1;
		else if(pre->val == node->val)	//数值相同 累加
			cnt++;	
		else 					//新数据
			cnt = 1;
		pre = node;				//更新旧指针
		
		/**********核心细节代码区****************/
		if(cnt == maxCnt)		//收获频率最大的数
			res.push_back(node->val);
		else if(cnt > maxCnt)	//更新最大频率
		{
			maxCnt = cnt;
			res.clear();				//☆有更长的频率 之前存入的结果都作废
			res.push_back(node->val);	//当前新的长度的数记得存进去
		}
		
		traversal(node->right);	//右
	}
	
//	vector<int> findMode(TreeNode* root) 
//	{
//		traversal(root);
//		return res;
//	}
	
	/********思路3 迭代法********/
	vector<int> findMode(TreeNode* root) 
	{
		int maxCnt = 0;			//最大频率
		int cnt = 0;			//单个元素频率
		vector<int> res;
		if(root == NULL)
			return res;
		stack<TreeNode*> st;
		TreeNode* pre = NULL;
		TreeNode* cur = root;
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
				
				if(pre == NULL)			//最初
					cnt = 1;
				else if(pre->val == cur->val)	//数值相同 累加
					cnt++;	
				else 					//新数据
					cnt = 1;
				pre = cur;				//更新旧指针
				
				/**********核心细节代码区****************/
				if(cnt == maxCnt)		//收获频率最大的数
					res.push_back(cur->val);
				else if(cnt > maxCnt)	//更新最大频率
				{
					maxCnt = cnt;
					res.clear();				//☆有更长的频率 之前存入的结果都作废
					res.push_back(cur->val);	//当前新的长度的数记得存进去
				}
				
				cur = cur->right;	//右
			}
		}
		return res;	
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
	res = s.findMode(root);
	showVector(res);
	return 0;
} 

//1#23##65###

