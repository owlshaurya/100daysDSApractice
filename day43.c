#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

// Create new node
struct node* createNode(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// Inorder traversal
void inorder(struct node* root) {
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Build tree using level order
struct node* buildTree(int arr[], int n) {

    if(n == 0 || arr[0] == -1)
        return NULL;

    struct node* root = createNode(arr[0]);

    struct node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

    while(i < n) {
        struct node* current = queue[front++];

        // Left child
        if(arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        if(i >= n) break;

        // Right child
        if(arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct node* root = buildTree(arr, n);

    inorder(root);

    return 0;
}