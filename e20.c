#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *left;
struct node *right;
};
struct node *newnode(int data);
int findIndex(int inorder[],int start,int end,int value);
struct node *buildTree(int postorder[],int inorder[],int inStart,int inEnd,int *postIndex);
void printPostorder(struct node *root);
void printInorder(struct node *root);
int main() {
int n;
printf("Enter no.of elements: ");
scanf("%d", &n);
int postorder[n],inorder[n];
printf("Enter postorder: ");
for(int i = 0; i < n; i++) {
printf("element[%d]: ",i);
scanf("%d", &postorder[i]);
inorder[i] = postorder[i];
}
for(int i = 0; i < n-1; i++) {
for(int j = i+1; j < n; j++) {
if(inorder[i] > inorder[j]) {
int temp = inorder[i];
inorder[i] = inorder[j];
inorder[j] = temp;
}
}
}
printf("Inorder is: ");
for(int i = 0; i < n; i++) {
printf("%d ",inorder[i]);
}
int postindex  = n-1;
struct node *root = buildTree(postorder,inorder,0,n-1,&postindex);
printf("\nTree built successfully\n");
printf("Verification:\n");
printf("Postorder: ");
printPostorder(root);
printf("\n");
printf("Inorder: ");
printInorder(root);
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
int findIndex(int inorder[],int start,int end,int value) {
for(int i = start; i <= end; i++) {
if(inorder[i] == value) {
return i;
}
}
return -1;
}
struct node *buildTree(int postorder[],int inorder[],int inStart,int inEnd,int *postIndex) {
if(inStart > inEnd) {
return 0;
}
int rootVal = postorder[*postIndex];
(*postIndex)--;
struct node *root = newnode(rootVal);
if(inStart == inEnd) {
return root;
}
int inIndex = findIndex(inorder,inStart,inEnd,rootVal);
root->right = buildTree(postorder,inorder,inIndex+1,inEnd,postIndex);
root->left = buildTree(postorder,inorder,inStart,inIndex-1,postIndex);
return root;
}
void printPostorder(struct node *root) {
if(root == 0) {
return;
}
printPostorder(root->left);
printPostorder(root->right);
printf("%d ",root->data);
}
void printInorder(struct node *root) {
if(root == 0) {
return;
}
printInorder(root->left);
printf("%d ",root->data);
printInorder(root->right);
}
