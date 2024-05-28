// question 4 (all inputs )

#include <stdio.h>
#include <stdlib.h>

// Define the structure for items
typedef struct {
    int weight;
    int cost;
    float ratio;
} Item;

// Comparison function for qsort to sort items by their ratio in descending order
int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    if (itemB->ratio > itemA->ratio) return 1;
    else if (itemB->ratio < itemA->ratio) return -1;
    else return 0;
}

// Function to calculate the maximum cost that can be carried in the knapsack
void fractionalKnapsack(Item items[], int n, int capacity) {
    // Calculate the ratio (cost/weight) for each item
    for (int i = 0; i < n; i++) {
        items[i].ratio = (float)items[i].cost / items[i].weight;
    }

    // Sort the items based on the ratio in descending order
    qsort(items, n, sizeof(Item), compare);

    int currentWeight = 0;
    float totalCost = 0.0;

    // Pick items to maximize the total cost within the given capacity
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalCost += items[i].cost;
        } else {
            int remain = capacity - currentWeight;
            totalCost += items[i].cost * ((float)remain / items[i].weight);
            break;
        }
    }

    printf("Maximum cost in the knapsack: %.2f\n", totalCost);
}

int main() {
    // Initialize items with their weights and costs
    Item items[] = {
        {12, 24, 0},
        {5, 15, 0},
        {7, 28, 0},
        {6, 18, 0},
        {8, 8, 0}
    };

    // Number of items
    int n = sizeof(items) / sizeof(items[0]);
    // Capacity of the knapsack
    int capacity = 23;

    // Calculate and print the maximum cost for the fractional knapsack problem
    fractionalKnapsack(items, n, capacity);

    return 0;
}



//question 4 user input

#include <stdio.h>
#include <stdlib.h>

// Define the structure for items
typedef struct {
    int weight;
    int cost;
    float ratio;
} Item;

// Comparison function for qsort to sort items by their ratio in descending order
int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    if (itemB->ratio > itemA->ratio) return 1;
    else if (itemB->ratio < itemA->ratio) return -1;
    else return 0;
}

// Function to calculate the maximum cost that can be carried in the knapsack
void fractionalKnapsack(Item items[], int n, int capacity) {
    // Calculate the ratio (cost/weight) for each item
    for (int i = 0; i < n; i++) {
        items[i].ratio = (float)items[i].cost / items[i].weight;
    }

    // Sort the items based on the ratio in descending order
    qsort(items, n, sizeof(Item), compare);

    int currentWeight = 0;
    float totalCost = 0.0;

    // Pick items to maximize the total cost within the given capacity
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalCost += items[i].cost;
        } else {
            int remain = capacity - currentWeight;
            totalCost += items[i].cost * ((float)remain / items[i].weight);
            break;
        }
    }

    printf("Maximum cost in the knapsack: %.2f\n", totalCost);
}

