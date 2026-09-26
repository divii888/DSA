#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *left;
struct node *right;
struct node *parent;
};
struct node *root = 0;
struct node *newnode(int data) {
struct node *n = (struct node*)malloc(sizeof(struct node));
n->data = data;
n->left = 0;
n->right = 0;
n->parent = 0;
return n;
}
void leftRotate(struct node *z) {
struct node *y = z->right;
z->right = y->left;
if(y->left != 0) {
y->left->parent = z;
}
y->parent = z->parent;
if(z->parent == 0) {
root = y;
} else if(z == z->parent->left) {
z->parent->left = y;
} else {
z->parent->right = y;
}
y->left = z;
z->parent = y;
}
void rightRotate(struct node *z) {
struct node *y = z->left;
z->left = y->right;
if(y->right != 0) {
y->right->parent = z;
}
y->parent = z->parent;
if(z->parent == 0) {
root = y;
} else if(z == z->parent->right) {
z->parent->right = y;
} else {
z->parent->left = y;
}
y->right = z;
z->parent = y;
}
void splay(struct node *n) {
while(n->parent != 0) {
if(n->parent == root) {
if(n == n->parent->left) {
rightRotate(n->parent);
} else {
leftRotate(n->parent);
} 
} else {
struct node *p = n->parent;
struct node *g = p->parent;
if(n == n->parent->left && p == p->parent->left) {
rightRotate(g);
rightRotate(p);
} else if(n == n->parent->right && p == p->parent->right) {
leftRotate(g);
leftRotate(p);
} else if(n == n->parent->left && p == p->parent->right) {
rightRotate(p);
leftRotate(g);
} else {
leftRotate(p);
rightRotate(g);
}
}
}
}
void insert(int data) {
struct node *n = newnode(data);
if(root == 0) {
root = n;
return;
}
struct node *curr = root;
struct node *parent = 0;
while(curr != 0) {
parent = curr;
if(data < curr->data) {
curr = curr->left;
} else if(data > curr->data) {
curr = curr->right;
} else {
break;
}
}
n->parent = parent;
if(data < parent->data) {
parent->left = n;
} else {
parent->right = n;
}
splay(n);
}
void inorder(struct node *root) {
if(root == 0) {
return;
}
inorder(root->left);
printf("%d ",root->data);
inorder(root->right);
}
struct node *findMax(struct node *n) {
while(n->right != 0) {
n = n->right;
}
return n;
}
void delete(int data) {
if(root == 0) {
return;
}
struct node *curr = root;
struct node *last = 0;
while(curr != 0) {
last = curr;
if(data < curr->data) {
curr = curr->left;
} else if(data > curr->data) {
curr = curr->right;
} else {
break;
}
}
if(curr == 0) {
printf("Element not found");
splay(last);
return;
}
splay(curr);
struct node *temp = root;
if(root->left == 0) {
root = root->right;
if(root != 0) {
root->parent = 0;
}
} else {
struct node *leftSubtree = root->left;
struct node *rightSubtree = root->right;
leftSubtree->parent = 0;
if(rightSubtree != 0) {
rightSubtree->parent = 0;
}
root = leftSubtree;
struct node *maxNode = findMax(leftSubtree);
splay(maxNode);
root->right = rightSubtree;
if(rightSubtree != 0) {
rightSubtree->parent = root;
}
free(temp);
}
}
int main() {
int n;
printf("Enter no.of node: ");
scanf("%d", &n);
int arr[n];
for(int i = 0; i < n; i++) {
printf("element[%d]: ",i);
scanf("%d", &arr[i]);
insert(arr[i]);
}
printf("\nSplay tree constructed\n");
printf("inorder: ");
inorder(root);
printf("\n");
int choice;
printf("Do u want to delete(0 or 1): ");
scanf("%d", &choice);
while(choice) {
int val;
printf("Enter element to be deleted: ");
scanf("%d", &val);
delete(val);
printf("Delete another?(0 or 1): ");
scanf("%d", &choice);
}
if(choice == 0) {
printf("Inorder after deletion: ");
inorder(root);
printf("\n");
}
return 0;
}
