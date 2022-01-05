#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>
#include <limits.h>
#include "graph.h"


int main()
{
char c;
int size;
pnode temp = NULL;
pnode *h = &temp;
scanf("%c" , &c);
while(scanf("%c" , &c)!= EOF){
if (c == 'A')
{
   build_graph_cmd(h);
}
if (c == 'B')
{
  insert_node_cmd(h);
  printGraph_cmd(*h);
}
if (c == 'D')
{
  delete_node_cmd(h);
  printGraph_cmd(*h);
}
if (c == 'S')
{
  int src = -1, dest = -1;
            scanf("%d %d", &src, &dest);
            int dis = shortsPath_cmd(*h, src, dest);
            printf("Dijsktra shortest path: %d \n", dis);
            continue;
}
if (c == 'T')
{
 TSP(*h);
  continue;
}
free(h);
}

