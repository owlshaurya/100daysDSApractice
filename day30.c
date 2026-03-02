#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int exp;
    struct node *next;
};

int main() {
    int n, i;
    scanf("%d", &n);

    struct node *head = NULL, *temp = NULL, *newnode = NULL;

    // Create polynomial
    for(i = 0; i < n; i++) {
        newnode = (struct node*) malloc(sizeof(struct node));

        scanf("%d %d", &newnode->coeff, &newnode->exp);
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // Print polynomial
    temp = head;
    while(temp != NULL) {

        if(temp->exp == 0)
            printf("%d", temp->coeff);

        else if(temp->exp == 1)
            printf("%dx", temp->coeff);

        else
            printf("%dx^%d", temp->coeff, temp->exp);

        if(temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }

    return 0;
}