int main() {
    int n, capacity;

    // Get the number of items from the user
    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Allocate memory for the items
    Item *items = (Item *)malloc(n * sizeof(Item));

    // Get the weight and cost for each item from the user
    for (int i = 0; i < n; i++) {
        printf("Enter weight and cost for item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].cost);
    }

    // Get the capacity of the knapsack from the user
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    // Calculate and print the maximum cost for the fractional knapsack problem
    fractionalKnapsack(items, n, capacity);

    // Free the allocated memory
    free(items);

    return 0;
}


// question 3(direct input )


#include <stdio.h>
#include <stdbool.h>

#define N 4

void printSolution(int board[N][N]) {
    static int count = 1;
    printf("Solution %d:\n", count++);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check this row on the left side
    for (i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    // Check the upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check the lower diagonal on the left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

bool solveNQUtil(int board[N][N], int col) {
    // If all queens are placed, return true
    if (col >= N) {
        printSolution(board);
        return true;
    }

    bool res = false;
    // Try placing this queen in all rows one by one
    for (int i = 0; i < N; i++) {
        // Check if the queen can be placed on board[i][col]
        if (isSafe(board, i, col)) {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Make result true if any placement is possible
            res = solveNQUtil(board, col + 1) || res;

            // If placing queen in board[i][col] doesn't lead to a solution, then remove queen from board[i][col]
            board[i][col] = 0; // BACKTRACK
        }
    }

    // If the queen can not be placed in any row in this column col, return false
    return res;
}

void solveNQ() {
    int board[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };

    if (!solveNQUtil(board, 0)) {
        printf("Solution does not exist");
        return;
    }
}

int main() {
    solveNQ();
    return 0;
}


//question 3 (with user input )


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void printSolution(int** board, int N) {
    static int count = 1;
    printf("Solution %d:\n", count++);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int** board, int row, int col, int N) {
    int i, j;

    // Check this row on the left side
    for (i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    // Check the upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check the lower diagonal on the left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

bool solveNQUtil(int** board, int col, int N) {
    // If all queens are placed, return true
    if (col >= N) {
        printSolution(board, N);
        return true;
    }

    bool res = false;
    // Try placing this queen in all rows one by one
    for (int i = 0; i < N; i++) {
        // Check if the queen can be placed on board[i][col]
        if (isSafe(board, i, col, N)) {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Make result true if any placement is possible
            res = solveNQUtil(board, col + 1, N) || res;

            // If placing queen in board[i][col] doesn't lead to a solution, then remove queen from board[i][col]
            board[i][col] = 0; // BACKTRACK
        }
    }

    // If the queen cannot be placed in any row in this column col, return false
    return res;
}

void solveNQ(int N) {
    // Dynamically allocate the board
    int** board = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        board[i] = (int*)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    if (!solveNQUtil(board, 0, N)) {
        printf("Solution does not exist\n");
    }

    // Free the dynamically allocated board
    for (int i = 0; i < N; i++) {
        free(board[i]);
    }
    free(board);
}

int main() {
    int N;
    printf("Enter the size of the chessboard (N): ");
    scanf("%d", &N);

    solveNQ(N);
    return 0;
}


//auestion no 2 (direct input )

#include <stdio.h>

// Function to perform binary search recursively
int binarySearch(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the target is present at mid
        if (arr[mid] == target) {
            return mid;
        }

        // If the target is smaller than mid, it must be in the left subarray
        if (arr[mid] > target) {
            return binarySearch(arr, left, mid - 1, target);
        }

        // Otherwise, the target must be in the right subarray
        return binarySearch(arr, mid + 1, right, target);
    }

    // If the target is not present in the array
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1) {
        printf("Target %d found at index %d.\n", target, result);
    } else {
        printf("Target %d not found in the array.\n", target);
    }

    return 0;
}


//question 2 (user input)

#include <stdio.h>
#include <stdlib.h>

// Function to perform binary search recursively
int binarySearch(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the target is present at mid
        if (arr[mid] == target) {
            return mid;
        }

        // If the target is smaller than mid, it must be in the left subarray
        if (arr[mid] > target) {
            return binarySearch(arr, left, mid - 1, target);
        }

        // Otherwise, the target must be in the right subarray
        return binarySearch(arr, mid + 1, right, target);
    }

    // If the target is not present in the array
    return -1;
}

int main() {
    int n, target;

    // Taking the number of elements in the array as input from the user
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Allocating memory for the array
    int *arr = (int *)malloc(n * sizeof(int));

    // Taking the array elements as input from the user
    printf("Enter the elements of the array in sorted order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Taking the target element as input from the user
    printf("Enter the target number: ");
    scanf("%d", &target);

    // Calling the binarySearch function
    int result = binarySearch(arr, 0, n - 1, target);

    // Printing the result
    if (result != -1) {
        printf("Target %d found at index %d.\n", target, result);
    } else {
        printf("Target %d not found in the array.\n", target);
    }

    // Freeing the allocated memory
    free(arr);

    return 0;
}


// question 5 (user input )

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 7 // Number of vertices in the graph

// Function to find the vertex with the minimum key value, from the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

// Function to print the constructed MST stored in parent[]
void printMST(int parent[], int graph[V][V]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

// Function to construct and print MST for a graph represented using adjacency matrix representation
void primMST(int graph[V][V]) {
    int parent[V]; // Array to store constructed MST
    int key[V];    // Key values used to pick minimum weight edge in cut
    bool mstSet[V]; // To represent set of vertices not yet included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    // Always include first 1st vertex in MST.
    key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < V; v++)

            // graph[u][v] is non-zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // print the constructed MST
    printMST(parent, graph);
}

int main() {
    int graph[V][V];

    // Initialize the graph with 0s
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;

    int E;
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    printf("Enter the edges and their weights in the format: u v w\n");
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // Since the graph is undirected
    }

    // Print the solution
    primMST(graph);

    return 0;
}


/*output 
Enter the number of edges: 9
Enter the edges and their weights in the format: u v w
0 1 10
0 5 25
1 2 28
1 6 14
2 3 16
3 4 12
4 5 22
5 6 24
6 3 18

Edge   Weight
0 - 1    10
1 - 6    14
1 - 2    28
2 - 3    16
3 - 4    12
4 - 5    22

*/


// question 5 ( direct input)

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 7 // Number of vertices in the graph

// Function to find the vertex with the minimum key value, from the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

// Function to print the constructed MST stored in parent[]
void printMST(int parent[], int graph[V][V]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

// Function to construct and print MST for a graph represented using adjacency matrix representation
void primMST(int graph[V][V]) {
    int parent[V]; // Array to store constructed MST
    int key[V];    // Key values used to pick minimum weight edge in cut
    bool mstSet[V]; // To represent set of vertices not yet included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    // Always include first 1st vertex in MST.
    key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < V; v++)

            // graph[u][v] is non-zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // print the constructed MST
    printMST(parent, graph);
}

int main() {
    // Hardcoded adjacency matrix for the given graph
    int graph[V][V] = {
        { 0, 10, 0, 0, 0, 25, 0 },
        { 10, 0, 28, 0, 0, 0, 14 },
        { 0, 28, 0, 16, 0, 0, 0 },
        { 0, 0, 16, 0, 12, 0, 18 },
        { 0, 0, 0, 12, 0, 22, 0 },
        { 25, 0, 0, 0, 22, 0, 24 },
        { 0, 14, 0, 18, 0, 24, 0 }
    };

    // Print the solution
    primMST(graph);

    return 0;
}


//question no 8 (with user input)

#include <stdio.h>
#include <stdlib.h>

// A structure to represent a weighted edge in graph
struct Edge {
    int src, dest, weight;
};

// A structure to represent a connected, undirected and weighted graph
struct Graph {
    int V, E;
    struct Edge* edge;
};

// A structure to represent a subset for union-find
struct subset {
    int parent;
    int rank;
};

// Function prototypes
struct Graph* createGraph(int V, int E);
int find(struct subset subsets[], int i);
void Union(struct subset subsets[], int x, int y);
int compare(const void* a, const void* b);
void KruskalMST(struct Graph* graph);

// Main function
int main() {
    int V = 7; // Number of vertices in the graph
    int E;     // Number of edges in the graph

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    struct Graph* graph = createGraph(V, E);

    printf("Enter the edges and their weights in the format: src dest weight\n");
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph->edge[i].src = u;
        graph->edge[i].dest = v;
        graph->edge[i].weight = w;
    }

    KruskalMST(graph);

    return 0;
}

// Create a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*) malloc(graph->E * sizeof(struct Edge));
    return graph;
}

