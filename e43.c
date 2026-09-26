#include <stdio.h>
#include <stdlib.h>
#define ORDER 5
#define MAX_KEYS 4
#define MIN_KEYS 2
#define MAX_CHILD 5
struct node {
int keys[MAX_KEYS];
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
void insertNonFull(struct node *nd,int data) {
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
void insert(int data) {
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
printf("%d",nd->keys[i]);
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
int getPredecessor(struct node *nd) {
while(!nd->leaf) {
nd = nd->child[nd->n];
}
return nd->keys[nd->n - 1];
}
int getSuccessor(struct node *nd) {
while(!nd->leaf) {
nd = nd->child[0];
}
return nd->keys[0];
}
void merge(struct node *nd,int i) {
struct node *left = nd->child[i];
struct node *right = nd->child[i+1];
left->keys[left->n] = nd->keys[i];
left->n++;
for(int j = 0; j < right->n; j++) {
left->keys[left->n + j] = right->keys[j];
}
if(!left->leaf) {
for(int j = 0; j <= right->n; j++) {
left->child[left->n + j] = right->child[j];
}
}
left->n = left->n + right->n;
for(int j = i; j < nd->n - 1; j++) {
nd->keys[i] = nd->keys[i+1];
}
for(int j = i+1; j < nd->n; j++) {
nd->child[i] = nd->child[i+1];
}
nd->n--;
free(right);
}
void borrowFromLeft(struct node *nd,int i) {
struct node *child = nd->child[i];
struct node *left = nd->child[i-1];
for(int j = child->n - 1; j >= 0; j--) {
child->keys[j+1] = child->keys[j];
}
if(!child->leaf) {
for(int j = child->n; j >= 0; j--) {
child->child[j+1] = child->child[j];
}
}
child->keys[0] = nd->keys[i-1];
child->n++;
if(!child->leaf) {
child->child[0] = left->child[left->n];
}
nd->keys[i-1] = left->keys[left->n - 1];
left->n--;
}
void borrowFromRight(struct node *nd,int i) {
struct node *child = nd->child[i];
struct node *right = nd->child[i+1];
child->keys[child->n] = nd->keys[i];
child->n++;
if(!child->leaf) {
child->child[child->n] = right->child[0];
}
nd->keys[i] = right->keys[0];
for(int j = 0; j < right->n - 1; j++) {
right->keys[j] = right->keys[j+1];
}
if(!right->leaf) {
for(int j = 0; j < right->n; j++) {
right->child[j] = right->child[j+1];
}
}
right->n--;
}
void fix(struct node *nd,int i) {
if(i > 0 && nd->child[i-1]->n > MIN_KEYS) {
borrowFromLeft(nd,i);
} else if(i < nd->n && nd->child[i+1]->n > MIN_KEYS) {
borrowFromRight(nd,i);
} else {
if(i > 0) {
merge(nd,i-1);
} else {
merge(nd,i);
}
}
}
void delete(struct node *nd,int data) {
int i = findIndex(nd,data);
if(i < nd->n && nd->keys[i] == data) {
if(nd->leaf) {
for(int j = i; j < nd->n - 1; j++) {
nd->keys[j] = nd->keys[j+1];
}
nd->n--;
} else {
if(nd->child[i]->n > MIN_KEYS) {
int pred = getPredecessor(nd->child[i]);
nd->keys[i] = pred;
delete(nd->child[i],pred);
} else if(nd->child[i+1]->n > MIN_KEYS) {
int succ = getSuccessor(nd->child[i+1]);
nd->keys[i] = succ;
delete(nd->child[i+1],succ);
} else {
merge(nd,i);
delete(nd->child[i],data);
}
}
} else {
if(nd->leaf) {
printf("element not found");
return;
}
if(nd->child[i]->n == MIN_KEYS) {
fix(nd,i);
}
if(i > nd->n) {
delete(nd->child[i-1],data);
} else {
delete(nd->child[i],data);
}
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
printf("\nB-Tree constructed\n");
printf("Tree structure:\n");
printTree(root,0);
printf("\n");
int choice;
printf("Do u want to delete(0 or 1): ");
scanf("%d", &choice);
while(choice) {
int val;
printf("Enter element to be deleted: ");
scanf("%d", &val);
if(root == 0) {
printf("tree is empty");
return 0;
}
delete(root,val);
if(root->n == 0) {
struct node *old = root;
root = root->child[0];
free(old);
}
printf("Delete another?(0 or 1): ");
scanf("%d", &choice);
}
if(choice == 0) {
printf("Tree structure after deletion:\n");
printTree(root,0);
printf("\n");
}
return 0;
}
