void inorderTreeWalk(node* root)
{
    if (root == NULL) {return;}
    inorderTreeWalk(root->left);
    printf("%i ", root->val);
    inorderTreeWalk(root->right);
}

void postorderTreeWalk(node* root)
{
    if (root == NULL) {return;}
    postorderTreeWalk(root->left);
    postorderTreeWalk(root->right);
    printf("%i ", root->val);
}

void preorderTreeWalk(node* root)
{
    if (root == NULL) {return;}
    printf("%i ", root->val);
    preorderTreeWalk(root->left);
    preorderTreeWalk(root->right);
}
