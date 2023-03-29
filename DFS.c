// NOTE : We are taking an already accepted graph for the traversal.
// If you wish to take an user input graph then make changes accordingly, given the algorithm remains same.
//       2----3
//     / |   /|
//   1   | /  |
//     \ |/   |
//       4----5

#include <stdio.h>
#include <stdlib.h>

void dfs(int graph[][5], int visited[5], int vertices, int node)
{
    int it;
    printf("%d ", node);
    visited[node - 1] = 1;
    for (it = 0; it < vertices; it++)
    {
        if (graph[node - 1][it] == 1 && visited[it] == 0)
        {
            dfs(graph, visited, vertices, it + 1);
        }
    }
}

int main()
{
    int vertices = 5;
    int graph[][5] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}};

    int visited[5] = {0, 0, 0, 0, 0};
    printf("The DFS Traversal : \n");
    dfs(graph, visited, vertices, 1);
    printf("\n");

    return 0;
}