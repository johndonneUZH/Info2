void RECinsertBST(node** root, int x)
{
    if (*root == NULL)
    {
        *root = createNode(x);
    }
    else if (x > (*root)->val) 
    {
        RECinsertBST(&((*root)->right), x);
    }
    else if (x < (*root)->val)
    {
        RECinsertBST(&((*root)->left), x);
    }
}

void ITinsertBST(node** root, int x)
{
    node** p = root;
    node** y = NULL;
    while ((*p) != NULL)
    {
        y = p;
        if ((*p)->val > x) p = &(*p)->left;
        else p = &(*p)->right;
    }
    if (y == NULL) { (*y) = createNode(x);}
    else if ((*y)->left == *p) {(*y)->left = createNode(x);}
    else {(*y)->right = createNode(x);}
}
