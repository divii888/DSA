#include <stdio.h>
#define MAX 10
int adj[MAX][MAX];
int n;
void DFS(int v,int flag[]) {
flag[v] = 1;
printf("%d ",v);
for(int u = 0; u < n; u++) {
if(adj[v][u] == 1 && flag[u] == -1) {
DFS(u,flag);
}
}
}
void connectedComponents() {
int flag[10];
int count = 0;
for(int v = 0; v < n; v++) {
flag[v] = -1;
}
for(int v = 0; v < n; v++) {
if(flag[v] == -1) {
DFS(v,flag);
count++;
printf("\n");
}
}
printf("Total no.of connected components = %d\n",count);
}
int main() {
int u,v,e;
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
scanf("%d %d", &u, &v);
adj[u][v] = 1;
adj[v][u] = 1;
}
connectedComponents();
return 0;
}
