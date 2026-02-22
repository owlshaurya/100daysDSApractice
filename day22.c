#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    int n, value, i;
    scanf("%d", &n);

    struct node *head = NULL, *temp = NULL, *newnode = NULL;

    // Creating linked list
    for(i = 0; i < n; i++) {
        scanf("%d", &value);

        newnode = (struct node*) malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // Display linked list
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    // Count nodes
    int count = 0;
    temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    // If you want to print count also, uncomment below:
    // printf("\nTotal Nodes = %d", count);

    return 0;
}