#include <stdio.h>
#define MAX 10
int main() {
int graph[MAX][MAX];
char label[MAX];
int visited[MAX];
int keys[MAX];
int parent[MAX];
int u,v,totalWeight,min,root;
char rootLabel;
printf("Enter no.of vertices: ");
scanf("%d", &v);
printf("Enter the label of vertices:\n");
for(int i = 0; i < v; i++) {
printf("label for vertex%d: ",i);
getchar();
scanf("%c", &label[i]);
}
printf("Enter the adjacency matrix(0 for no edge, else edge weight):\n");
for(int i = 0; i < v; i++) {
for(int j = 0; j < v; j++) {
printf("Weight from %c to %c: ",label[i],label[j]);
scanf("%d", &graph[i][j]);
}
}
printf("Enter label for starting vertex(root): ");
getchar();
scanf("%c", &rootLabel);
root = -1;
for(int i = 0; i < v; i++) {
if(label[i] == rootLabel) {
root = i;
}
}
for(int i = 0; i < v; i++) {
visited[i] = 0;
parent[i] = -1;
keys[i] = 0;
}
totalWeight = 0;
for(int count = 0; count < v; count++) {
if(count == 0) {
u = root;
} else {
u = -1;
min = -1;
for(int i = 0; i < v; i++) {
if(visited[i] == 0 && keys[i] != 0) {
if(min == -1 || keys[i] < min) {
min = keys[i];
u = i;
}
}
}
}
visited[u] = 1;
if(parent[u] != -1) {
printf("Edge: %c -- %c, weight: %d\n",label[parent[u]],label[u],keys[u]);
totalWeight = totalWeight + keys[u];
}
for(int j = 0; j < v; j++) {
if(visited[j] == 0 && graph[u][j] != 0) {
if(keys[j] == 0 || graph[u][j] < keys[j]) {
keys[j] = graph[u][j];
parent[j] = u;
}
}
}
}
printf("\nTotal weight of the MST is %d\n",totalWeight);
return 0;
}
