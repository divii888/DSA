#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *left;
struct node *right;
};
struct node *newnode(int data);
int findIndex(int post[],int n,int value);
struct node *buildTree(int pre[],int post[],int n);
void preorder(struct node *root);
void postorder(struct node *root);
int main() {
int n;
printf("Enter no.of nodes: ");
scanf("%d", &n);
int pre[n],post[n];
printf("Enter preorder: ");
for(int i = 0; i < n; i++) {
printf("pre[%d]: ",i);
scanf("%d", &pre[i]);
}
printf("Enter postorder: ");
for(int i = 0; i < n; i++) {
printf("post[%d]: ",i);
scanf("%d", &post[i]);
}
struct node *root = buildTree(pre,post,n);
printf("\nTree built successfully\n");
printf("verification:\n");
printf("preorder: ");
preorder(root);
printf("\n");
printf("postorder: ");
postorder(root);
printf("\n");
return 0;
};
struct node *newnode(int data) {
struct node *Node = (struct node*)malloc(sizeof(struct node));
Node->data = data;
Node->left = 0;
Node->right = 0;
return Node;
}
int findIndex(int post[],int n,int value) {
for(int i = 0; i < n; i++) {
if(post[i] == value) {
return i;
}
}
return -1;
}
struct node *buildTree(int pre[],int post[],int n) {
struct node *root = newnode(pre[0]);
struct node *stack[n];
int top = -1;
top++;
stack[top] = root;
top++;
for(int i = 1; i < n; i++) {
struct node *newNode = newnode(pre[i]);
int newIndex = findIndex(post,n,pre[i]);
int parentIndex = findIndex(post,n,stack[top-1]->data);
if(newIndex < parentIndex) {
if(stack[top-1]->left == 0) {
stack[top-1]->left = newNode;
} else {
stack[top-1]->right = newNode;
}
} else {
while(top > 0 && newIndex > findIndex(post,n,stack[top-1]->data)) {
top--;
}
if(stack[top-1]->left == 0) {
stack[top-1]->left = newNode;
} else {
stack[top-1]->right = newNode;
}
}
stack[top] = newNode;
top++;
}
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
