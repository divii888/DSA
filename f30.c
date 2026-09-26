#include <stdio.h>
#define MAX 10
#define INF 9999
int graph[MAX][MAX];
int dist[MAX][MAX];
int n;
void floydWarshall() {
for(int i = 0; i < n; i++) {
for(int j = 0; j < n; j++) {
if(i == j) {
dist[i][j] = 0;
} else if(graph[i][j] == 0) {
dist[i][j] = INF;
} else {
dist[i][j] = graph[i][j];
}
}
}
for(int k = 0; k < n; k++) {
for(int i = 0; i < n; i++) {
for(int j = 0; j < n; j++) {
if(dist[i][k] != INF && dist[k][j] != INF && (dist[i][k] + dist[k][j]) < dist[i][j]) {
dist[i][j] = dist[i][k] + dist[k][j];
}
}
}
}
}
int main() {
printf("Enter no.of vertices: ");
scanf("%d", &n);
printf("Enter adjacency matrix(0 if no edge,else edge weight):\n");
for(int i = 0; i < n; i++) {
for(int j = 0; j < n; j++) {
printf("From %d to %d: ",i,j);
scanf("%d", &graph[i][j]);
}
}
floydWarshall();
for(int i = 0; i < n; i++) {
for(int j = 0; j < n; j++) {
if(i == j) {
continue;
}
printf("Shortest dist from %d to %d: ",i,j);
if(dist[i][j] == INF) {
printf("unreachable\n");
} else {
printf("%d\n",dist[i][j]);
}
}
}
return 0;
}
