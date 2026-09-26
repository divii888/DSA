#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *left;
struct node *right;
};
struct node *newnode(int data);
struct node *insert(struct node *root,int data);
struct node *inorderPredecessor(struct node *root);
struct node *inorderSuccessor(struct node *root);
struct node *delete(struct node *root,int data);
void inorder(struct node *root);
int main() {
int n;
printf("Enter the no.of elements: ");
scanf("%d", &n);
struct node *root = 0;
for(int i = 0; i < n; i++) {
int val;
printf("element[%d]: ",i);
scanf("%d", &val);
root = insert(root,val);
}
printf("\nBST constructed\n");
printf("Inorder: ");
inorder(root);
printf("\n");
int choice;
printf("Do u want to delete(0 or 1): ");
scanf("%d", &choice);
while(choice) {
int val;
printf("Enter element to be deleted: ");
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
struct node *newnode(int data) {
struct node *Node = (struct node*)malloc(sizeof(struct node));
Node->data = data;
Node->left = 0;
Node->right = 0;
return Node;
}
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
struct node *inorderPredecessor(struct node *root) {
root = root->left;
while(root->right != 0) {
root = root->right;
}
return root;
}
struct node *inorderSuccesor(struct node *root) {
root = root->right;
while(root->left != 0) {
root = root->left;
}
return root;
}
struct node *delete(struct node *root,int data) {
if(root == 0) {
printf("Element not found\n");
return 0;
} else if(data < root->data) {
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
