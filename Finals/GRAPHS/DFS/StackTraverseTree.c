// they are absolutely equivalent

void inorderTreeWalk(TreeNode* root)
{
    if (root == NULL) return;

    printf("%d ", root->val);

    inorderTreeWalk(root->left);
    inorderTreeWalk(root->right);
}

void stackTraverseTree(TreeNode* root)
{
    stack* S = initStack();
    push(S, root);

    while (!isEmptyStack(S))
    {
        TreeNode* p = pop(S);
        printf("%d ", p->val);
        if (p->right != NULL && p->right->visited == false)
        {
            push(S, p->right);
        }
        if (p->left != NULL && p->left->visited == false)
        {
            push(S, p->left);
        }

    }
}
