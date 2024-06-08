node* searchBST(node* root, int x)
{
    if (root == NULL || root->val == x) {return NULL;}

    node* p = root;
    node* y = NULL;
    while (p != NULL && p->val != x)
    {
        y = p;
        if (p->val > x) {p = p->left;}
        else {p = p->right;}
    }

    if (p != NULL) {return p;} 
    else {return NULL;}
}

node* searchParentBST(node* root, int x)
{
    if (root == NULL || root->val == x) {return NULL;}

    node* p = root;
    node* y = NULL;
    while (p != NULL && p->val != x)
    {
        y = p;
        if (p->val > x) {p = p->left;}
        else {p = p->right;}
    }

    if (p != NULL) {return y;} 
    else {return NULL;}
}
