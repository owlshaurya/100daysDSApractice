#include <stdio.h>

#define SIZE 100

int hashTable[SIZE];

// Initialize table
void init() {
    for(int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

// Insert
void insert(int key, int m) {
    int h = key % m;

    for(int i = 0; i < m; i++) {
        int index = (h + i*i) % m;

        if(hashTable[index] == -1) {
            hashTable[index] = key;
            return;
        }
    }
}

// Search
void search(int key, int m) {
    int h = key % m;

    for(int i = 0; i < m; i++) {
        int index = (h + i*i) % m;

        if(hashTable[index] == key) {
            printf("FOUND\n");
            return;
        }

        if(hashTable[index] == -1) {
            printf("NOT FOUND\n");
            return;
        }
    }

    printf("NOT FOUND\n");
}

int main() {
    int m, n;
    scanf("%d", &m);   // table size
    scanf("%d", &n);   // number of operations

    init();

    char op[10];
    int key;

    for(int i = 0; i < n; i++) {
        scanf("%s %d", op, &key);

        if(op[0] == 'I') {
            insert(key, m);
        } else if(op[0] == 'S') {
            search(key, m);
        }
    }

    return 0;
}