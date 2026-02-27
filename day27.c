#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to get length
int getLength(struct node *head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    int n, m, i, value;

    scanf("%d", &n);

    struct node *head1 = NULL, *temp1 = NULL, *newnode = NULL;
    struct node *intersectNode = NULL;

    // Create first list
    for(i = 0; i < n; i++) {
        scanf("%d", &value);

        newnode = (struct node*) malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;

        if(head1 == NULL) {
            head1 = newnode;
            temp1 = newnode;
        } else {
            temp1->next = newnode;
            temp1 = newnode;
        }

        if(value == 30)  // create intersection at 30
            intersectNode = newnode;
    }

    scanf("%d", &m);

    struct node *head2 = NULL, *temp2 = NULL;

    for(i = 0; i < m; i++) {
        scanf("%d", &value);

        if(value == 30 && intersectNode != NULL) {
            // Connect second list to first list
            if(head2 == NULL)
                head2 = intersectNode;
            else
                temp2->next = intersectNode;
            break;
        }

        newnode = (struct node*) malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;

        if(head2 == NULL) {
            head2 = newnode;
            temp2 = newnode;
        } else {
            temp2->next = newnode;
            temp2 = newnode;
        }
    }

    // Lengths
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct node *ptr1 = head1;
    struct node *ptr2 = head2;

    int diff;

    if(len1 > len2) {
        diff = len1 - len2;
        while(diff--) ptr1 = ptr1->next;
    } else {
        diff = len2 - len1;
        while(diff--) ptr2 = ptr2->next;
    }

    while(ptr1 && ptr2) {
        if(ptr1 == ptr2) {
            printf("%d", ptr1->data);
            return 0;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    printf("No Intersection");

    return 0;
}