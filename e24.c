#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
int height;
struct node *left;
struct node *right;
};
int height(struct node *n);
void updateHeight(struct node *n);
struct node *newnode(int data);
int bf(struct node *n);
struct node *leftRotate(struct node *z);
struct node *rightRotate(struct node *z);
struct node *leftRightRotate(struct node *z);
struct node *rightLeftRotate(struct node *z);
struct node *insert(struct node *root,int data);
struct node *inorderPredecessor(struct node *root);
struct node *delete(struct node *root,int data);
void inorder(struct node *root);
int main() {
int n;
printf("Enter no.of elements: ");
scanf("%d", &n);
int arr[n];
struct node *root = 0;
for(int i = 0; i < n; i++) {
printf("element[%d]: ",i);
scanf("%d", &arr[i]);
root = insert(root,arr[i]);
}
printf("\nAVL Tree constructed\n");
printf("Inorder: ");
inorder(root);
printf("\n");
int choice;
printf("Do u want to delete(0 or 1): ");
scanf("%d", &choice);
while(choice) {
int val;
printf("Enter the element to be deleted: ");
scanf("%d", &val);
root = delete(root,val);
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
int height(struct node *n) {
if(n == 0) {
return -1;
}
return n->height;
}
void updateHeight(struct node *n) {
int lh = height(n->left);
int rh = height(n->right);
n->height = 1 + (lh > rh ? lh : rh);
}
struct node *newnode(int data) {
struct node *Node = (struct node*)malloc(sizeof(struct node));
Node->data = data;
Node->left = 0;
Node->right = 0;
Node->height = 0;
return Node;
}
int bf(struct node *n) {
return height(n->left)-height(n->right);
}
struct node *leftRotate(struct node *z) {
struct node *y = z->right;
z->right = y->left;
y->left = z;
updateHeight(z);
updateHeight(y);
return y;
}
struct node *rightRotate(struct node *z) {
struct node *y = z->left;
z->left = y->right;
y->right = z;
updateHeight(z);
updateHeight(y);
return y;
}
struct node *leftRightRotate(struct node *z) {
z->left = leftRotate(z->left);
return rightRotate(z);
}
struct node *rightLeftRotate(struct node *z) {
z->right = rightRotate(z->right);
return leftRotate(z);
}
struct node *insert(struct node *root,int data) {
if(root == 0) {
return newnode(data);
}
if(data < root->data) {
root->left = insert(root->left,data);
} else if(data > root->data) {
root->right = insert(root->right,data);
} else {
return root;
}
updateHeight(root);
int b = bf(root);
if(b == 2 && data < root->left->data) {
return rightRotate(root);
}
if(b == -2 && data > root->right->data) {
return leftRotate(root);
}
if(b == 2 && data > root->left->data) {
return leftRightRotate(root);
}
if(b == -2 && data < root->right->data) {
return rightLeftRotate(root);
}
return root;
}
struct node *inorderPredecessor(struct node *root) {
root = root->left;
while(root->right != 0) {
root = root->right;
}
return root;
}
struct node *delete(struct node *root,int data) {
if(root == 0) {
printf("element not found");
}
if(data < root->data) {
root->left = delete(root->left,data);
} else if(data > root->data) {
root->right = delete(root->right,data);
} else {
if(root->left == 0 && root->right == 0) {
free(root);
return 0;
} else if(root->left == 0 && root->right != 0) {
struct node *temp = root->right;
free(root);
return temp;
} else if(root->right == 0 && root->left != 0) {
struct node *temp = root->left;
free(root);
return temp;
} else {
struct node *pred = inorderPredecessor(root);
root->data = pred->data;
root->left = delete(root->left,pred->data);
}
}
updateHeight(root);
int b = bf(root);
if(b == 2 && data < root->left->data) {
return rightRotate(root);
}
if(b == -2 && data > root->right->data) {
return leftRotate(root);
}
if(b == 2 && data > root->left->data) {
return leftRightRotate(root);
}
if(b == -2 && data < root->right->data) {
return rightLeftRotate(root);
}
return root;
}
void inorder(struct node *root) {
if(root == 0) {
return;
}
inorder(root->left);
printf("%d ",root->data);
inorder(root->right);
}
