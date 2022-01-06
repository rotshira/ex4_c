#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "graph.h"

// #####  function that build the graph ######
void build_graph_cmd(pnode *head) 
{
deleteGraph_cmd(head); //Delete if a graph exists
int size=0;  //size of graph-string
scanf("%d" ,&size);
char node;
scanf("%c" , &node);
for (int i = 0; i < size; ++i)
    {
        scanf("%c", &node);
        insert_node_cmd(head);
    }
}

// #####  function that delete the graph ######
void deleteGraph_cmd(pnode* head)
{
 pnode n = *head; //start graph node
    while (n != NULL) //the string not finish
    {
        pedge e = n->edges;
        while (e != NULL) //the edge not finish
        {
            pedge tmp1 = e;
            e = e->next;
            free(tmp1);
     
        }
        pnode tmp2 = n;
        n = n->next;
        free(tmp2);
    }
    *head = NULL;
}

// #####  function that print the graph ######
void printGraph_cmd(pnode head) 
{
    pnode n = head; //start graph node
    while (n != NULL) //  the string not finish
    {
        printf("Node %d: ", n->node_num); 
        pedge e = n->edges;
        while (e != NULL)
        {
            printf("D= %d: W= %d, ", e->endpoint->node_num, e->weight); // print end node id + weight
            e = e->next;
        }
        printf("\n");
        n = n->next;
    }
}

// ######### function that return pointer node by him id
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

// ########## function that delete node from graph
void delete_node_cmd(pnode *head)
{
    if(! head){
        return;
    }
    if(!(*head))
        return;
    int num;
    scanf("%d" , &num); // node to remove
    node * pointer =*head; // pointer to head
    while(pointer != NULL) {
    if( pointer ->node_num ==num) {
        node * pointer2 = pointer ->next;
        while(pointer2  !=NULL && pointer2 ->node_num ==num )
        {
            pointer2 = pointer2 ->next;
        }
        if( &pointer == head){
            * head = pointer2;
        }
        if (&pointer != head){
            (*head) ->next = pointer2;
        }
        while(pointer !=pointer2){
            node * p= pointer;
            //free the edges
            pedge pf;
            pedge pass_edge =p ->edges;
            while (pass_edge){
                pf =pass_edge ;
                pass_edge = pass_edge->next;
                free(pf);
            }
            pointer =pointer->next;
            free(p);
        }
        }
        pointer = pointer ->next;
  }
}

// ########## function that insert node to graph
void insert_node_cmd(pnode *head){
    //the first node we need to creat  
    node* new = (node*) malloc(sizeof(node));
    if(!new) 
    {
        printf("error");
        return;
    }
        //there is no elements in the list
        if(!(*head)){
            int num_of_node;
            scanf("%d " , &num_of_node) ;
            new -> next = NULL;
            new ->edges = NULL;
            new ->node_num = num_of_node;
            *head = new;
            //start to ger edges
            edge* pass_e ;
            while (scanf("%d " , &num_of_node) ==1 ) {
            edge* new_e = (edge*) malloc(sizeof(edge));
            if(!new_e) {
                printf("error");
                return;
                }
            int wight_of_node;
            scanf("%d" , &wight_of_node);
            node* endpoint = (node*) malloc(sizeof(node));
            if(!endpoint) {
                printf("error");
                return;}
            endpoint ->node_num = num_of_node;
            new_e -> endpoint =endpoint;
            new_e->weight=wight_of_node;
            if(new ->edges == NULL){
                new ->edges = new_e;
                pass_e = new_e;
            }
            else{
                pass_e ->next =new_e;
                pass_e = new_e;
            }
        }}
        else{
            int num_of_node;
            scanf("%d " , &num_of_node) ;
          
            node * pass =(*head);
            while(pass ->next != NULL &&pass ->node_num != num_of_node){
                pass = pass->next;
            }
            if(pass ->next != NULL){
                node * j =  pass ->next;
                pass ->next =pass ->next->next;
                free(j);
                while(pass ->next != NULL){
                    pass = pass->next;
                }
            }
            new -> next = NULL;
            new ->edges = NULL;
            new ->node_num = num_of_node;
            pass ->next =new;
            edge* pass_e = new->edges;
            while (scanf("%d " , &num_of_node)==1 && scanf("%d " , &num_of_node)==' ') {
                edge* new_e = (edge*) malloc(sizeof(edge));
                if(!new_e) {
                    printf("error");
                    return;}
                int wight_of_node;
                scanf("%d" , &wight_of_node);
                node* endpoint = (node*) malloc(sizeof(node));
                if(!endpoint) {
                    printf("error");
                    return;}
                endpoint ->node_num = num_of_node;
                new_e -> endpoint =endpoint;
                new_e->weight=wight_of_node;
                if(new ->edges == NULL){
                    new ->edges = new_e;
                    pass_e = new_e;
                }
                else{
                    pass_e ->next =new_e;
                    pass_e = new_e;
                }
                }
        }
        }



    

  