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

// Build tree from level order
struct node* buildTree(int arr[], int n) {
    if(n == 0 || arr[0] == -1)
        return NULL;

    struct node* root = createNode(arr[0]);

    struct node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while(i < n) {
        struct node* curr = queue[front++];

        // Left child
        if(arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if(i >= n) break;

        // Right child
        if(arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

// Find LCA
struct node* findLCA(struct node* root, int n1, int n2) {

    if(root == NULL)
        return NULL;

    if(root->data == n1 || root->data == n2)
        return root;

    struct node* left = findLCA(root->left, n1, n2);
    struct node* right = findLCA(root->right, n1, n2);

    if(left != NULL && right != NULL)
        return root;

    return (left != NULL) ? left : right;
}

int main() {
    int n, a, b;

    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d %d", &a, &b);

    struct node* root = buildTree(arr, n);

    struct node* lca = findLCA(root, a, b);

    if(lca != NULL)
        printf("%d", lca->data);

    return 0;
}