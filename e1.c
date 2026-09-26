#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *left;
struct node *right;
};
struct node *create();
void inorder(struct node *root);
int main() {
struct node *root;
root = 0;
root = create();
printf("Inorder: ");
inorder(root);
return 0;
}
struct node *create() {
int x;
struct node *newNode;
newNode = (struct node*)malloc(sizeof(struct node));
printf("Enter data: ");
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
void inorder(struct node *root) {
if(root == 0) {
return;
}
inorder(root->left);
printf("%d ",root->data);
inorder(root->right);
}
