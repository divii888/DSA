#include <stdio.h>
#include <stdlib.h>
#define RED 1
#define BLACK 0
struct node {
int data;
int colour;
struct node *left;
struct node *right;
struct node *parent;
};
struct node *root = 0;
struct node *newnode(int data) {
struct node *n = (struct node*)malloc(sizeof(struct node));
n->data = data;
n->colour = RED;
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
}else if(z == z->parent->left) {
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
void fixInsert(struct node *n) {
while(n != root && n->parent->colour == RED) {
struct node *parent = n->parent;
struct node *grandpa = parent->parent;
if(parent == grandpa->left) {
struct node *uncle = grandpa->right;
if(uncle != 0 && uncle->colour == RED) {
parent->colour = BLACK;
uncle->colour = BLACK;
grandpa->colour = RED;
n = grandpa;
} else {
if(n == parent->right) {
n = parent;
leftRotate(n);
parent = n->parent;
grandpa = parent->parent;
}
parent->colour = BLACK;
grandpa->colour = RED;
rightRotate(grandpa);
}
} else {
struct node *uncle = grandpa->left;
if(uncle != 0 && uncle->colour == RED) {
parent->colour = BLACK;
uncle->colour = BLACK;
grandpa->colour = RED;
n = grandpa;
} else {
if(n == parent->left) {
n = parent;
rightRotate(n);
parent = n->parent;
grandpa = parent->parent;
}
parent->colour = BLACK;
grandpa->colour = RED;
leftRotate(grandpa);
}
}
}root->colour = BLACK;
}
void insert(int data) {
struct node *n = newnode(data);
if(root == 0) {
n->colour = BLACK;
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
return;
}
}
n->parent = parent;
if(data < parent->data) {
parent->left = n;
} else {
parent->right = n;
}
fixInsert(n);
}
void inorder(struct node *root) {
if(root == 0) {
return;
}
inorder(root->left);
printf("%d(%s) ",root->data,root->colour == RED ? "R" : "B");
inorder(root->right);
}
int getColour(struct node *n) {
if(n == 0) {
return BLACK;
}
return n->colour;
}
void fixDelete(struct node *n,struct node *parent) {
while(n != root && getColour(n) == BLACK) {
if(n == parent->left) {
struct node *sibling = parent->right;
if(getColour(sibling) == RED) {
sibling->colour = BLACK;
parent->colour = RED;
leftRotate(parent);
sibling = parent->right;
}
if(getColour(sibling->right) == BLACK && getColour(sibling->left) == BLACK) {
sibling->colour = RED;
if(parent->colour == RED) {
parent->colour = BLACK;
break;
} else {
n = parent;
parent = n->parent;
}
} else {
if(getColour(sibling->right) == BLACK) {
if(sibling->left != 0) {
sibling->left->colour = BLACK;
}
sibling->colour = RED;
rightRotate(sibling);
sibling = parent->right;
}
sibling->colour = parent->colour;
parent->colour = BLACK;
if(sibling->right != 0) {
sibling->right->colour = BLACK;
}
leftRotate(parent);
break;
}
} else {
struct node *sibling = parent->left;
if(getColour(sibling) == RED) {
sibling->colour = BLACK;
parent->colour = RED;
rightRotate(parent);
sibling = parent->left;
}
if(getColour(sibling->left) == BLACK && getColour(sibling->right) == BLACK) {
sibling->colour = RED;
if(parent->colour == RED) {
parent->colour = BLACK;
break;
} else {
n = parent;
parent = n->parent;
}
} else {
if(getColour(sibling->left) == BLACK) {
if(sibling->right != 0) {
sibling->right->colour = BLACK;
}
sibling->colour = RED;
leftRotate(sibling);
sibling = parent->left;
} 
sibling->colour = parent->colour;
parent->colour = BLACK;
rightRotate(parent);
break;
}
}
}
if(n != 0) {
n->colour = BLACK;
}
}
struct node *inorderSuccessor(struct node *root) {
root = root->right;
while(root->left != 0) {
root = root->left;
}
return root;
}
void delete(int data) {
struct node *curr = root;
while(curr != 0) {
if(data < curr->data) {
curr = curr->left;
} else if(data > curr->data) {
curr = curr->right;
} else {
break;
}
}
if(curr->left != 0 && curr->right != 0) {
struct node *succ = inorderSuccessor(curr);
curr->data = succ->data;
curr = succ;
}
struct node *child = curr->left != 0 ? curr->left : curr->right;
struct node *parent = curr->parent;
if(child != 0) {
child->parent = parent;
}
if(curr == parent->left) {
parent->left = child;
} else {
parent->right = child;
}
if(curr->colour == RED) {
free(curr);
return;
}
free(curr);
if(child != 0 && child->colour == RED) {
child->colour = BLACK;
return;
}
fixDelete(child,parent);
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
printf("\n RB Tree constructed\n");
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
printf("inorder after deletion: ");
inorder(root);
printf("\n");
}
return 0;
}
