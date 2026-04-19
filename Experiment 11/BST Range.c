#include <stdio.h>
#include <stdlib.h>

// BST Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Insert into BST
struct Node* insert(struct Node* root, int val) {
    if (root == NULL)
        return newNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Print values in range
void rangeBST(struct Node* root, int low, int high) {
    if (root == NULL)
        return;

    if (root->data > low)
        rangeBST(root->left, low, high);

    if (root->data >= low && root->data <= high)
        printf("%d ", root->data);

    if (root->data < high)
        rangeBST(root->right, low, high);
}

// MAIN
int main() {
    int n, val, low, high;
    struct Node* root = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Enter low and high: ");
    scanf("%d %d", &low, &high);

    printf("Values in range: ");
    rangeBST(root, low, high);

    return 0;
}
