#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr) { }
};

// 通用功能函数
TreeNode* init_tree();
vector<vector<int>> levelOrder(TreeNode* root);
void showDoubleVec(vector<vector<int>>& vecs);

TreeNode* traversal(TreeNode* root, TreeNode* p, TreeNode* q)
{
    // 空节点
    if (root == nullptr)
        return nullptr;
    // 找到目标值
    if (root == p || root == q)
        return root;
    
    // 遍历左右子树是否存在q,q
    TreeNode* left  = traversal(root->left, p, q); 
    TreeNode* right = traversal(root->right, p,q);

    // 判断左右子树知否为空
    if (left != nullptr && right != nullptr)
        return root;
    if (left != nullptr && right == nullptr)
        return left;
    if (left == nullptr && right != nullptr)
        return right;
    
    return nullptr;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return traversal(root,p,q);
}

int main()
{
    TreeNode* root = init_tree();
    vector<vector<int>> src = levelOrder(root);
    showDoubleVec(src);
    // TreeNode* resRoot = lowestCommonAncestor(root,root);
    // vector<vector<int>> res = levelOrder(resRoot);
    // showDoubleVec(res);
    cout  << endl;
    return 0;
}

TreeNode* init_tree()
{
    TreeNode* root = new TreeNode(1);
    root->left  = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left ->left  = new TreeNode(3);
    root->left ->right = new TreeNode(4);
    root->right->left  = new TreeNode(4);
    root->right->right = new TreeNode(3);
    return root;
}
vector<vector<int>> levelOrder(TreeNode* root)
{
    queue<TreeNode*> que;
    vector<vector<int>> res;
    if (root != nullptr) {
        que.push(root);
    }
    
    while (!que.empty())
    {
        vector<int> vec;
        //获取每一层的节点个数并处理
        int size = que.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            vec.push_back(node->val);
            que.pop();
            // 把下一层的非空节点加入队列
            if(node->left)      que.push(node->left);
            if(node->right)     que.push(node->right);
        }
        res.push_back(vec);
    }
    return res;
}
void showDoubleVec(vector<vector<int>>& vecs)
{
    for (auto vec: vecs){
        for (int num: vec){
            cout <<  num <<  " ";
        }
        cout << endl;
    }
    cout << endl;
}