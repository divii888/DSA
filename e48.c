#include <stdio.h>
#include <stdlib.h>
#define ORDER 5
#define MAX_CHILD 5
#define MAX_KEYS 4
#define MIN_KEYS 2
struct node {
int keys[MAX_KEYS+1];
struct node *child[MAX_CHILD+1];
struct node *next;
int n;
int leaf;
};
struct node *root = 0;
struct node *newnode() {
struct node *nd = (struct node*)malloc(sizeof(struct node));
nd->n = 0;
nd->leaf = 1;
nd->next = 0;
for(int i = 0; i < MAX_CHILD; i++) {
nd->child[i] = 0;
}
return nd;
}
int findIndex(struct node *nd,int data) {
int i = 0;
while(i < nd->n && data > nd->keys[i]) {
i++;
}
return i;
}
void insertInLeaf(struct node *nd,int data) {
int i = nd->n - 1;
while(i >= 0 && data < nd->keys[i]) {
nd->keys[i+1] = nd->keys[i];
i--;
}
nd->keys[i+1] = data;
nd->n++;
}
void splitLeaf(struct node *parent,int i) {
struct node *leftLeaf = parent->child[i];
int mid = (MAX_KEYS+1)/2;
struct node *rightLeaf = newnode();
rightLeaf->leaf = 1;
rightLeaf->n = MAX_KEYS+1-mid;
for(int j = 0; j < rightLeaf->n; j++) {
rightLeaf->keys[j] = leftLeaf->keys[mid+j];
}
leftLeaf->n = mid;
rightLeaf->next = leftLeaf->next;
leftLeaf->next = rightLeaf;
int pushUp = rightLeaf->keys[0];
for(int j = parent->n; j >= i+1; j--) {
parent->child[j+1] = parent->child[j];
}
parent->child[i+1] = rightLeaf;
for(int j = parent->n - 1; j >= i; j--) {
parent->keys[j+1] = parent->keys[j];
}
parent->keys[i] = pushUp;
parent->n++;
}
void splitInternal(struct node *parent,int i) {
struct node *fullChild = parent->child[i];
int mid = (MAX_KEYS+1)/2;
struct node *rightChild = newnode();
rightChild->leaf = 0;
rightChild->n = MAX_KEYS-mid;
for(int j = 0; j < rightChild->n; j++) {
rightChild->keys[j] = fullChild->keys[mid+1+j];
}
for(int j = 0; j <= rightChild->n; j++) {
rightChild->child[j] = fullChild->child[mid+1+j];
}
int pushUp = fullChild->keys[mid];
fullChild->n = mid;
for(int j = parent->n; j >= i+1; j--) {
parent->child[j+1] = parent->child[j];
}
parent->child[i+1] = rightChild;
for(int j = parent->n - 1; j >= i; j--) {
parent->keys[j+1] = parent->keys[j];
}
parent->keys[i] = pushUp;
parent->n++;
}
void insertNonFull(struct node *nd,int data) {
if(nd->leaf) {
insertInLeaf(nd,data);
} else {
int i = findIndex(nd,data);
insertNonFull(nd->child[i],data);
if(nd->child[i]->n > MAX_KEYS) {
if(nd->child[i]->leaf) {
splitLeaf(nd,i);
} else {
splitInternal(nd,i);
}
}
}
}
void insert(int data) {
if(root == 0) {
root = newnode();
root->n = 1;
root->keys[0] = data;
return;
}
insertNonFull(root,data);
if(root->n > MAX_KEYS) {
struct node *newRoot = newnode();
newRoot->leaf = 0;
newRoot->child[0] = root;
if(root->leaf) {
splitLeaf(newRoot,0);
} else {
splitInternal(newRoot,0);
}
root = newRoot;
}
}
void printTree(struct node *nd,int level) {
if(nd == 0) {
return;
}
printf("Level %d: [",level);
for(int i = 0; i < nd->n; i++) {
printf("%d",nd->keys[i]);
if(i < (nd->n - 1)) {
printf("|");
}
}
if(!nd->leaf) {
for(int i = 0; i < nd->n; i++) {
printTree(nd->child[i],level+1);
}
}
}
void printLeaves() {
struct node *nd = root;
while(!nd->leaf) {
nd = nd->child[0];
}
printf("Leaf linked list: ");
while(nd != 0) {
printf("[");
for(int i = 0; i < nd->n; i++) {
printf("%d",nd->keys[i]);
if(i < (nd->n - 1)) {
printf("|");
}
}
printf("]");
if(nd->next != 0) {
printf("->");
}
nd = nd->next;
}
}
int main() {
int n;
printf("Enter no.of elements: ");
scanf("%d", &n);
int arr[n];
for(int i = 0; i < n; i++) {
printf("element[%d]: ",i);
scanf("%d", &arr[i]);
insert(arr[i]);
}
printf("\nB+ Tree constructed\n");
printf("Tree structure:\n");
printTree(root,0);
printf("\n");
printLeaves();
printf("\n");
return 0;
}
