typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int height(TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}

int diameter(TreeNode* root) {
    if (root == NULL) return 0;

    // Calculate the diameter passing through the root
    int rootDiameter = height(root->left) + height(root->right) + 1;

    // Calculate the diameters of the left and right subtrees
    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);

    // Return the maximum of the three diameters
    return max(rootDiameter, max(leftDiameter, rightDiameter));
}
