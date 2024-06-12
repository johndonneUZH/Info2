/*Consider a binary tree defined as follows:
struct node {
    int val;
    struct node* left;
    struct node* right;
};
struct node* root;
Implement a function isBST(struct node* root) that checks if a tree is a BST*/

bool isBST(node* root)
{
    if (root == NULL) return true;
    if (root->left && root->val < root->left->val) return false;
    if (root->right && root->val > root->right->val) return false;
    return isBST(root->left) && isBST(root->right)
}
