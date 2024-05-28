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
