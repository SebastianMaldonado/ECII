#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define NODES 4
#define INF INT_MAX

void dijkstra(int graph[NODES][NODES], int start) {
    int distances[NODES];
    int visited[NODES] = {0};

    for (int i = 0; i < NODES; i++) {
        distances[i] = INF;
    }
    distances[start] = 0;

    for (int i = 0; i < NODES - 1; i++) {
        int minDist = INF, minIndex = -1;
        for (int j = 0; j < NODES; j++) {
            if (!visited[j] && distances[j] <= minDist) {
                minDist = distances[j];
                minIndex = j;
            }
        }

        visited[minIndex] = 1;
        for (int j = 0; j < NODES; j++) {
            if (!visited[j] && graph[minIndex][j] && distances[minIndex] != INF &&
                distances[minIndex] + graph[minIndex][j] < distances[j]) {
                distances[j] = distances[minIndex] + graph[minIndex][j];
            }
        }
    }
}

int main() {
    int graph[NODES][NODES] = {
        {0, 1, 4, 0},
        {0, 0, 2, 5},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };

    clock_t start = clock();
    dijkstra(graph, 0);
    clock_t end = clock();

    double executionTime = (double)(end - start) * 1000 / CLOCKS_PER_SEC;
    FILE *file = fopen("result.txt", "w");
    fprintf(file, "Execution time: %.6f\n", executionTime);
    fclose(file);

    return 0;
}
