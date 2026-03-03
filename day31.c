#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

int main() {
    int n, choice, value;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {

        scanf("%d", &choice);

        // PUSH
        if(choice == 1) {
            scanf("%d", &value);

            if(top == MAX - 1) {
                printf("Stack Overflow\n");
            } else {
                stack[++top] = value;
            }
        }

        // POP
        else if(choice == 2) {
            if(top == -1) {
                printf("Stack Underflow\n");
            } else {
                printf("%d\n", stack[top--]);
            }
        }

        // DISPLAY
        else if(choice == 3) {
            if(top == -1) {
                printf("Stack Underflow\n");
            } else {
                for(int j = top; j >= 0; j--) {
                    printf("%d ", stack[j]);
                }
                printf("\n");
            }
        }
    }

    return 0;
}