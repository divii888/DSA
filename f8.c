#include <stdio.h>
#define MAX 7
int adj[MAX][MAX];
int stack[MAX];
int top = -1;
int n;
int visited[MAX];
void push(int x) {
if(top == n-1) {
printf("overflow");
} else {
top++;
stack[top] = x;
}
}
void pop() {
if(top == -1) {
printf("underflow");
} else {
top--;
}
}
void dfs(int start) {
int current,found;
push(start);
visited[start] = 1;
printf("%d ",start);
while(top != -1) {
current = stack[top];
found = 0;
for(int i = 0; i < n; i++) {
if(adj[current][i] == 1 && visited[i] == 0) {
push(i);
visited[i] = 1;
printf("%d ",i);
found = 1;
break;
}
}
if(found == 0) {
pop();
}
}
}
int main() {
int e,u,v,isDirected,start;
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
printf("DFS Traversal starting from %d:\n",start);
dfs(start);
printf("\n");
return 0;
}
