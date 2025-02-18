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

bool traversal(TreeNode* p, TreeNode* q)
{
    // 结束条件
    if(p == nullptr && q == nullptr)
        return true;
    if(p == nullptr && q != nullptr || p != nullptr && q == nullptr)
        return false;
    if(p->val != q ->val)
        return false;
    

    bool left  = traversal(p->left, q->left);
    bool right = traversal(p->right, q->right);
    return left && right;
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    bool ret = traversal(p, q);
    return ret;
}

int main()
{

}