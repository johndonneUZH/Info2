/*Consider a binary tree defined as follows:
struct node {
    int val;
    struct node* left;
    struct node* right;
};
struct node* root;
Implement a function isBST(struct node* root) that checks if a tree is a BST*/

bool BSThelper(struct TreeNode* root, int min, int max)
{
    if (root == NULL) return true;

    if (root->val <= min || root->val >= max) return false;

    return BSThelper(root->left, min, root->val) && BSThelper(root->right, root->val, max);
}


bool isValidBST(struct TreeNode* root) {
    return BSThelper(root, INT_MIN, INT_MAX);
}
