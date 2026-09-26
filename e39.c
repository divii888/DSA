#include <stdio.h>
#include <stdlib.h>
#define ORDER 5
#define MAX_CHILD 5
#define MAX_KEYS 4
struct node {
char keys[MAX_KEYS];
struct node *child[MAX_CHILD];
int n;
int leaf;
};
struct node *root = 0;
struct node *newnode() {
struct node *nd = (struct node*)malloc(sizeof(struct node));
nd->n = 0;
nd->leaf = 1;
for(int i = 0; i < MAX_CHILD; i++) {
nd->child[i] = 0;
}
return nd;
}
int findIndex(struct node *nd,char data) {
int i = 0;
while(i < nd->n && data > nd->keys[i]) {
i++;
}
return i;
}
void insertInLeaf(struct node *nd,char data) {
int i = nd->n - 1;
while(i >= 0 && data < nd->keys[i]) {
nd->keys[i+1] = nd->keys[i];
i--;
}
nd->keys[i+1] = data;
nd->n++;
}
void splitChild(struct node *parent,int i) {
struct node *fullChild = parent->child[i];
int mid = MAX_KEYS/2;
struct node *rightChild = newnode();
rightChild->leaf = fullChild->leaf;
rightChild->n = MAX_KEYS-mid-1;
for(int j = 0; j < rightChild->n; j++) {
rightChild->keys[j] = fullChild->keys[mid+1+j];
}
if(!fullChild->leaf) {
for(int j = 0; j <= rightChild->n; j++) {
rightChild->child[j] = fullChild->child[mid+1+j];
}
}
fullChild->n = mid;
for(int j = parent->n; j >= i+1; j--) {
parent->child[j+1] = parent->child[j];
}
parent->child[i+1] = rightChild;
for(int j = parent->n - 1; j >= i; j--) {
parent->keys[j+1] = parent->keys[j];
}
parent->keys[i] = fullChild->keys[mid];
parent->n++;
}
void insertNonFull(struct node *nd,char data) {
if(nd->leaf) {
insertInLeaf(nd,data);
} else {
int i = findIndex(nd,data);
if(nd->child[i]->n == MAX_KEYS) {
splitChild(nd,i);
if(data > nd->keys[i]) {
i++;
}
}
insertNonFull(nd->child[i],data);
}
}
void insert(char data) {
if(root == 0) {
root = newnode();
root->n = 1;
root->keys[0] = data;
return;
}
if(root->n == MAX_KEYS) {
struct node *newRoot = newnode();
newRoot->leaf = 0;
newRoot->child[0] = root;
splitChild(newRoot,0);
root = newRoot;
}
insertNonFull(root,data);
}
void printTree(struct node *nd,int level) {
if(nd == 0) {
return;
}
printf("Level %d: [",level);
for(int i = 0; i < nd->n; i++) {
printf("%c",nd->keys[i]);
if(i < (nd->n - 1)) {
printf("|");
}
}
printf("]\n");
if(!nd->leaf) {
for(int i = 0; i <= nd->n; i++) {
printTree(nd->child[i],level+1);
}
}
}
int main() {
int n;
printf("Enter no.of elements: ");
scanf("%d", &n);
char arr[n];
for(int i = 0; i < n; i++) {
printf("element[%d]: ",i);
getchar();
scanf("%c", &arr[i]);
}
for(int i = 0; i < n -1; i++) {
for(int j = i+1; j < n; j++) {
char temp;
if(arr[i] > arr[j]) {
temp = arr[i];
arr[i]= arr[j];
arr[j] = temp;
}
}
}
for(int i = 0; i < n; i++) {
insert(arr[i]);
}
printf("\nB-Tree constructed\n");
printf("Tree structure:\n");
printTree(root,0);
printf("\n");
return 0;
}
