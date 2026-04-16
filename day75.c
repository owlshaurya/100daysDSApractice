#include <stdio.h>

#define MAX 1000

int main() {
    int arr[MAX];
    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int prefixSum = 0;
    int maxLen = 0;

    // simple hashmap using array (for demo)
    int map[20001];   // to handle negative values
    for(int i = 0; i < 20001; i++)
        map[i] = -2;  // -2 means not visited

    int offset = 10000;

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Case 1: sum = 0
        if(prefixSum == 0) {
            maxLen = i + 1;
        }

        // Case 2: seen before
        if(map[prefixSum + offset] != -2) {
            int len = i - map[prefixSum + offset];
            if(len > maxLen)
                maxLen = len;
        }
        else {
            // store first occurrence
            map[prefixSum + offset] = i;
        }
    }

    printf("%d\n", maxLen);

    return 0;
}