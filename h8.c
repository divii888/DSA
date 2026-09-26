#include <stdio.h>
#define m 10
int table[m];
int h1(int key) {
return (2*key+3)%m;
}
int h2(int key) {
return (3*key+1)%m;
}
void insert(int key) {
int u,v,index;
u = h1(key);
if(table[u] == -1) {
table[u] = key;
printf("Key %d inserted at index %d,probes = 1\n",key,u);
return;
}
v = h2(key);
for(int i = 0; i < m; i++) {
index = (u+v*i)%m;
if(table[index] == -1) {
table[index] = key;
printf("key %d inserted at index %d,probes = %d\n",key,index,i+1);
return;
}
}
printf("cannot insert\n");
}
void display() {
for(int i = 0; i < m; i++) {
if(table[i] == -1) {
printf("%d: EMPTY\n",i);
} else {
printf("%d: %d\n",i,table[i]);
}
}
}
int main() {
int n,key;
for(int i = 0; i < m; i++) {
table[i] = -1;
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
