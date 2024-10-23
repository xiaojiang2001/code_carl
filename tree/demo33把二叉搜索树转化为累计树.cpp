#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
};

TreeNode* init_tree();
TreeNode* create_tree();
void levelOrder(TreeNode* root);
void preOrder(TreeNode* root);

// 新树 val = 之前比他大的数值之和
// 遍历顺序 右 中 左
TreeNode* pre = nullptr;
void traversal(TreeNode* root)
{
    if (root == nullptr)
        return;
    // 右
    traversal(root->right);
    // 中
    if (pre != nullptr)
        root->val += pre->val;
    pre = root;
    // 左
    traversal(root->left);
    return;
}

// TreeNode* convertBST(TreeNode* root) {
//     traversal(root);
//     return root;  
// }

// 迭代法 中序遍历模板
TreeNode* convertBST(TreeNode* root) 
{
    if (root == nullptr)    
        return nullptr;

    stack<TreeNode*> st;
    TreeNode* pre = nullptr;
    TreeNode* cur = root;
    while (cur != nullptr || !st.empty())
    {
        // 右
        if (cur != nullptr)
        {
            st.push(cur);
            cur = cur->right;
        }
        else
        {
            cur = st.top();
            st.pop();
            // 中
            if (pre != nullptr)
                cur->val += pre->val;
            pre = cur;

            // 左
			cur = cur -> left;
        } 
    }
    return root;
}

int main()
{
    TreeNode* root = init_tree();
    levelOrder(root);
    TreeNode* res = convertBST(root);
    levelOrder(res);
    return 0;
}


TreeNode* init_tree()
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    root->left->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(8);
    return root;
}

TreeNode* create_tree()
{
    int val;
    cout << "please input a number(-1表示空节点): ";
    cin >> val;
    if (val == -1)
        return nullptr;

    TreeNode* root = new TreeNode(val);
    root->left = create_tree();
    root->right = create_tree();

    return root;
}


void preOrder(TreeNode* root)
{
    if(root == nullptr)
        return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}


void levelOrder(TreeNode* root)
{
    queue<TreeNode*> que;
    que.push(root);
    while (!que.empty())
    {
        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode* node = que.front();
            que.pop();
            cout << node->val << " ";
            if (node->left)     que.push(node->left);
            if (node->right)    que.push(node->right);   
        }
        // 换层
        cout << endl;
    }
}
