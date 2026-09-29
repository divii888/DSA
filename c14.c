#include <stdio.h>
char stack[50];
int top = -1;
void push(char x);
int pop();
int precedence(char c);
int isOperator(char c);
int isRightAssociative(char c);
int shouldPop(char stackTop,char incoming);
void infixToPostfix(char exp[]);
int main() {
char exp[50];
printf("Enter infix: ");
scanf("%s", exp);
infixToPostfix(exp);
return 0;
}
void push(char x) {
top++;
stack[top] = x;
}
int pop() {
char item = stack[top];
top--;
return item;
}
int precedence(char c) {
if(c == '^') {
return 3;
} else if(c == '%' || c == '*' || c == '/') {
return 2;
} else if(c == '+' || c == '-') {
return 1;
} else {
return 0;
}
}
int isOperator(char c) {
if(c == '^' || c == '%' || c == '*' || c == '/' || c == '+' || c == '-') {
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
} else if(precedence(stackTop) == precedence(incoming) && !isRightAssociative) {
return 1;
} else {
return 0;
}
}
void infixToPostfix(char exp[]) {
char result[50];
int k = 0;
for(int i = 0; exp[i] != '\0'; i++) {
char c = exp[i];
if(c >= 'a' && c <= 'z') {
result[k] = c;
k++;
} else if(c == '(') {
push(c);
} else if(c == ')') {
while(top != -1 && stack[top] != '(') {
result[k] = pop();
k++;
}
} else if(isOperator(c)) {
while(top != -1 && stack[top] != '(' && shouldPop(stack[top],c)) {
result[k] = pop();
k++;
}
push(c);
}
}
while(top != -1) {
result[k] = pop();
k++;
}
result[k] = '\0';
printf("posfix: %s",result);
}
