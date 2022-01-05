#include <stdio.h> 
#include <stdlib.h> 
#include "graph.h"

pnode get_node(int id_node, pnode *head) // get the indexe of the node
{
    pnode tmp = *head;
    while (tmp != NULL){
        if (tmp->node_num == id_node){
            return tmp;
        }
        else{
            tmp = tmp->next;
        }
    }
    return NULL;
}
void insert_edge(pnode t,int d,int w,pnode *head)
{
 if (!t->edges) // =null
    {
        t->edges = (pedge)malloc(sizeof(edge));// allocate memory
        if (!t->edges) // =null
        {
            printf("errore");
            return;
        }
        t->edges->weight = w; // enter value to edge
        t->edges->next = NULL;
        node *endN = get_node(d, head);
        t->edges->endpoint = &(*endN);
    }
 else 
    {
        pedge e = t->edges; // the edge = the edge that conect to node t
        while (e->next != NULL) // move to end edge
        {
            e = e->next;
        }
        e->next = (pedge)malloc(sizeof(edge));
        if (e->next == NULL)
        {
           printf("errore");
           return;
        }
        e->next->next = NULL;
        e->next->weight = w;
        node *endN = get_node(d, head);
        e->next->endpoint = &(*endN);
    }
 }


