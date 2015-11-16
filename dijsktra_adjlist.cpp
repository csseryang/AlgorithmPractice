// C / C++ program for Dijkstra's shortest path algorithm for adjacency
// list representation of graph
 
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct AdjListNode
{
    int dest;
    int weight;
    struct AdjListNode *next;
};

struct AdjList
{
    struct AdjListNode *head;
};

struct Graph
{
    int V;
    struct AdjList *array;
};

struct AdjListNode *newAdjListNode(int dest, int weight)
{
    struct AdjListNode *newNode=
        (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int v)
{
    struct Graph*graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList))

    for(int i=0; i<V; ++i)
        graph->array[i].head = NULL;
    
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight)
{
    struct AdjListNode *newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    
    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

struct MinHeapNode
{
    int v;
    int dist;
};

struct MinHeap
{
    int size;
    int capacity;
    int *pos;
    struct MinHeapNode **array;
}

struct MinHeapNode *newMinHeapNode(int v, int dist)
{
    struct MinHeapNode* minHeapNode = 
        (struct MinHeapNode*) malloc(sizeof(struct MinHeap));
    minHeap->pos = (int *) malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = 
        (struct MinHeapNode ** ) malloc(capacity*sizeof(struct MinHeapNode*));
    return minHeap;
}

void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode** b)
{
    struct MinHeapNode *t = *a;
    *a = *b;
    *b = *t;
}

void minHeapify(struct MinHeap* minHeap, int idx)
{
    int smallest, left, right;
    smallest = idx;
    left = 2*idx +1;
    right = 2*idx +2;
    
    if(left < minHeap->size &&
        minHeap->array[left]->dist < minHeap->array[smallest]->dist)
        smallest = left;
        
    if(right < minHeap->size &&
        minHeap->array[right]->dist < minHeap->array[smallest]->dist)
        smallest = right;  
    if(smallest != idx)
    {
        MinHeapNode * smallestNode = minHeap->array[smallest];
        MinHeapNode * idxNode = minHeap->array[idx];
        
        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;
        
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}