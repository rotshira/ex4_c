#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>
#include "graph.h"

// function that return node by him id
pnode get_node(int id_node, pnode *head) // get the indexe of the node
{
    pnode tmp = *head;
    while (tmp != NULL){
        if (tmp->node_num == id_node)
        {
            return tmp;
        }
        else{
            tmp = tmp->next;
        }
    }
    return NULL;
}
// function that insert one edge!
void insert_e(node *n, int endpoint , int weight, pnode *head )
{
 pedge e = n->edges;
    while (e!=NULL){
         e = e->next;
}
    pedge new_edge =(pedge)malloc(sizeof(edge));
    if(new_edge == NULL)
        {
            exit(0);
        }
    pnode Node = get_node(endpoint,head);
    new_edge->endpoint= &(*Node);
    new_edge->weight =weight;
    new_edge->next = NULL;
    e->next=new_edge;
}

//function that add edge to list
void insert_edges(pnode temp,int dest,int w,pnode *head)
{
  if(temp->edges == NULL)
    {
        temp->edges = (pedge)malloc(sizeof(edge));
        if(temp->edges == NULL)
        {
            exit(0);
        }
        temp->edges->weight = w;
        temp->edges->next =NULL;
        node *D = get_node(dest,head);
        temp->edges->endpoint = &(*D);
    }
    else{
        pedge n = temp->edges;

        while(n->next!=NULL)
        {
            n = n->next;
        }
        n->next = (pedge)malloc(sizeof(edge));
        if(n == NULL)
        {
            exit(0);
        }
        n->next->next = NULL;
        n->next->weight = w;
        node *D = get_node(dest,head);
        n->next->endpoint = &(*D);
    }
}

void delete_edges(pnode t)
{
if(t->edges!=NULL)
    {
    pedge temp = t->edges;
    while(temp!=NULL)
    {
        pedge p1 = NULL;
        p1 = temp;
        temp = temp->next;
        free(p1);
    }
    }
    else{
        free(t->edges);

}
}

void del_edge(pnode *head,int n)
{
    pnode tempNode = *head;

    while (tempNode!= NULL)
    {
    if(tempNode->node_num != n && tempNode->edges!=NULL){
    if(tempNode->edges->endpoint->node_num !=n)
        {
         pedge tempEdge = tempNode->edges;
         while (tempEdge->next!= NULL)
                {   
        if(tempEdge->next->endpoint->node_num == n){
             pedge p1 = tempEdge->next;
             tempEdge->next=tempEdge->next->next;
             free(p1);
             break;
                }
            tempEdge = tempEdge->next;
                }           
            }
            else
            { 
            if(tempNode->edges->next ==NULL){
                pedge p1 = tempNode->edges;
                tempNode->edges = NULL;
                 free(p1);
            }
            else{
                pedge p1 = tempNode->edges;
                tempNode->edges = p1->next;
                free(p1);
                 }
            }
        }
    tempNode = tempNode->next; 
  }
}

// function that delete node from graph
void delete_node_cmd(pnode *head)
{
 int D = 0;
    scanf("%d",&D);
    del_edge(head,D);
    pnode tempNode = *head;
    node *p = NULL;
    if(tempNode->node_num != D)
    {
        while (tempNode->next->node_num!=D)
        {
        tempNode = tempNode->next;
        }
        p = tempNode->next;
        tempNode->next=tempNode->next->next;
        delete_edges(p);
        free(p);    
    }
    else
    {
    p = *head;
    *head = p->next;
    delete_edges(p);
    free(p);
    }
}

void insert_node_cmd(pnode *head)
{
   int src;
    scanf("%d", &src);
    int dest;
    int w;
    pnode temp = get_node(src,head);
    if(temp == NULL){
        pnode inGraph = *head;
        while (inGraph->next != NULL){
            inGraph = inGraph->next;
        }
        pnode newNode = (pnode)(malloc(sizeof (node)));
        newNode->node_num = src;
        newNode->edges = NULL;
        newNode->next = NULL;
        inGraph->next = newNode;
        while (scanf("%d",&dest)!=0 && scanf("%d",&w)!=0){
            if((dest >= 'A' && dest <= 'Z') || (w >= 'A' && w <= 'Z'))
            {
                break;
            }
            if((dest >= 'a' && dest <= 'z') || (w >= 'a' && w <= 'z'))
            {
                break;
            }
            insert_e(newNode,dest,w,head);
        }
    } else{
        delete_edges(temp);
        // pedge tempEdge = temp->edges;
        temp->edges = NULL;
        while (scanf("%d",&dest)!=0 && scanf("%d",&w)!=0){
            if((dest >= 'A' && dest <= 'Z') || (w >= 'A' && w <= 'Z'))
            {
                break;
            }
            if((dest >= 'a' && dest <= 'z') || (w >= 'a' && w <= 'z'))
            {
                break;
            }
            insert_e(temp,dest,w,head);
        }
    }

}  
