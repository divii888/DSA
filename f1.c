#include <stdio.h>
#define MAX 10
int adj[MAX][MAX];
int n;
int isDirected;
void initMatrix() {
for(int i = 1; i <= n; i++) {
for(int j = 1; j <= n; j++) {
adj[i][j] = 0;
}
}
}
void addEdge(int u,int v) {
adj[u][v] = 1;
if(isDirected == 0) {
adj[v][u] = 1;
}
}
void printMatrix() {
for(int j = 1; j <= n; j++) {
printf(" %d",j);
}
printf("\n");
for(int i = 1; i <= n; i++) {
printf("%d ",i);
for(int j = 1; j <= n; j++) {
printf("%d ",adj[i][j]);
}
printf("\n");
}
}
int main() {
int e,u,v;
printf("Enter no.of vertices: ");
scanf("%d", &n);
printf("Enter 0 for undirected and 1 for directed: ");
scanf("%d", &isDirected);
initMatrix();
printf("Enter no.of edges: ");
scanf("%d", &e);
for(int i = 1; i <= e; i++) {
printf("Enter edge%d(u v): ",i);
scanf("%d %d", &u, &v);
addEdge(u,v);
}
printf("\n");
printMatrix();
printf("\n");
return 0;
}
