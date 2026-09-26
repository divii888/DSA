#include <stdio.h>
#define MAX 10
#define INF 9999
int graph[MAX][MAX];
int dist[MAX];
int n;
void bellmanFord(int src) {
int u,v;
for(int i = 0; i < n; i++) {
dist[i] = INF;
}
dist[src] = 0;
for(int count = 0; count < n-1; count++) {
for(u = 0; u < n; u++) {
for(v = 0; v < n; v++) {
if(graph[u][v] != 0 && dist[u] != INF && (dist[u] + graph[u][v]) < dist[v]) {
dist[v] = dist[u] + graph[u][v];
}
}
}
}
for(u = 0; u < n; u++) {
for(v = 0; v < n; v++) {
if(graph[u][v] != 0 && dist[u] != INF && (dist[u] + graph[u][v]) < dist[v]) {
printf("\nGraph contains a negative weight cycle\n");
return;
}
}
}
printf("\nVertex\tDistance\n");
for(int i = 0; i < n; i++) {
printf("%c\t",i+'A');
if(dist[i] == INF) {
printf("INF\n");
} else {
printf("%d\n",dist[i]);
}
}
}
int main() {
int src;
char ch;
printf("Enter the no.of vertices: ");
scanf("%d", &n);
printf("Enter the adjacency matrix(0 if no edge,else edge weight):\n");
for(int i = 0; i < n; i++) {
for(int j = 0; j < n; j++) {
printf("From %c to %c: ",i+'A',j+'A');
scanf("%d", &graph[i][j]);
}
}
printf("Enter the source vertex: ");
scanf(" %c", &ch);
src = ch - 'A';
bellmanFord(src);
return 0;
}
