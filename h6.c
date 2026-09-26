#include <stdio.h>
#define m 10
int table[m];
int hashFunc(int key) {
return (2*key+3)%m;
}
void insert(int key) {
int u,index;
u = hashFunc(key);
for(int i = 0; i < m; i++) {
index = (u+i*i)%m;
if(table[index] == -1) {
table[index] = key;
printf("Key %d inserted at index %d,probes = %d\n",key,index,i+1);
return;
}
}
printf("table is full,cannot insert");
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