// A utility function to find set of an element i (uses path compression technique)
int find(struct subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// A function that does union of two sets of x and y (uses union by rank)
void Union(struct subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare two edges according to their weights (for qsort)
int compare(const void* a, const void* b) {
    struct Edge* a1 = (struct Edge*) a;
    struct Edge* b1 = (struct Edge*) b;
    return a1->weight > b1->weight;
}

// The main function to construct MST using Kruskal's algorithm
void KruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V]; // This will store the resultant MST
    int e = 0; // An index variable, used for result[]
    int i = 0; // An index variable, used for sorted edges

    // Step 1: Sort all the edges in non-decreasing order of their weight
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compare);

    // Allocate memory for creating V subsets
    struct subset* subsets = (struct subset*) malloc(V * sizeof(struct subset));

    // Create V subsets with single elements
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && i < graph->E) {
        // Step 2: Pick the smallest edge. And increment the index for next iteration
        struct Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge does not cause cycle, include it in result
        // and increment the index of result for next edge
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    // Print the contents of result[] to display the built MST
    printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);

    // Free allocated memory
    free(subsets);
    free(graph->edge);
    free(graph);
}


/*out put

Enter the number of edges: 9
Enter the edges and their weights in the format: src dest weight
0 1 10
0 5 25
1 2 28
1 6 14
2 3 16
3 4 12
4 5 22
5 6 24
6 3 18

Following are the edges in the constructed MST
0 -- 1 == 10
1 -- 6 == 14
2 -- 3 == 16
3 -- 4 == 12
4 -- 5 == 22
6 -- 3 == 18
*/



