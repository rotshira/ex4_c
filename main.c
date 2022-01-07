#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>
#include <limits.h>
#include "graph.h"
#include <ctype.h>

// the main of ex4 

int main()
{
    pnode help = NULL;
    pnode *head = &help;
    char c ;
    while (scanf("%c", &c) != EOF)
    {
        if (c == 'A')
        {
            build_graph_cmd(head);
        }
        else if (c == 'B')
        {
            insert_node_cmd(head);
        }
        else if (c == 'D')
        {
            delete_node_cmd(head);
        }
        else if (c == 'S')
        {
            int src = -1, dest = -1;
            scanf("%d %d", &src, &dest);
            int dis = shortsPath_cmd(*head, src, dest);
            printf("Dijsktra shortest path: %d \n", dis);
        }
        else if (c == 'T') {
            TSP_cmd(*head);
        }
    }
    deleteGraph_cmd(head);
    return 0;
}