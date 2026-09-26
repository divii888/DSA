#include <stdio.h>
#define MAX 10
int main() {
int graph[MAX][MAX];
char label[MAX];
int edgeU[MAX*MAX],edgeV[MAX*MAX],edgeW[MAX*MAX];
int group[MAX];
int V,u,v,numEdges,totalWeight,edgeCount,temp,oldGroup,newGroup;
printf("Enter the no.of vertices: ");
scanf("%d", &V);
printf("Enter vertex labels:\n");
for(int i = 0; i < V; i++) {
printf("Label of vertex%d: ",i);
scanf(" %c", &label[i]);
}
printf("Enter adjacency matrix(0 for no edge,else edge weight):\n");
for(int i = 0; i < V; i++) {
for(int j = 0; j < V; j++) {
printf("Weight from %c to %c: ",label[i],label[j]);
scanf("%d", &graph[i][j]);
}
}
numEdges = 0;
for(int i = 0; i < V-1; i++) {
for(int j = i+1; j < V; j++) {
if(graph[i][j] != 0) {
edgeU[numEdges] = i;
edgeV[numEdges] = j;
edgeW[numEdges] = graph[i][j];
numEdges++;
}
}
}
for(int i = 0; i < numEdges-1; i++) {
for(int j = i+1; j < numEdges; j++) {
if(edgeW[j] < edgeW[i]) {
temp = edgeW[i];
edgeW[i] = edgeW[j];
edgeW[j] = temp;
temp = edgeU[i];
edgeU[i] = edgeU[j];
edgeU[j] = temp;
temp = edgeV[i];
edgeV[i] = edgeV[j];
edgeV[j] = temp;
}
}
}
for(int i = 0; i < V; i++) {
group[i] = i;
}
totalWeight = 0;
edgeCount = 0;
for(int k = 0; k < numEdges && edgeCount < V-1; k++) {
u = edgeU[k];
v = edgeV[k];
if(group[u] != group[v]) {
printf("Edge: %c -- %c, weight: %d\n",label[u],label[v],edgeW[k]);
totalWeight = totalWeight + edgeW[k];
edgeCount++;
oldGroup = group[v];
newGroup = group[u];
for(int i = 0; i < V; i++) {
if(group[i] == oldGroup) {
group[i] = newGroup;
}
}
}
}
printf("\nTotal weight of MST = %d\n",totalWeight);
return 0;
}
