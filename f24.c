#include <stdio.h>
#define MAX 20
int adj[MAX][MAX];
int stack[MAX];
int top = -1;
int starting[MAX];
int finishing[MAX];
int low[MAX];
int visited[MAX];
int parent[MAX];
int n;
int timer = 1;
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
starting[start] = timer;
low[start] = timer;
timer++;
parent[start] = -1;
printf("%c ",'A'+start);
while(top != -1) {
current = stack[top];
found = 0;
for(int i = 0; i < n; i++) {
if(adj[current][i] == 1 && visited[i] == 0) {
push(i);
visited[i] = 1;
parent[i] = current;
starting[i] = timer;
low[i] = timer;
timer++;
printf("%c ",'A'+i);
found = 1;
break;
} else if(adj[current][i] == 1 && visited[i] == 1 && i != parent[current]) {
if(starting[i] < low[current]) {
low[current] = starting[i];
}
}
}
if(found == 0) {
finishing[current] = starting[current] + 1;
printf("\n%c finished | starting = %d, finishing = %d, low = %d\n",current+'A',starting[current],finishing[current],low[current]);
int p = parent[current];
if(p != -1) {
if(low[current] < low[p]) {
low[p] = low[current];
}
if(low[current] > starting[p]) {
printf("\nBrige detected: %c - %c\n",'A'+p,'A'+current);
}
}
pop();
}
}
}
int main() {
int e,u,v,start;
char uChar,vChar,startChar;
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
scanf(" %c %c", &uChar, &vChar);
u = uChar - 'A';
v = vChar - 'A';
adj[u][v] = 1;
adj[v][u] = 1;
}
for(int i = 0; i < n; i++) {
visited[i] = 0;
starting[i] = 0;
finishing[i] = 0;
low[i] = 0;
parent[i] = -1;
}
printf("Enter starting vertex: ");
scanf(" %c", &startChar);
start = startChar - 'A';
printf("\ndfs traversal starting from %c:\n",startChar);
dfs(start);
printf("\n");
return 0;
}
