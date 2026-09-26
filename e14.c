#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *left;
struct node *right;
};
struct node *newnode(int data);
struct node *insert(struct node *root,int data);
void inorder(struct node *root);
int main() {
int n;
printf("Enter no.of elements: ");
scanf("%d", &n);
struct node *root = 0;
for(int i = 0; i < n; i++) {
int val;
printf("Enter element[%d]: ",i);
scanf("%d", &val);
root = insert(root,val);
}
printf("\nBST built successfully\n");
printf("Verification:\n");
printf("inorder: ");
inorder(root);
printf("\n");
return 0;
}
struct node *newnode(int data) {
struct node *Node = (struct node*)malloc(sizeof(struct node));
Node->data = data;
Node->left = 0;
Node->right = 0;
};
struct node *insert(struct node *root,int data) {
if(root == 0) {
return newnode(data);
}
if(data < root->data) {
root->left = insert(root->left,data);
} else if(data > root->data) {
root->right = insert(root->right,data);
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
