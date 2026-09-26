#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
int val;
struct node *left;
struct node *right;
};
int precedence(char op);
struct node *buildTree(char exp[],int start,int end);
void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);
int main() {
char exp[50];
printf("Enter infix: ");
gets(exp);
int l = strlen(exp);
struct node *root = buildTree(exp,0,l-1);
printf("Infix: ");
inorder(root);
printf("\n");
printf("prefix: ");
preorder(root);
printf("\n");
printf("postfix: ");
postorder(root);
printf("\n");
return 0;
}
int precedence(char op) {
if(op == '^') {
return 3;
} else if(op == '*' || op == '%' || op == '/') {
return 2;
} else if(op == '+' || op == '-') {
return 1;
} else {
return 0;
}
}
struct node *buildTree(char exp[],int start,int end) {
while(start <= end && exp[start] == ' ') {
start++;
}
while(start <= end && exp[end] == ' ') {
end--;
}
if(start == end) {
struct node *newnode = (struct node*)malloc(sizeof(struct node));
newnode->val = exp[start];
newnode->left = 0;
newnode->right = 0;
return newnode;
} else {
int shiftPos = -1;
int lowestPrec = 99;
for(int i = start; i <= end; i++) {
int p = precedence(exp[i]);
if(p != 0 && p < lowestPrec) {
lowestPrec = p;
shiftPos = i;
}
}
struct node *newnode = (struct node*)malloc(sizeof(struct node));
newnode->val = exp[shiftPos];
newnode->left = buildTree(exp,start,shiftPos-1);
newnode->right = buildTree(exp,shiftPos+1,end);
return newnode;
}
}
void inorder(struct node *root) {
if(root == 0) {
return;
} 
inorder(root->left);
printf("%c",root->val);
inorder(root->right);
}
void preorder(struct node *root) {
if(root == 0) {
return;
}
printf("%c",root->val);
preorder(root->left);
preorder(root->right);
}
void postorder(struct node *root) {
if(root == 0) {
return;
}
postorder(root->left);
postorder(root->right);
printf("%c",root->val);
}
