#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <ctype.h>

int weight;
int arrlenth;
pnode graph;

void deep_copy(int *fromArr, int *toArr, int arrLenght)
{
    for (int i = 0; i < arrLenght; ++i)
    {
        toArr[i] = fromArr[i];
    }
}
void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void calcPermot(int *arr, int arrLength)
{
    int tempWeight = 0;
    for (int i = 0; i < arrLength - 1; ++i)
    {
        int distance = shortsPath_cmd(graph, arr[i], arr[i + 1]);
        if (distance == -1)
        {
            tempWeight = INT_MAX;
            return;
        }
        tempWeight += distance;
    }
    if (tempWeight < weight)
    {
        weight = tempWeight;
    }
}
void permotion(int start, int *arr, int arrLength)
{
    if (start == arrLength - 1)
    {
        calcPermot(arr, arrLength);
        return;
    }
    for (int i = start; i < arrLength; ++i)
    {
        int *arrCopy = (int *)(calloc(arrLength, sizeof(int)));
        deep_copy(arr, arrCopy, arrLength);
        swap(arrCopy, start, i);
        permotion(start + 1, arrCopy, arrLength);
        free(arrCopy);
    }
}
void TSP_cmd(pnode head)
{
	weight = INT_MAX;
	arrlenth = -1;
    graph = head;
    scanf("%d", &arrlenth);
    int *arr = (int *)(calloc(arrlenth, sizeof(int)));
    for (int i = 0; i < arrlenth; i++)
    {
        scanf("%d", &arr[i]);
    }
    int *arrCopy = (int *)(calloc(arrlenth, sizeof(int)));
    deep_copy(arr, arrCopy, arrlenth);
    permotion(0, arrCopy, arrlenth);
    free(arr);
    free(arrCopy);
    if (weight == INT_MAX)
    {
        weight = -1;
    }
    printf("TSP shortest path: %d \n", weight);
}