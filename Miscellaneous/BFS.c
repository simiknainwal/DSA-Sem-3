#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct queue {
    int* arr;
    int front, rear, size, cap;
};

struct queue* initialize(int size) {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->arr = (int*)malloc(sizeof(int) * size);
    q->front = q->rear = -1;
    q->size = 0;
    q->cap = size;
    return q;
}

int isEmpty(struct queue* q) { return q->size == 0; }
int isFull(struct queue* q) { return (q->rear + 1) % q->cap == q->front; }

void enqueue(struct queue* q, int val) {
    if (isFull(q)) return;
    if (q->front == -1) q->front = q->rear = 0;
    else q->rear = (q->rear + 1) % q->cap;
    q->arr[q->rear] = val;
    q->size++;
}

int dequeue(struct queue* q) {
    if (isEmpty(q)) return -1;
    int val = q->arr[q->front];
    q->size--;
    if (q->size == 0) q->front = q->rear = -1;
    else q->front = (q->front + 1) % q->cap;
    return val;
}

void BFS(int graph[MAX][MAX], int n, int start, int end) {
    int visited[MAX] = {0};
    int parent[MAX]; // to reconstruct path
    for (int i = 0; i < n; i++) parent[i] = -1;

    struct queue* q = initialize(n);
    visited[start] = 1;
    enqueue(q, start);

    while (!isEmpty(q)) {
        int node = dequeue(q);
        if (node == end) break; // reached destination

        for (int j = 0; j < n; j++) {
            if (graph[node][j] == 1 && visited[j]==0) {
                visited[j] = 1;
                parent[j] = node;
                enqueue(q, j);
            }
        }
    }

    // reconstruct path
    if (visited[end]==0) {
        printf("\nNo route found between %d and %d\n", start, end);
        return;
    }

    int path[MAX], len = 0;
    //Backtracks from the destination to source.
    for (int v = end; v != -1; v = parent[v])
        path[len++] = v;

    printf("\nShortest (least stops) route: ");
    //Finds the length between the source and destination
    for (int i = len - 1; i >= 0; i--)
        printf("%d ", path[i]);
    printf("\nNumber of stops: %d\n", len - 2); // excluding start & end
}
