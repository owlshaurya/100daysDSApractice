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

// Queue for vertical traversal
struct pair {
    struct node* node;
    int hd;
};

// Vertical Order
void verticalOrder(struct node* root) {
    if(root == NULL) return;

    struct pair queue[100];
    int front = 0, rear = 0;

    int map[200][100];   // store values
    int size[200] = {0}; // count per column

    int offset = 100; // to handle negative index

    queue[rear++] = (struct pair){root, 0};

    while(front < rear) {
        struct pair temp = queue[front++];

        int hd = temp.hd + offset;

        map[hd][size[hd]++] = temp.node->data;

        if(temp.node->left)
            queue[rear++] = (struct pair){temp.node->left, temp.hd - 1};

        if(temp.node->right)
            queue[rear++] = (struct pair){temp.node->right, temp.hd + 1};
    }

    // Print result
    for(int i = 0; i < 200; i++) {
        if(size[i] > 0) {
            for(int j = 0; j < size[i]; j++)
                printf("%d ", map[i][j]);
            printf("\n");
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

    verticalOrder(root);

    return 0;
}