#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


//***********************DIJKSTRA*********************//
dijkstra_P buildDijkstra(pnode start, int src)
{
    dijkstra_P head = NULL;
    dijkstra_P *index = &head;
    while (start != NULL)
    {
        (*index) = (dijkstra_P)malloc(sizeof(dijkstra_P));
        if ((*index) == NULL)
        {
            perror("malloc didnt work");
            exit(0);
        }

        (*index)->node = start;
        if (start->node_num == src)
        {
            (*index)->weight = 0;
        }
        else
        {
            (*index)->weight = INT_MAX;
        }
        (*index)->tag = 0;
        (*index)->next = NULL;
        index = &((*index)->next);
        start = start->next;
    }
    return head;
}

void deletateDijkstra(dijkstra_P dijkstra)
{
    while (dijkstra != NULL)
    {
        dijkstra_P temp = dijkstra;
        dijkstra = dijkstra->next;
        free(temp);
    }
}

dijkstra_P getPdijkstra(dijkstra_P head, int id)
{
    while (head != NULL)
    {
        if (head->node->node_num == id)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

dijkstra_P minVertical(dijkstra_P head)
{
    dijkstra_P ver = NULL;
    while (head != NULL)
    {
        if (!head->tag && head->weight < INT_MAX && (ver == NULL || ver->weight < head->weight))
        {
            ver = head;
        }
        head = head->next;
    }
    if (ver != NULL)
    {
        ver->tag = 1;
    }
    return ver;
}

int shortsPath_cmd(pnode head, int src, int dest)
{
   dijkstra_P dijkstraHead = buildDijkstra(head, src);
    dijkstra_P u = minVertical(dijkstraHead);
    while (u != NULL)
    {
        pedge edgeIndex = u->node->edges;
        while (edgeIndex != NULL)
        {
            // relax
           dijkstra_P v = getPdijkstra(dijkstraHead, edgeIndex->endpoint->node_num);
            int newDist = u->weight + edgeIndex->weight;
            if (v->weight > newDist)
            {
                v->weight = newDist;
            }
            edgeIndex = edgeIndex->next;
        }
        u = minVertical(dijkstraHead);
    }
    int distance = getPdijkstra(dijkstraHead, dest)->weight;
    if (distance == INT_MAX)
    {
        distance = -1;
    }
    deletateDijkstra(dijkstraHead);
    return distance;
}