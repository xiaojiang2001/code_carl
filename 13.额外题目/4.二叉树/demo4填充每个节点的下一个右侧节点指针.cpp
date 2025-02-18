#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
    Node *next;
    Node() : val(0),left(nullptr),right(nullptr),next(NULL) {}
    Node(int x) : val(x),left(nullptr),right(nullptr),next(NULL) {}
};

Node* levelOrder(Node* root)
{
    queue<Node*> que;
    vector<vector<int>> res;
    if(root == nullptr)
        return nullptr;
    que.push(root);
    while (!que.empty())
    {
        int size = que.size();  // 每一行的节点数
        while (size--)
        {
            Node* node = que.front();
            que.pop();
            if(size > 0) {
                node->next = que.front();
            }   

            if(node->left)
                que.push(node->left);
            if(node->right)
                que.push(node->right);
        }
    }
    return root;
}

Node* connect(Node* root) {
    Node* res = levelOrder(root);
    return res;
}


// 调试
// 前序遍历
void preOrder(Node* root)
{
    if(root == nullptr)
        return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}
int main()
{
    Node* root = new Node(1);
    root->left  = new Node(2);
    root->right = new Node(3);
    root->left->left   = new Node(4);
    root->left->right  = new Node(5);
    root->right->left  = new Node(6);
    root->right->right = new Node(7);

    return 0;   
}