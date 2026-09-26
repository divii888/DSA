#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *left;
struct node *right;
};
struct node *newnode(int data);
int findIndex(int inorder[],int start,int end,int value);
struct node *buildTree(int preorder[],int inorder[],int inStart,int inEnd,int *preIndex);
void printPreorder(struct node *root);
void printInorder(struct node *root);
int main() {
int n;
printf("Enter no.of nodes: ");
scanf("%d", &n);
int preorder[n],inorder[n];
printf("Enter preorder: ");
for(int i = 0; i < n; i++) {
printf("Enter preorder[%d]: ",i);
scanf("%d", &preorder[i]);
}
printf("Enter inorder: ");
for(int i = 0; i < n; i++) {
printf("Enter inorder[%d]; ",i);
scanf("%d", &inorder[i]);
}
int preindex = 0;
struct node *root = buildTree(preorder,inorder,0,n-1,&preindex);
printf("\nTree built successfully\n");
printf("Verification:\n");
printf("Preorder: ");
printPreorder(root);
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
struct node *buildTree(int preorder[],int inorder[],int inStart,int inEnd,int *preIndex) {
if(inStart > inEnd) {
return 0;
}
int rootVal = preorder[*preIndex];
(*preIndex)++;
struct node *root = newnode(rootVal);
if(inStart == inEnd) {
return root;
}
int inIndex = findIndex(inorder,inStart,inEnd,rootVal);
root->left = buildTree(preorder,inorder,inStart,inIndex-1,preIndex);
root->right = buildTree(preorder,inorder,inIndex+1,inEnd,preIndex);
return root;
}
void printPreorder(struct node *root) {
if(root == 0) {
return;
}
printf("%d ",root->data);
printPreorder(root->left);
printPreorder(root->right);
}
void printInorder(struct node *root) {
if(root == 0) {
return;
}
printInorder(root->left);
printf("%d ",root->data);
printInorder(root->right);
}
