#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n;
    scanf("%d", &n);

    int dist[MAX][MAX];

    // Input adjacency matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);

            // convert -1 to INF (except diagonal)
            if(dist[i][j] == -1 && i != j)
                dist[i][j] = INT_MAX;
        }
    }

    // Floyd-Warshall
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                   dist[i][k] + dist[k][j] < dist[i][j]) {

                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Output result
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dist[i][j] == INT_MAX)
                printf("-1 ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}