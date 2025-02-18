#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0),left(nullptr),right(nullptr) {}
    TreeNode(int x) : val(x),left(nullptr),right(nullptr) {}
};

/*******************算法********************/
// 中序遍历二叉搜索树是递增的
void traversal(TreeNode* root, vector<int> &res)
{
    if(root == nullptr)
        return;
    
    traversal(root->left, res);
    res.push_back(root->val);
    traversal(root->right, res);
    return;
}

// 从一个数组中获取指定区间的数组 [left, right]
vector<int> getArray(vector<int> vec, int left, int right)
{
    vector<int> res;    
    if(left > right || left < 0 || right >= vec.size())
        return res;
    for (int i = left; i <= right; i++) {
        res.push_back(vec[i]);
    }
    return res;
}
TreeNode* cerate(vector<int> &array)
{
    if(array.size() == 0)
        return nullptr;
    // 中间数字变成新的根节点
    int mid = array.size() / 2;
    TreeNode* root = new TreeNode(array[mid]);
    vector<int> leftVec  =  getArray(array, 0, mid - 1);
    vector<int> rightVec =  getArray(array, mid + 1, array.size() - 1);
    root->left = cerate(leftVec);
    root->right = cerate(rightVec);
    return root;
}
TreeNode* balanceBST(TreeNode* root) {
    vector<int> vec;
    traversal(root, vec);
    TreeNode * newRoot = cerate(vec);
    return newRoot;
}

/*****************调试****************/
// 前序遍历
void preOrder(TreeNode* root, vector<int> &vec)
{
    if(root == nullptr)
        return;
    vec.push_back(root->val);
    preOrder(root->left, vec);
    preOrder(root->right, vec);
}

int main()
{
    TreeNode* root = new TreeNode(2);
    root->left =  new TreeNode(1);
    root->right =  new TreeNode(3);
    root->right->right =  new TreeNode(4);
    TreeNode* newRoot =  balanceBST(root);

    // 调试
    vector<int> res;
    preOrder(newRoot, res);
    for (auto num : res) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}