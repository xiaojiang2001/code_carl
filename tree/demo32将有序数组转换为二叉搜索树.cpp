#include <iostream>
#include <vector>
#include <queue>

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


TreeNode* traversal(vector<int>& nums)
{
    if (nums.size() == 0)
        return nullptr;

    int mid = nums.size() / 2;

    // 中间节点
    TreeNode* root = new TreeNode(nums[mid]);

    // 分割数组
    vector<int> leftNums(nums.begin(), nums.begin() + mid);
    vector<int> rightnums(nums.begin() + mid + 1, nums.end());

    // 递归构造左右子树
    root->left = traversal(leftNums);
    root->right = traversal(rightnums);

    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    TreeNode* root = traversal(nums);
    return root;
}

int main()
{
    vector<int>nums = {-10,-3,0,5,9};
    TreeNode* root = sortedArrayToBST(nums);
    levelOrder(root);
    return 0;
}


TreeNode* init_tree()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
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
