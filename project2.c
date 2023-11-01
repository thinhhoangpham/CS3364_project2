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

    // read data from source and create graph nodes (vertices)
    // In the order given in assignment document
    FILE * data = fopen("data.txt", "r");
    char id[10]; char name[100];
    int k = 0;
    for (int i = 0; i <= MAXNODES; i++) {
        // read data for course id and check if reach end of file
        if (fgets(g.nodes[k].id, 100, data) == NULL) {
            break;
        }
        // remove new line character
        g.nodes[k].id[strcspn(g.nodes[k].id, "\n")] = '\0';
        // print out for debug
        // printf("node%d_id: %s\n", i, g.nodes[i].id);

        // read data for course name and check if reach end of file
        if (fgets(g.nodes[k].name, 100, data) == NULL) {
            break;
        }
        // remove new line character
        g.nodes[k].name[strcspn(g.nodes[k].name, "\n")] = '\0';
        // print out for debug
        // printf("node%d_name: %s\n", i, g.nodes[i].name);
        k++;
    }
    fclose(data);

    // make connections
    join(g.arcs, 0, 3);     // CS 1412 needs CS 1411
    join(g.arcs, 1, 4);     // MATH 1452 needs MATH 1451
    join(g.arcs, 1, 5);     // PHYS 1408 needs MATH 1451
    join(g.arcs, 2, 6);     // ENGL 1302 needs ENGL 1301
    join(g.arcs, 3, 7);     // CS 2413 needs CS 1412
    join(g.arcs, 0, 8);     // CS 1382 needs CS 1411
    join(g.arcs, 1, 9);     // ECE 2372 needs MATH 1451
    join(g.arcs, 4, 10);    // MATH 2450 needs MATH 1452
    join(g.arcs, 5, 11);    // PHYS 2401 needs PHYS 1408
    join(g.arcs, 3, 12);    // CS 2350 needs CS 1412
    join(g.arcs, 9, 12);    // CS 2350 needs ECE 2372
    join(g.arcs, 7, 13);    // CS 2365 needs CS 2413
    join(g.arcs, 4, 16);    // MATH 2360 needs MATH 1452
    join(g.arcs, 2, 17);    // ENGL 2311 needs ENGL 1301
    join(g.arcs, 6, 17);    // ENGL 2311 needs ENGL 1302
    join(g.arcs, 7, 18);    // CS 3361 needs CS 2413
    join(g.arcs, 7, 19);    // CS 3364 needs CS 2413
    join(g.arcs, 8, 19);    // CS 3364 needs CS 1382
    join(g.arcs, 16, 19);   // CS 3364 needs MATH 2360
    join(g.arcs, 10, 20);   // MATH 3342 needs MATH 2450
    join(g.arcs, 13, 22);   // CS 3365 needs CS 2365
    join(g.arcs, 7, 22);    // CS 3365 needs CS 2413
    join(g.arcs, 20, 22);   // CS 3365 needs MATH 3342
    join(g.arcs, 12, 23);   // CS 3375 needs CS 2350
    join(g.arcs, 8, 24);    // CS 3383 needs CS 1382
    join(g.arcs, 22, 25);   // CS 4365 needs CS 3365
    join(g.arcs, 19, 26);   // CS 4352 needs CS 3364
    join(g.arcs, 23, 26);   // CS 4352 needs CS 3375
    join(g.arcs, 19, 27);   // CS 4354 needs CS 3364
    join(g.arcs, 25, 28);   // CS 4366 needs CS 4365

    // print out adjacency matrix for debug
    // for (int i = 0; i < MAXNODES; i++) {
    //     for (int j = 0; j < MAXNODES; j++) {
    //         printf("%d ", g.arcs[i][j].adj);
    //     }
    //     printf("\n");
    // }
    // printf("----------\n");

    // DFS
    dfs(g);
    // print pre and post nums
    // for (int i = 0; i < MAXNODES; i++) {
    //     printf("%d: %d, %d\n", pre[i].i, pre[i].v, post[i].v);
    // }
    // printf("----------\n");

    // sort in descending order of post numbers
    struct Element* sorted = mergeSort(post, MAXNODES);

    // print out topological order of courses
    printf("\nTopological order of courses in descending order of post numbers\n\n");
    for (int i = 0; i < MAXNODES; i++) {
        printf("%d\t| %s\t| %s\n", sorted[i].v, g.nodes[sorted[i].i].id, g.nodes[sorted[i].i].name);
    }


}