#include <stdio.h>
#define MAX 10
int adj[MAX][MAX];
int flag[MAX];
int queue[MAX];
int front = -1,rear = -1;
int n;
void enqueue(int x) {
if(rear == n-1) {
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
}
int isCyclicBFS(int start) {
int current;
enqueue(start);
flag[start] = 0;
while(front != -1 && rear != -1 && front <= rear) {
current = dequeue();
flag[current] = 1;
for(int i = 0; i < n; i++) {
if(adj[current][i] == 1) {
if(flag[i] == 0) {
return 1;
}
if(flag[i] == -1) {
enqueue(i);
flag[i] = 0;
}
}
}
}
return 0;
}
int main() {
int e,u,v,start,hasCycle = 0;
char uChar,vChar,startChar;
printf("Enter no.of vertices: ");
scanf("%d", &n);
for(int i = 0; i < n; i++) {
for(int j = 0; j < n; j++) {
adj[i][j] = 0;
}
}
printf("Enter no.of edges: ");
scanf("%d", &e);
for(int i = 1; i <= e; i++) {
printf("Enter edge%d(u v): ",i);
scanf(" %c %c", &uChar, &vChar);
u = uChar - 'A';
v = vChar - 'A';
adj[u][v] = 1;
adj[v][u] = 1;
}
for(int i = 0; i < n; i++) {
flag[i] = -1;
}
printf("Enter starting vertex: ");
scanf(" %c", &startChar);
start = startChar - 'A';
if(isCyclicBFS(start)) {
hasCycle = 1;
}
for(int i = 0; i < n; i++) {
if(flag[i] == -1) {
if(isCyclicBFS(i)) {
hasCycle = 1;
}
}
}
if(hasCycle) {
printf("Graph contains a cycle.\n");
} else {
printf("Graph does not contain a cycle.\n");
}
return 0;
}
