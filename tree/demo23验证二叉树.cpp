#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <stack>

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

// 1. 二叉搜索树的中序遍历是有序数组
vector<int> vec;
void traversal(TreeNode* root)
{
    // 遍历到空节点
    if (root == nullptr)
        return;
    traversal(root->left);      // 左
    vec.push_back(root->val);   // 中
    traversal(root->right);     // 右
}

// bool isValidBST(TreeNode* root) {
//     vec.clear(); // 不加这句在leetcode上也可以过，但最好加上
//     traversal(root);
//     for (int i = 1; i < vec.size(); i++)
//     {
//         if (vec[i] <= vec[i-1])
//             return false;
//     }
//     return true;
// }


// // 2.直接递归遍历判断 
// // 记录当前最大值,中序遍历 是递增的
// // 力扣节点有INT_MIN
// long long maxVal = LONG_MIN;  
// bool isValidBST(TreeNode* root) 
// {
//     // 空节点
//     if (root == nullptr)
//         return true;

//     // 左子树
//     bool left = isValidBST(root->left);

//     // 比较当前节点和前一个节点的值 持续递增 中
//     if (root->val > maxVal)
//         maxVal = root->val;
//     else    // 不是二叉搜索树
//         return false;

//     // 右子树
//     bool right = isValidBST(root->right);

//     return left && right;
// }


// // 3. 递归法 双指针优化
// // 记录当前最大值,中序遍历 是递增的
// TreeNode* pre = nullptr;    // 记录前一个节点
// bool isValidBST(TreeNode* root)     
// {
//     // 空节点
//     if (root == nullptr)
//         return true;

//     // 左子树
//     bool left = isValidBST(root->left);

//     // 比较当前节点和前一个节点的值 持续递增 中
//     if (pre != nullptr && pre->val >= root->val) 
//         return false;
//     //  记录前一个节点
//     pre = root; 

//     // 右子树
//     bool right = isValidBST(root->right);

//     return left && right;
// }

// 4. 迭代法
bool isValidBST(TreeNode* root)     
{
    stack<TreeNode*> st;
    TreeNode* cur = root;
    TreeNode* pre = nullptr;
    while (cur != nullptr || !st.empty())
    {
        if (cur != nullptr)
        {
            st.push(cur);       // 遍历到最左下角
            cur = cur->left;    // 左
        }
        else
        {
            // 获取当前要处理的节点 中
            cur = st.top();
            st.pop();   
            if (pre != nullptr && pre->val >= cur->val)
                return false;
            pre = cur;

            cur = cur->right;       // 右
        }
    }
    return true;
}

int main()
{
    TreeNode* root = init_tree();
    vector<vector<int>> src = levelOrder(root);
    showDoubleVec(src);
    bool res = isValidBST(root);
    cout << res << endl;
    return 0;
}

TreeNode* init_tree()
{
    TreeNode* root = new TreeNode(2);
    root->left  = new TreeNode(1);
    root->right = new TreeNode(3);
    // root->left ->left  = new TreeNode(1);
    // root->left ->right = new TreeNode(3);
    // root->right->left  = new TreeNode(3);
    // root->right->right = new TreeNode(6);
    // root->left ->right->right = new TreeNode(1);
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