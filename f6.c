#include <stdio.h>
#define MAX 7
int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1;
int rear = -1;
void enqueue(int x) {
if(rear == MAX-1) {
printf("overflow");
} else if(front == -1 && rear == -1) {
front = 0;
rear = 0;
queue[rear] = x;
} else {
rear++;
queue[rear] = x;
}
}
int dequeue() {
int x;
if((front == -1 && rear == -1) || front > rear) {
printf("underflow");
} else if(front == rear) {
x = queue[front];
front = -1;
rear = -1;
} else {
x = queue[front];
front++;
}
return x;
}
void bfs(int start) {
int current;
enqueue(start);
visited[start] = 1;
while(front != -1 && rear != -1 && front <= rear) {
current = dequeue();
printf("%d ",current);
for(int i = 0; i < MAX; i++) {
if(adj[current][i] == 1 && visited[i] == 0) {
enqueue(i);
visited[i] = 1;
}
}
}
}
int main() {
int n,u,v,start,isDirected,e;
printf("Enter no.of vertices: ");
scanf("%d", &n);
for(int i = 0; i < n; i++) {
for(int j = 0; j < n; j++) {
adj[i][j] = 0;
}
}
printf("Enter 0 if undirected,1 if directed: ");
scanf("%d", &isDirected);
printf("Enter no.of edges: ");
scanf("%d", &e);
for(int i = 1; i <= e; i++) {
printf("Enter edge%d(u v): ",i);
scanf("%d %d", &u, &v);
adj[u][v] = 1;
if(isDirected == 0) {
adj[v][u] = 1;
}
}
for(int i = 0; i < n; i++) {
visited[i] = 0;
}
printf("Enter the starting vertex: ");
scanf("%d", &start);
printf("BFS Traversal starting from %d:\n",start);
bfs(start);
printf("\n");
return 0;
}
