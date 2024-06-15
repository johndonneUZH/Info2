void inorderTraversal(TreeNode* root) {
    Stack* S = initStack(100);  // assuming a max capacity of 100 for simplicity
    TreeNode* current = root;

    while (current != NULL || !isEmpty(S)) {
        // Traverse to the leftmost node
        while (current != NULL) {
            push(S, current);
            current = current->left;
        }

        // Pop from stack and visit the node
        current = pop(S);
        printf("%d ", current->value);  // print the value of the node

        // Go to the right subtree
        current = current->right;
    }
}

void NormalStackTraverse(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    Stack* S = initStack(100);  // assuming a max capacity of 100 for simplicity
    push(S, root);

    while (!isEmpty(S)) {
        root = pop(S);
        printf("%d ", root->value);  // print the value of the node

        // Push right child first
        if (root->right != NULL) {
            push(S, root->right);
        }

        // Push left child last so it is processed first
        if (root->left != NULL) {
            push(S, root->left);
        }
    }
}


void postorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    Stack* S1 = initStack(100);  // assuming a max capacity of 100 for simplicity
    Stack* S2 = initStack(100);  // second stack to hold the nodes in reverse postorder
    push(S1, root);

    // Process all nodes of the tree
    while (!isEmpty(S1)) {
        TreeNode* node = pop(S1);
        push(S2, node);

        // Push left and right children of the removed item to S1
        if (node->left != NULL) {
            push(S1, node->left);
        }
        if (node->right != NULL) {
            push(S1, node->right);
        }
    }

    // Print all elements of S2
    while (!isEmpty(S2)) {
        TreeNode* node = pop(S2);
        printf("%d ", node->value);
    }
}
