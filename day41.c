#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

// Enqueue
void enqueue(int value) {
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if(front == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

// Dequeue
void dequeue() {
    if(front == NULL) {
        printf("-1\n");
        return;
    }

    struct node *temp = front;
    printf("%d\n", front->data);

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
}

int main() {
    int n, type, value;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &type);

        if(type == 1) {
            scanf("%d", &value);
            enqueue(value);
        }
        else if(type == 2) {
            dequeue();
        }
    }

    return 0;
}