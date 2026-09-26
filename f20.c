#include <stdio.h>
#define MAX 10
int adj[MAX][MAX];
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
if(front == -1 && rear == -1) {
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
int main() {
int u,v,e,count = 0;
char uChar,vChar;
int inDegree[MAX],topoOrder[MAX];
printf("Enter the no.of vertices: ");
scanf("%d", &n);
for(int i = 0; i < n; i++) {
inDegree[i] = 0;
for(int j = 0; j < n; j++) {
adj[i][j] = 0;
}
}
printf("Enter the no.of edges: ");
scanf("%d", &e);
for(int i = 1; i <= e; i++) {
printf("Enter edge%d(u v): ",i);
scanf(" %c %c", &uChar, &vChar);
u = uChar - 'A';
v = vChar - 'A';
adj[u][v] = 1;
}
for(int i = 0; i < n; i++) {
for(int j = 0; j < n; j++) {
if(adj[j][i] == 1) {
inDegree[i]++;
}
}
}
for(int i = 0; i < n; i++) {
if(inDegree[i] == 0) {
enqueue(i);
}
}
while(front != -1 && rear != -1 && front <= rear) {
int current = dequeue();
topoOrder[count] = current;
count++;
for(int i = 0; i < n; i++) {
if(adj[current][i] == 1) {
inDegree[i]--;
if(inDegree[i] == 0) {
enqueue(i);
}
}
}
}
if(count != n) {
printf("Graph contains a cycle");
} else {
printf("Topological order: ");
for(int i = 0; i < n; i++) {
printf("%c",'A'+topoOrder[i]);
}
}
printf("\n");
return 0;
}
