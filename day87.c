#include <stdio.h>

// Simple sort (for given example)
void sort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Binary Search Iterative
int binarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;

    while(left <= right) {
        int mid = (left + right) / 2;

        if(arr[mid] == x)
            return mid;
        else if(arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; // not found
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    // input
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // sort first
    sort(arr, n);

    // print sorted array
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    // optional: search element
    int x;
    scanf("%d", &x);

    int result = binarySearch(arr, n, x);

    if(result != -1)
        printf("Found at index %d\n", result);
    else
        printf("Not Found\n");

    return 0;
}