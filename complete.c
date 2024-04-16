#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a node in the adjacency list
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

// Structure to represent an adjacency list
struct AdjList {
    struct AdjListNode *head;
};

// Structure to represent a graph. A graph is an array of adjacency lists.
struct Graph {
    int V;
    struct AdjList* array;
};

// Function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since the graph is undirected, add an edge from dest to src as well
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to display the adjacency matrix
void displayAdjMatrix(struct Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->array[i].head->dest == j ? 1 : 0);
        }
        printf("\n");
    }
}

// Function to perform Breadth First Search
void BFS(struct Graph* graph, int start) {
    // Create a queue for BFS
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    int visited[MAX_VERTICES] = {0};

    // Mark the current node as visited and enqueue it
    visited[start] = 1;
    queue[rear++] = start;

    while (front != rear) {
        // Dequeue a vertex from queue and print it
        int current = queue[front++];
        printf("%d ", current);

        // Get all adjacent vertices of the dequeued vertex current
        // If an adjacent has not been visited, then mark it visited and enqueue it
        struct AdjListNode* temp = graph->array[current].head;
        while (temp != NULL) {
            int adj = temp->dest;
            if (!visited[adj]) {
                visited[adj] = 1;
                queue[rear++] = adj;
            }
            temp = temp->next;
        }
    }
}

// Recursive function for Depth First Search
void DFSUtil(struct Graph* graph, int vertex, int visited[]) {
    // Mark the current vertex as visited and print it
    visited[vertex] = 1;
    printf("%d ", vertex);

    // Recur for all the vertices adjacent to this vertex
    struct AdjListNode* temp = graph->array[vertex].head;
    while (temp != NULL) {
        int adj = temp->dest;
        if (!visited[adj])
            DFSUtil(graph, adj, visited);
        temp = temp->next;
    }
}

// Function to perform Depth First Search
void DFS(struct Graph* graph, int start) {
    int visited[MAX_VERTICES] = {0};
    DFSUtil(graph, start, visited);
}

// Driver program to test above functions
int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Display adjacency matrix
    displayAdjMatrix(graph);
    printf("\n");

    printf("BFS Traversal starting from vertex 0: ");
    BFS(graph, 0);
    printf("\n");

    printf("DFS Traversal starting from vertex 0: ");
    DFS(graph, 0);
    printf("\n");

    return 0;
}