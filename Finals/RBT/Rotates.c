void leftRotate(node** root, node* x)
{
    node* y = x->right; // Taking the right subchild of the pivot of the rotation
    if (!y) return; // Cannot perform left rotation if x->right is NUL

    x->right = y->left; // Right child of pivot becomes the left child of y
    if (x->right != NULL) // Check if it wasn't a NULL node
    {
        x->right->parent = x;
    }

    // changing parent pointers
    y->parent = x->parent;
    if (x->parent == NULL) // if x is the root
    {
        *root = y;       
    }
    else // if x is NOT the root
    {
        if (x->parent->left == x) x->parent->left = y;
        else x->parent->right = y; 
    }
    // rest of exchanges
    y->left = x;
    x->parent = y;
}

void rightRotate(node** root, node* x)
{
    node* y = x->left;
    if (!y) return; // x->left is NULL

    x->left = y->right;
    if (y->right != NULL)
    {
        y->right->parent = x;
    }

    y->parent = x->parent;
    if (x->parent == NULL) // x is the root
    {   
        *root = y;
    }
    else
    {
        if (x->parent->right == x) x->parent->right = y;
        else x->parent->left = y;
    }

    y->right = x;
    x->parent = y;
}
