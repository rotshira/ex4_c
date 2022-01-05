#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


//***********************DIJKSTRA*********************//
p_dijkstra createDijkstra(pnode begin, int src){
    p_dijkstra head = NULL;
    p_dijkstra *idx = &head;

    while (begin != NULL){
        (*idx) = (p_dijkstra)malloc(sizeof(dijkstra));
        if ((*idx) == NULL){
            perror("there is no enough space to create dijkstra struct, sorry\n");
            exit(0);
        }
        (*idx)->node = begin;
        if (begin->node_num == src){
            (*idx)->weight = 0;
        }
        else{
            (*idx)->weight = INT_MAX;
        }
        (*idx)->tag = 0;
        (*idx)->next = NULL;
        idx = &((*idx)->next);
        begin = begin->next;
    }
    return head;
}

p_dijkstra getPointerDijkstra(p_dijkstra head, int ID){
    while (head != NULL){
        if (head->node->node_num == ID){
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void deleteDijkstra(p_dijkstra dijkstra){
    while (dijkstra != NULL){
        p_dijkstra temp = dijkstra;
        dijkstra = dijkstra->next;
        free(temp);
    }
}

p_dijkstra minimalH(p_dijkstra head){
    p_dijkstra v = NULL;
    while (head != NULL){
        if (!head->tag && head->weight < INT_MAX && (v == NULL || v->weight < head->weight)){
            v = head;
        }
        head = head->next;
    }
    if (v != NULL){
        v->tag = 1;
    }
    return v;
}

int shortsPath_cmd(pnode head, int src, int dest){
    p_dijkstra d_Head = createDijkstra(head, src);
    p_dijkstra minV = minimalH(d_Head);
    int dist = 0;
    while (minV != NULL){
        pedge edgeIndex = minV->node->edges;
        while (edgeIndex != NULL){
            p_dijkstra n = getPointerDijkstra(d_Head, edgeIndex->endpoint->node_num);
            int newDist = minV->weight + edgeIndex->weight;
            if (n->weight > newDist)
            {
                n->weight = newDist;
            }
            edgeIndex = edgeIndex->next;
        }
        minV = minimalH(d_Head);
    }
    dist = getPointerDijkstra(d_Head, dest)->weight;
    if (dist == INT_MAX){
        dist = -1;
    }
    deleteDijkstra(d_Head);
    return dist;
}