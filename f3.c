#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *next;
};
struct node *head[10];
void insert(int source,int dest) {
struct node *newnode,*temp;
newnode = (struct node*)malloc(sizeof(struct node));
newnode->data = dest;
newnode->next = 0;
if(head[source] == 0) {
head[source] = newnode;
} else {
temp = head[source];
while(temp->next != 0) {
temp = temp->next;
}
temp->next = newnode;
}
}
void display(int vertices) {
struct node *temp;
for(int i = 1; i <= vertices; i++) {
printf("%d: ",i);
temp = head[i];
while(temp != 0) {
printf("%d->",temp->data);
temp = temp->next;
}
printf("NULL\n");
}
}
int main() {
int vertices,edges,source,dest,isDirected;
for(int i = 0; i < 10; i++) {
head[i] = 0;
}
printf("Enter no.of vertices: ");
scanf("%d", &vertices);
printf("Enter 0 for undirected,1 for directed: ");
scanf("%d", &isDirected);
printf("Enter no.of edges: ");
scanf("%d", &edges);
for(int i = 1; i <= edges; i++) {
printf("Enter edge%d(source dest): ",i);
scanf("%d %d", &source, &dest);
insert(source,dest);
if(isDirected == 0) {
insert(dest,source);
}
}
display(vertices);
return 0;
}
