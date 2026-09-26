#include <stdio.h>
#include <stdlib.h>
#define ORDER 4
#define MAX_CHILD 4
#define MAX_KEYS 3
#define MIN_KEYS 1
struct node {
int keys[MAX_KEYS];
struct node *child[MAX_CHILD];
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
int mid = MAX_KEYS/2;
struct node *rightLeaf = newnode();
rightLeaf->leaf = 1;
rightLeaf->n = MAX_KEYS-mid;
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
int mid = MAX_KEYS/2;
struct node *rightChild = newnode();
rightChild->leaf = 0;
rightChild->n = MAX_KEYS-mid-1;
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
struct node *ch = nd->child[i];
if(ch->n == MAX_KEYS) {
if(ch->leaf) {
splitLeaf(nd,i);
} else {
splitInternal(nd,i);
}
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
if(root->leaf) {
splitLeaf(newRoot,0);
} else {
splitInternal(newRoot,0);
}
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
void removeFromLeaf(struct node *nd,int data) {
int i = findIndex(nd,data);
for(int j = i; j < nd->n - 1; j++) {
nd->keys[j] = nd->keys[j+1];
}
nd->n--;
}
int getMin(struct node *nd) {
while(!nd->leaf) {
nd = nd->child[0];
}
return nd->keys[0];
}
void borrowFromLeft(struct node *parent,int i) {
struct node *child = parent->child[i];
struct node *left = parent->child[i-1];
if(child->leaf) {
for(int j = child->n - 1; j >= 0; j--) {
child->keys[j+1] = child->keys[j];
}
child->keys[0] = left->keys[left->n - 1];
child->n++;
left->n--;
parent->keys[i-1] = child->keys[0];
} else {
for(int j = child->n - 1; j >= 0; j--) {
child->keys[j+1] = child->keys[j];
}
for(int j = child->n; j >= 0; j--) {
child->child[j+1] = child->child[j];
}
child->keys[0] = parent->keys[i-1];
child->n++;
child->child[0] = left->child[left->n];
parent->keys[i-1] = left->keys[left->n - 1];
left->n--;
}
}
void borrowFromRight(struct node *parent,int i) {
struct node *child = parent->child[i];
struct node *right = parent->child[i+1];
if(child->leaf) {
child->keys[child->n] = right->keys[0];
child->n++;
for(int j = 0; j < right->n - 1; j++) {
child->keys[j] = child->keys[j+1];
}
right->n--;
parent->keys[i] = right->keys[0];
} else {
child->keys[child->n] = parent->keys[i];
child->n++;
child->child[child->n] = right->child[0];
parent->keys[i] = right->keys[0];
for(int j = 0; j < right->n - 1; j++) {
right->keys[j] = right->keys[j+1];
}
for(int j = 0; j < right->n; j++) {
right->child[j] = right->child[j+1];
}
right->n--;
}
}
void merge(struct node *parent,int i) {
struct node *left = parent->child[i];
struct node *right = parent->child[i];
if(left->leaf) {
for(int j = 0; j < right->n; j++) {
left->keys[left->n + j] = right->keys[j];
}
left->n = left->n + right->n;
left->next = right->next;
} else {
left->keys[left->n] = parent->keys[i];
left->n++;
for(int j = 0; j < right->n; j++) {
left->keys[left->n + j] = right->keys[j];
}
for(int j = 0; j <= right->n; j++) {
left->child[left->n +j] = right->child[j];
}
left->n = left->n + right->n;
}
for(int j = i; j < parent->n - 1; j++) {
parent->keys[j] = parent->keys[j+1];
}
for(int j = i+1; j < parent->n; j++) {
parent->child[j] = parent->child[j+1];
}
parent->n--;
free(right);
}
void fix(struct node *parent,int i) {
if(i > 0 && parent->child[i-1]->n > MIN_KEYS) {
borrowFromLeft(parent,i);
} else if(i < parent->n && parent->child[i+1]->n > MIN_KEYS) {
borrowFromRight(parent,i);
} else {
if(i > 0) {
merge(parent,i-1);
} else {
merge(parent,i);
}
}
}
void deleteKey(struct node *nd,int data) {
if(nd->leaf) {
removeFromLeaf(nd,data);
return;
}
int i = findIndex(nd,data);
int sepIndex = -1;
for(int j = 0; j < nd->n; j++) {
if(nd->keys[j] == data) {
sepIndex = j;
break;
}
}
deleteKey(nd->child[i],data);
if(sepIndex != -1) {
nd->keys[sepIndex] = getMin(nd->child[sepIndex+1]);
}
if(nd->child[i]->n < MIN_KEYS) {
fix(nd,i);
}
}
void delete(int data) {
if(root == 0) {
printf("Tree is empty");
return;
}
deleteKey(root,data);
if(!root->leaf && root->n == 0) {
struct node *old = root;
root = root->child[0];
free(old);
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
int choice;
printf("Do u want to delete(0 or 1): ");
scanf("%d", &choice);
while(choice) {
int val;
printf("Enter the element to be deleted: ");
scanf("%d", &val);
delete(val);
printf("Delete another?(0 or 1): ");
scanf("%d", &choice);
}
if(choice == 0) {
printf("Tree structure after deletion: ");
printTree(root,0);
printf("\n");
printLeaves();
printf("\n");
}
return 0;
}
