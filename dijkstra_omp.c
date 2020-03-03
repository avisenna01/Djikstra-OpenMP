// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <omp.h>
#define MAX LONG_MAX - 101
// Number of vertices in the graph
// #define V 9


// A utility function to print the constructed distance array
void printSolution(char *outfile, int N, long int **graph) {
    FILE *out;

    out = fopen(outfile, "w");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (graph[i][j] != MAX) {
                fprintf(out, "%ld ", graph[i][j]);
            } else {
                fprintf(out, "X ");
            }
        }
        fprintf(out, "\n");
    }
    fclose(out);
}

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
long int minDistance(int N, long int *dist, bool *sptSet) {
    // Initialize min value
    long int min = MAX, min_index;

    for (int v = 0; v < N; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v], min_index = v;
        }
    }

    return min_index;
}

void createMatrix(long int **solutionMatrix, int src, long int *dist) {
    solutionMatrix[src] = dist;
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int N, long int **graph, int src, long int **solutionMatrix) {
    long int *dist; // The output array. dist[i] will hold the shortest
    dist = (long int *) malloc(sizeof(long int) * (N + 1));
    // distance from src to i

    bool *sptSet; // sptSet[i] will be true if vertex i is included in shortest
    sptSet = (bool *) malloc(sizeof(bool) * (N + 1));
    // path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < N; i++) {
        dist[i] = MAX,
        sptSet[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < N - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        long int u = minDistance(N, dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < N; v++) {
            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && (graph[u][v] != MAX) /*&& (dist[u] != MAX)*/ && (dist[u] + graph[u][v] < dist[v])) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    free(sptSet);

    createMatrix(solutionMatrix, src, dist);
}

/* Global variables */
long int **graph;
long int **solutionMatrix;

// driver program to test above function
int main(int argc, char *argv[]) {
    /* Let us create the example graph discussed above */
    int N = atoi(argv[1]);
    int thread_count = atoi(argv[2]);

    graph = (long int **) malloc(sizeof(long int *) * (N + 1));
    for (int i = 0; i < N; i++) {
        graph[i] = (long int *)malloc(sizeof(long int) * (N + 1));
    }

    srand(13517061);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                if (rand() % 2) { //Menentukan apakah terdapat edge dari i ke j 
                    long int x = rand() % 100 + 1;
                    graph[i][j] = x;
                    graph[j][i] = x;
                } else {
                    graph[i][j] = MAX;
                    graph[j][i] = MAX;
                }
            }
        }
    }

    solutionMatrix = (long int **)malloc(sizeof(long int *) * (N + 1));

    printSolution("out/in", N, graph);
    
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    #pragma omp parallel for num_threads(thread_count)
    for (int i = 0; i < N; i++) {
        dijkstra(N, graph, i, solutionMatrix);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / (CLOCKS_PER_SEC / 1000000);
    
    printf("cpu time(in microseconds) : %lf\n", cpu_time_used);
    printSolution("out/out", N, solutionMatrix);

    for (int i = 0; i < N; i++) {
        free(graph[i]);
        free(solutionMatrix[i]);
    }
    free(graph);
    free(solutionMatrix);

    return 0;
}
