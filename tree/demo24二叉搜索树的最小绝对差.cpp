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


// 方法1：遍历到数组 判断数组中的最小绝对差
// 方法2：递归 + 双指针
// 方法3：迭代法 + 双指针
TreeNode* pre = nullptr;
int res = INT_MAX;
void traversal(TreeNode* root)
{
    // 空节点
    if (root == nullptr)
        return;

    //左
    traversal(root->left);

    // 中
    if (pre != nullptr) {
        int dis = abs(root->val - pre->val);
        if (dis < res)
            res = dis;        
    }
    pre = root;
    
    // 右
    traversal(root->right);

    return;
}

// int getMinimumDifference(TreeNode* root) {
//     traversal(root);
//     return res;
// }
// 迭代法
int getMinimumDifference(TreeNode* root) {
    stack<TreeNode*> st;
    TreeNode* cur = root;
    TreeNode* pre = nullptr;
    while (cur != nullptr || !st.empty())
    {
        if (cur) {              // 遍历到左下角 
            st.push(cur);
            cur = cur->left;    //左         
        }
        else
        {
            // 当前节点处理的节点
            cur = st.top();
            st.pop();

            // 中
            if (pre != nullptr)
            {
                int dis = abs(cur->val - pre->val);
                if (dis < res)
                    res = dis;    
            }
            pre = cur;

            // 右
            cur = cur->right;
        }        
    }
    return res;
}

int main()
{
    TreeNode* root = init_tree();
    vector<vector<int>> src = levelOrder(root);
    showDoubleVec(src);
    int res = getMinimumDifference(root);
    cout << res << endl;
    return 0;
}

TreeNode* init_tree()
{
    TreeNode* root = new TreeNode(4);
    root->left  = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left ->left  = new TreeNode(1);
    root->left ->right = new TreeNode(3);
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