#include <stdio.h>
#include <stdlib.h>
#define m 10
struct node {
int data;
struct node *next;
};
struct node *table[m];
int hashFunc(int key) {
return (2*key+3)%m;
}
void insert(int key) {
int index = hashFunc(key);
struct node *newnode,*temp;
newnode = (struct node*)malloc(sizeof(struct node));
newnode->data = key;
newnode->next = 0;
if(table[index] == 0) {
table[index] = newnode;
} else {
temp = table[index];
while(temp->next != 0) {
temp = temp->next;
}
temp->next = newnode;
}
}
void display() {
struct node *temp;
for(int i = 0; i < m; i++) {
printf("%d: ",i);
temp = table[i];
while(temp != 0) {
printf("%d->",temp->data);
temp = temp->next;
}
printf("NULL\n");
}
}
int main() {
int n,key;
for(int i = 0; i < m; i++) {
table[i] = 0;
}
printf("Enter no.of elements: ");
scanf("%d", &n);
for(int i = 0; i < n; i++) {
printf("Enter key%d: ",i);
scanf("%d", &key);
insert(key);
}
display();
return 0;
}
