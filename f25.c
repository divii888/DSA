#include <stdio.h>
#define MAX 10
#define INF 9999
int graph[MAX][MAX];
int visited[MAX];
int parent[MAX];
int dist[MAX];
int n;
void dijkstra(int src) {
int u,v;
for(int i = 0; i < n; i++) {
visited[i] = 0;
parent[i] = -1;
dist[i] = INF;
}
dist[src] = 0;
for(int count = 0; count < n-1; count++) {
int min = INF,minIndex = -1;
for(v = 0; v < n; v++) {
if(visited[v] == 0 && dist[v] < min) {
min = dist[v];
minIndex = v;
}
}
if(minIndex == -1) {
break;
}
u = minIndex;
visited[u] = 1;
for(v = 0; v < n; v++) {
if(visited[v] == 0 && graph[u][v] != 0 && dist[u] != INF && (dist[u] + graph[u][v]) < dist[v]) {
dist[v] = dist[u] + graph[u][v];
parent[v] = u;
}
}
}
}
void printPath(int v) {
if(parent[v] == -1) {
printf("%c",'A'+v);
return;
}
printPath(parent[v]);
printf("-> %c",'A'+v);
}
int main() {
int src;
char ch;
printf("Enter no.of vertices: ");
scanf("%d", &n);
printf("Enter adjacency matrix(0 for no edge,else edge weight): ");
for(int i = 0; i < n; i++) {
for(int j = 0; j < n; j++) {
printf("From %c to %c: ",i+'A',j+'A');
scanf("%d", &graph[i][j]);
}
}
printf("Enter source vertex: ");
scanf(" %c", &ch);
src = ch - 'A';
dijkstra(src);
printf("\nVertex\tDistance\tPath\n");
for(int i = 0; i < n; i++) {
printf("%c\t",i+'A');
if(dist[i] == INF) {
printf("INF\t\tunreachable\n");
} else {
printf("%d\t\t",dist[i]);
printPath(i);
printf("\n");
}
}
return 0;
}
