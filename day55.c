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

// Build tree
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

        if(arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if(i >= n) break;

        if(arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

// Right View
void rightView(struct node* root) {
    if(root == NULL) return;

    struct node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while(front < rear) {
        int size = rear - front;

        for(int i = 0; i < size; i++) {
            struct node* curr = queue[front++];

            // print last node of level
            if(i == size - 1)
                printf("%d ", curr->data);

            if(curr->left)
                queue[rear++] = curr->left;

            if(curr->right)
                queue[rear++] = curr->right;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct node* root = buildTree(arr, n);

    rightView(root);

    return 0;
}