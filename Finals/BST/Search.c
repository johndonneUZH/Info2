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

node* searchSuccessor(node* root, node* x)
{
    node* succ = NULL;
    node* p = root;
    while (p->val != x->val)
    {
        if (p->val > x->val)
        {
            succ = p;
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    return succ;

node* searchPredecessor(node* root, node* x)
{
    node* p = root;
    node* succ = NULL;
    while (p->val != x->val)
    {
        if (p->val < x->val)
        {
            succ = p;
            p = p->left;
        }
        else
        {
            p = p->right
        }
    }   
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
