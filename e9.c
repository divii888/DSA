#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *left;
struct node *right;
};
struct node *newnode(int data);
int findIndex(int post[],int start,int end,int value);
struct node *buildTree(int pre[],int post[],int preStart,int preEnd,int postStart,int postEnd);
void preorder(struct node *root);
void postorder(struct node *root);
int main() {
int n;
printf("Enter no.of nodes: ");
scanf("%d", &n);
int pre[n],post[n];
printf("Enter preorder: ");
for(int i = 0; i < n; i++) {
printf("Enter preorder[%d]: ",i);
scanf("%d", &pre[i]);
}
printf("Enter postrder: ");
for(int i = 0; i < n; i++) {
printf("Enter postorder[%d]: ",i);
scanf("%d", &post[i]);
}
struct node *root = buildTree(pre,post,0,n-1,0,n-1);
printf("\nTree built successfully\n");
printf("Verification:\n");
printf("Preorder: ");
preorder(root);
printf("\n");
printf("Postorder: ");
postorder(root);
printf("\n");
return 0;
}
struct node *newnode(int data) {
struct node *Node = (struct node*)malloc(sizeof(struct node));
Node->data = data;
Node->left = 0;
Node->right = 0;
return Node;
}
int findIndex(int post[],int start,int end,int value) {
for(int i = start; i <= end; i++) {
if(post[i] == value) {
return i;
}
}
return -1;
}
struct node *buildTree(int pre[],int post[],int preStart,int preEnd,int postStart,int postEnd) {
if((preStart > preEnd) || (postStart > postEnd)) {
return 0;
}
struct node *root = newnode(pre[preStart]);
if(preStart == preEnd) {
return root;
}
int leftRootVal = pre[preStart+1];
int leftRootPostIndex = findIndex(post,postStart,postEnd-1,leftRootVal);
int leftSize = leftRootPostIndex - postStart + 1;
root->left = buildTree(pre,post,preStart+1,preStart+leftSize,postStart,leftRootPostIndex);
root->right = buildTree(pre,post,preStart+leftSize+1,preEnd,leftRootPostIndex+1,postEnd);
return root;
}
void preorder(struct node *root) {
if(root == 0) {
return;
}
printf("%d ",root->data);
preorder(root->left);
preorder(root->right);
}
void postorder(struct node *root) {
if(root == 0) {
return;
}
postorder(root->left);
postorder(root->right);
printf("%d ",root->data);
}
