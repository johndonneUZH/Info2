node* deleteBST(node* root, int x)
{
    if (root == NULL) return root; // base case value not found
    else if (root->val < x) {root->right = deleteBST(root->right, x); return root;}
    else if (root->val > x) {root->left = deleteBST(root->left, x); return root;}

    else // x was found
    {
        // first case: x has no children
        if (root->right == NULL && root->left == NULL)
        {
            free(root);
            root = NULL;
        }

        else if (root->right == NULL)
        {
            node* temp = root;
            root = root->left;
            free(temp);

        }
        else if (root->left == NULL)
        {
            node* temp = root;
            root = root->right;
            free(temp);
        }

        else
        {
            int minRight = minVal(root->right);
            root->val = minRight;
            root->right = deleteBST(root->right, minRight);
        }
        return root;
    }
}   
