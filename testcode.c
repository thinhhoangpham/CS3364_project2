#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "project2.h"

int main() {

    //make graph structure
    struct graph g;
    // Set adjacency mattrix values to 0 (no edges)
    for (int i = 0; i < MAXNODES; i++) {
        for (int j = 0; j < MAXNODES; j++) {
            g.arcs[j][i].adj = 0;
        }
    }

    // create graph nodes (vertices)
    for (int i = 0; i < 10; i++) {
        sprintf(g.nodes[i].id, "%d", i);
        sprintf(g.nodes[i].name, "%d", i+10);
    }

    // join
    join(g.arcs, 0, 3);
    join(g.arcs, 0, 4);
    join(g.arcs, 1, 2);
    join(g.arcs, 2, 5);
    join(g.arcs, 3, 7);
    join(g.arcs, 4, 6);
    join(g.arcs, 4, 7);
    join(g.arcs, 5, 4);
    join(g.arcs, 5, 8);
    join(g.arcs, 6, 9);
    join(g.arcs, 8, 9);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", g.arcs[i][j].adj);
        }
        printf("\n");
    }

    // DFS
    dfs(g);
    // print pre and post nums
    for (int i = 0; i < 10; i++) {
        printf("%d: %d, %d\n", pre[i].i, pre[i].v, post[i].v);
    }
    printf("----------\n");

    // sort
    struct Element* sorted = mergeSort(post, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d\t %s\t%s\n", sorted[i].v, g.nodes[sorted[i].i].id, g.nodes[sorted[i].i].name);
    }
    
}