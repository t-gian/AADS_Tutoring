#include <stdio.h>
#include <stdlib.h>

int isCorrect(int vertex, int **graph, int *colors, int color, int n) {
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

int generate_color(int vertex, int **graph, int *colors, int m, int n) {
    if (vertex == n) {
        return 1;
    }

    for (int color = 1; color <= m; color++) {
        if (isCorrect(vertex, graph, colors, color, n)) {
            colors[vertex] = color;

            if (generate_color(vertex + 1, graph, colors, m, n)) {
                return 1;
            }

            colors[vertex] = 0;
        }
    }

    return 0;
}

void color(int **graph, int n) {
    int *colors = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        colors[i] = 0;
    }
    int numColors = 1;

    while (!generate_color(0, graph, colors, numColors, n)) {
        numColors++;
    }

    printf("Vertex;  Color\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", i, colors[i]);
    }

    free(colors);
}

int** readAdjacencyMatrixFromFile(const char* filename, int* n) {
    FILE* fin = fopen(filename, "r");
    if (fin == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }

    fscanf(fin, "%d", n);
    int** matrix = (int**)malloc(*n * sizeof(int*));
    for (int i = 0; i < *n; i++) {
        matrix[i] = (int*)malloc(*n * sizeof(int));
        for (int j = 0; j < *n; j++) {
            fscanf(fin, "%d", &matrix[i][j]);
        }
    }

    fclose(fin);
    return matrix;
}

int main() {
    const char* filename = "adjmatrix.txt";
    int n = 0;
    int** matrix = readAdjacencyMatrixFromFile(filename, &n);
    if (matrix == NULL) {
        return 1;
    }
    color(matrix, n);

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
