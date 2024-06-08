void RBinsert(node* root, int x)
{
    // standard BST search
    node* y = NULL;
    node* p = root;
    while (p != NULL && p->val != x)
    {
        y = p;
        if (p->val > x) p = p->left;
        else p = p->right;
    }

    // initialising the new node
    node* q = createNode(x);
    q->parent = y;

    // we check if the root is NULL
    if (y == NULL)
    {
        root = q;
    }
    // insert q as a child of y
    else if (y->val > x) y->left = q;
    else y->right = q;

    // set the new col
    q->col = RED;
    q->left = q->right = NULL;

    //fix possible problems with RB tree
    root = insertFixUp(root, q);
    return root;
}

node* insertFixUp(node* root, node* q)
{
    node* parent_pt = NULL;
    node* grand_parent_pt = NULL;

    while ((q != root) && (q->col != BLACK) && (q->parent->col == RED))
    {
        parent_pt = q->parent;
        grand_parent_pt = q->parent->parent;

        /*  Case : A
            Parent of q is left child of Grand-parent of q */
        if (parent_pt == grand_parent_pt->left)
        {
            node* uncle_pt = grand_parent_pt->right;

            /* Case : 1
               The uncle of q is also red
               Only Recoling required */
            if (uncle_pt != NULL && uncle_pt->col == RED)
            {
                grand_parent_pt->col = RED;
                parent_pt->col = BLACK;
                uncle_pt->col = BLACK;
                q = grand_parent_pt;
            }
            else
            {
                /* Case : 2
                   q is right child of its parent
                   Left-rotation required */
                if (q == parent_pt->right)
                {
                    leftRotate(&root, parent_pt);
                    q = parent_pt;
                    parent_pt = q->parent;
                }

                /* Case : 3
                   q is left child of its parent
                   Right-rotation required */
                rightRotate(&root, grand_parent_pt);
                swap(parent_pt->col, grand_parent_pt->col);
                q = parent_pt;
            }
        }

        /* Case : B
           Parent of q is right child of Grand-parent of q */
        else
        {
            node* uncle_pt = grand_parent_pt->left;

            /*  Case : 1
                The uncle of q is also red
                Only Recoling required */
            if ((uncle_pt != NULL) && (uncle_pt->col == RED))
            {
                grand_parent_pt->col = RED;
                parent_pt->col = BLACK;
                uncle_pt->col = BLACK;
                q = grand_parent_pt;
            }
            else
            {
                /* Case : 2
                   q is left child of its parent
                   Right-rotation required */
                if (q == parent_pt->left)
                {
                    rightRotate(&root, parent_pt);
                    q = parent_pt;
                    parent_pt = q->parent;
                }

                /* Case : 3
                   q is right child of its parent
                   Left-rotation required */
                leftRotate(&root, grand_parent_pt);
                swap(parent_pt->col, grand_parent_pt->col);
                q = parent_pt;
            }
        }
    }

    root->col = BLACK;

    return root;
}
