#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

// Create node
struct node* createNode(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// Find index in inorder
int findIndex(int inorder[], int start, int end, int val) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == val)
            return i;
    }
    return -1;
}

// Build tree
struct node* build(int inorder[], int postorder[],
                   int start, int end, int* postIndex) {

    if(start > end)
        return NULL;

    int rootVal = postorder[(*postIndex)--];
    struct node* root = createNode(rootVal);

    if(start == end)
        return root;

    int index = findIndex(inorder, start, end, rootVal);

    // Build right first
    root->right = build(inorder, postorder, index + 1, end, postIndex);
    root->left = build(inorder, postorder, start, index - 1, postIndex);

    return root;
}

// Preorder traversal
void preorder(struct node* root) {
    if(root == NULL) return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for(int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    struct node* root = build(inorder, postorder, 0, n - 1, &postIndex);

    preorder(root);

    return 0;
}