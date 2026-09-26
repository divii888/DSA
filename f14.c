#include <stdio.h>
#define MAX 10
int adj[MAX][MAX];
int stack[MAX];
int top = -1;
int flag[MAX];
int parent[MAX];
int n;
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
void printCycle(int current,int cycleVertex) {
int path[MAX],count = 0,v;
v = current;
while(v != cycleVertex) {
path[count] = v;
v = parent[v];
count++;
}
path[count] = cycleVertex;
count++;
for(int i = count-1; i >= 0; i--) {
printf("%d->",path[i]);
}
printf("%d\n",cycleVertex);
}
int detectCycle(int start) {
int current,foundUnvisited,cycleVertex;
push(start);
flag[start] = 0;
parent[start] = -1;
while(top != -1) {
current = stack[top];
foundUnvisited = 0;
cycleVertex = -1;
for(int i = 0; i < n; i++) {
if(adj[current][i] == 1) {
if(flag[i] == -1) {
push(i);
flag[i] = 0;
parent[i] = current;
foundUnvisited = 1;
break;
} else if(flag[i] == 0) {
cycleVertex = i;
break;
}
}
}
if(cycleVertex != -1) {
printCycle(current,cycleVertex);
return 1;
}
if(foundUnvisited == 0) {
flag[current] = 1;
pop();
}
}
return 0;
}
int main() {
int u,v,e,start,result;
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
}
for(int i = 0; i < n; i++) {
flag[i] = -1;
parent[i] = -1;
}
printf("Enter the starting vertex: ");
scanf("%d", &start);
result = detectCycle(start);
if(result == 1) {
printf("Graph contains a cycle.\n");
} else {
printf("Graph does not contain a cycle.\n");
}
return 0;
}