//question 8 (direct input)

#include <stdio.h>
#include <stdlib.h>

// A structure to represent a weighted edge in the graph
struct Edge {
    int src, dest, weight;
};

// A structure to represent a connected, undirected, and weighted graph
struct Graph {
    int V, E;
    struct Edge* edge;
};

// A structure to represent a subset for union-find
struct subset {
    int parent;
    int rank;
};

// Function prototypes
struct Graph* createGraph(int V, int E);
int find(struct subset subsets[], int i);
void Union(struct subset subsets[], int x, int y);
int compare(const void* a, const void* b);
void KruskalMST(struct Graph* graph);

// Main function
int main() {
    int V = 7; // Number of vertices in the graph
    int E = 9; // Number of edges in the graph

    struct Graph* graph = createGraph(V, E);

    // Add edges with their weights
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    graph->edge[1].src = 0;
    graph->edge[1].dest = 5;
    graph->edge[1].weight = 25;

    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 28;

    graph->edge[3].src = 1;
    graph->edge[3].dest = 6;
    graph->edge[3].weight = 14;

    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 16;

    graph->edge[5].src = 3;
    graph->edge[5].dest = 4;
    graph->edge[5].weight = 12;

    graph->edge[6].src = 4;
    graph->edge[6].dest = 5;
    graph->edge[6].weight = 22;

    graph->edge[7].src = 5;
    graph->edge[7].dest = 6;
    graph->edge[7].weight = 24;

    graph->edge[8].src = 6;
    graph->edge[8].dest = 3;
    graph->edge[8].weight = 18;

    KruskalMST(graph);

    return 0;
}

// Create a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*) malloc(graph->E * sizeof(struct Edge));
    return graph;
}

// A utility function to find set of an element i (uses path compression technique)
int find(struct subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// A function that does union of two sets of x and y (uses union by rank)
void Union(struct subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare two edges according to their weights (for qsort)
int compare(const void* a, const void* b) {
    struct Edge* a1 = (struct Edge*) a;
    struct Edge* b1 = (struct Edge*) b;
    return a1->weight > b1->weight;
}

// The main function to construct MST using Kruskal's algorithm
void KruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V]; // This will store the resultant MST
    int e = 0; // An index variable, used for result[]
    int i = 0; // An index variable, used for sorted edges

    // Step 1: Sort all the edges in non-decreasing order of their weight
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compare);

    // Allocate memory for creating V subsets
    struct subset* subsets = (struct subset*) malloc(V * sizeof(struct subset));

    // Create V subsets with single elements
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && i < graph->E) {
        // Step 2: Pick the smallest edge. And increment the index for next iteration
        struct Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge does not cause cycle, include it in result
        // and increment the index of result for next edge
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    // Print the contents of result[] to display the built MST
    printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);

    // Free allocated memory
    free(subsets);
    free(graph->edge);
    free(graph);
}



//question 7 Iuser input )

