#include <stdio.h>
#include <stdlib.h>
struct node {
int val;
struct node *left;
struct node *right;
};
char charStack[50];
int charTop = -1;
struct node *nodeStack[50];
int nodeTop = -1;
void charPush(char c);
char charPop();
void nodePush(struct node *newNode);
struct node *nodePop();
int precedence(char c);
int isOperator(char c);
int isRightAssociative(char c);
int shouldPop(char stackTop,char incoming);
void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);
struct node *buildTree(char result[]);
void infixToPostfix(char exp[]);
int main() {
char exp[50];
printf("Enter infix: ");
scanf("%s",exp);
infixToPostfix(exp);
return 0;
}
void charPush(char c) {
charTop++;
charStack[charTop] = c;
}
char charPop() {
char item = charStack[charTop];
charTop--;
return item;
}
void nodePush(struct node *newNode) {
nodeTop++;
nodeStack[nodeTop] = newNode;
}
struct node *nodePop() {
struct node *item = nodeStack[nodeTop];
nodeTop--;
return item;
}
int precedence(char c) {
if(c == '^') {
return 3;
} else if(c == '*' || c == '%' || c == '/') {
return 2;
} else if(c == '+' || c == '-') {
return 1;
} else {
return 0;
}
}
int isOperator(char c) {
if(c == '*' || c == '^' || c == '%' || c == '/' || c == '+' || c == '-') {
return 1;
} else {
return 0;
}
}
int isRightAssociative(char c) {
if(c == '^') {
return 1;
} else {
return 0;
}
}
int shouldPop(char stackTop,char incoming) {
if(precedence(stackTop) > precedence(incoming)) {
return 1;
} else if(precedence(stackTop) == precedence(incoming) && !isRightAssociative(incoming)) {
return 1;
} else {
return 0;
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
struct node *buildTree(char result[]) {
for(int i = 0; result[i] != '\0'; i++) {
char c = result[i];
if(!isOperator(c)) {
struct node *newNode = (struct node*)malloc(sizeof(struct node));
newNode->val = c;
newNode->left = 0;
newNode->right = 0;
nodePush(newNode);
} else {
struct node *newNode = (struct node*)malloc(sizeof(struct node));
newNode->val = c;
newNode->right = nodePop();
newNode->left = nodePop();
nodePush(newNode);
}
}
return nodePop();
}
void infixToPostfix(char exp[]) {
char result[50];
int k = 0;
for(int i = 0; exp[i] != '\0'; i++) {
char c = exp[i];
if(c >= 'a' && c <= 'z') {
result[k] = c;
k++;
} else {
while(charTop != -1 && shouldPop(charStack[charTop],c)) {
result[k] = c;
k++;
}
charPush(c);
}
}
while(charTop != -1) {
result[k] = charPop();
k++;
}
result[k] = '\0';
printf("postfix: %s\n",result);
struct node *root = buildTree(result);
printf("inorder: ");
inorder(root);
printf("\n");
printf("preorder: ");
preorder(root);
printf("\n");
printf("postorder: ");
postorder(root);
printf("\n");
}
