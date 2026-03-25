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

// Insert into BST
struct node* insert(struct node* root, int val) {
    if(root == NULL)
        return createNode(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Find LCA
struct node* findLCA(struct node* root, int n1, int n2) {

    while(root != NULL) {

        if(n1 < root->data && n2 < root->data)
            root = root->left;

        else if(n1 > root->data && n2 > root->data)
            root = root->right;

        else
            return root; // split point
    }

    return NULL;
}

int main() {
    int n, val, a, b;

    scanf("%d", &n);

    struct node* root = NULL;

    // Build BST
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    // Input nodes
    scanf("%d %d", &a, &b);

    struct node* lca = findLCA(root, a, b);

    if(lca != NULL)
        printf("%d", lca->data);

    return 0;
}