#include <stdio.h>
#include <limits.h>

#define INF 99999

// Function to print the solution matrix
void printSolution(int dist[][4], int V);

// Function to implement Floyd-Warshall algorithm
void floydWarshall(int graph[][4], int V) {
    int dist[V][V], i, j, k;

    // Initialize the solution matrix same as input graph matrix
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Add all vertices one by one to the set of intermediate vertices.
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(dist, V);
}

// Function to print the shortest distance matrix
void printSolution(int dist[][4], int V) {
    printf("The following matrix shows the shortest distances"
           " between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int V = 4;  // Number of vertices in the graph

    // Define the graph as an adjacency matrix
    int graph[4][4] = {
        {0, 1, 8, INF},
        {INF, 0, 2, 1},
        {4, INF, 0, 9},
        {INF, INF, INF, 0}
    };

    // Print the input graph
    printf("Input graph matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", graph[i][j]);
        }
        printf("\n");
    }

    // Execute Floyd-Warshall algorithm
    floydWarshall(graph, V);

    return 0;
}

/* jai graph ta dewa aache tar jonno 
  (0) --1--> (1)
   |        / |  \
  4|       2  |   8
   |     /    |     \
  (3)<-9---(2)<-1--(1)


input adjacency matrix 
0     1     8   INF
INF   0     2     1
4   INF     0     9
INF INF   INF     0

output adjacency matrix
0     1     3     2
6     0     2     1
4     5     0     3
INF INF INF     0
*/



//question 7 (direct input )

#include <stdio.h>
#include <limits.h>

#define INF 99999
#define V 4 // Number of vertices in the graph

// Function to print the solution matrix
void printSolution(int dist[][V]);

// Function to implement Floyd-Warshall algorithm
void floydWarshall(int graph[][V]) {
    int dist[V][V], i, j, k;

    // Initialize the solution matrix same as input graph matrix
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Add all vertices one by one to the set of intermediate vertices.
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(dist);
}

// Function to print the shortest distance matrix
void printSolution(int dist[][V]) {
    printf("The following matrix shows the shortest distances"
           " between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Define the graph as an adjacency matrix
    int graph[V][V] = {
        {0, 1, 8, INF},
        {INF, 0, 2, 1},
        {4, INF, 0, 9},
        {INF, INF, INF, 0}
    };

    // Print the input graph
    printf("Input graph matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", graph[i][j]);
        }
        printf("\n");
    }

    // Execute Floyd-Warshall algorithm
    floydWarshall(graph);

    return 0;
}



//question 6 (user input )

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
    int* visited;
} Graph;

typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function to create a node
Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(Node*));
    graph->visited = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Function to add edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (since the graph is undirected)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to create a queue
Queue* createQueue() {
    Queue* q = malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

// Adding elements into queue
void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1)
        printf("\nQueue is Full!!");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Removing elements from queue
int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

// BFS algorithm
void bfs(Graph* graph, int startVertex) {
    Queue* q = createQueue();

    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("Visited %d\n", currentVertex);

        Node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int vertices = 7;
    Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 5);
    addEdge(graph, 2, 4);
    addEdge(graph, 2, 6);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 6);

    bfs(graph, 0);

    return 0;
}



//question 6 (direct input )


#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
    int* visited;
} Graph;

typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function to create a node
Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(Node*));
    graph->visited = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Function to add edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (since the graph is undirected)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to create a queue
Queue* createQueue() {
    Queue* q = malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

// Adding elements into queue
void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1)
        printf("\nQueue is Full!!");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Removing elements from queue
int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

// BFS algorithm
void bfs(Graph* graph, int startVertex) {
    Queue* q = createQueue();

    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("Visited %d\n", currentVertex);

        Node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int vertices = 7;
    Graph* graph = createGraph(vertices);

    // Adding edges based on the provided graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 5);
    addEdge(graph, 2, 4);
    addEdge(graph, 2, 6);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 6);

    // Starting BFS from vertex 0
    bfs(graph, 0);

    return 0;
}
