#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *left;
struct node *right;
};
struct node *create();
void preorder(struct node *root);
void inorder(struct node *root);
void postorder(struct node *root);
int main() {
struct node *root;
root = 0;
root = create();
printf("Preorder: ");
preorder(root);
printf("\n");
printf("Inorder: ");
inorder(root);
printf("\n");
printf("Postorder: ");
postorder(root);
printf("\n");
return 0;
}
struct node *create() {
int x;
struct node *newNode;
newNode = (struct node*)malloc(sizeof(struct node));
printf("Enter data(-1 for no node): ");
scanf("%d", &x);
if(x == -1) {
return 0;
}
newNode->data = x;
printf("Enter left child of %d: ",x);
newNode->left = create();
printf("Enter right child of %d: ",x);
newNode->right = create();
return newNode;
}
void preorder(struct node *root) {
if(root == 0) {
return;
}
printf("%d ",root->data);
preorder(root->left);
preorder(root->right);
}
void inorder(struct node *root) {
if(root == 0) {
return;
}
inorder(root->left);
printf("%d ",root->data);
inorder(root->right);
}
void postorder(struct node *root) {
if(root == 0) {
return;
}
postorder(root->left);
postorder(root->right);
printf("%d ",root->data);
}
