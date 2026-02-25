#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    int n, i, key, count = 0;

    scanf("%d", &n);

    struct node *head = NULL;
    struct node *temp = NULL;
    struct node *newnode = NULL;

    // Create linked list
    for(i = 0; i < n; i++) {
        newnode = (struct node*) malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
        } else {
            temp->next = newnode;
        }

        temp = newnode;
    }

    // Read key
    scanf("%d", &key);

    // Traverse and count
    temp = head;
    while(temp != NULL) {
        if(temp->data == key) {
            count++;
        }
        temp = temp->next;
    }

    printf("%d", count);

    // Free memory
    temp = head;
    while(temp != NULL) {
        struct node *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}