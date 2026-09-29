#include <stdio.h>
#include <string.h>
char stack[50];
int top = -1;
void push(char x);
char pop();
int precedence(char c);
int isOperator(char c);
int isRighAssociative(char c);
int shouldPop(char stackTop,char incoming);
void reverse(char str[]);
void infixToPrefix(char exp[]);
int main() {
char exp[50];
printf("Enter infix: ");
scanf("%s", exp);
infixToPrefix(exp);
return 0;
}
void push(char x) {
top++;
stack[top] = x;
}
char pop() {
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
if(c == '^' || c == '+' || c == '-' || c == '*' || c == '%' || c == '/') {
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
} else if(precedence(stackTop) == precedence(incoming) && isRightAssociative(incoming)) {
return 1;
} else {
return 0;
}
}
void reverse(char str[]) {
int n = strlen(str);
for(int i = 0; i < n/2; i++) {
char t = str[i];
str[i] = str[n-1-i];
str[n-1-i] = t;
}
}
void infixToPrefix(char exp[]) {
char result[50];
int k = 0;
reverse(exp);
for(int i = 0; exp[i] != '\0'; i++) {
char c = exp[i];
if(c >= 'a' && c <= 'z') {
result[k] = c;
k++;
} else if(c == ')') {
push(c);
} else if(c == '(') {
while(top != -1 && stack[top] != ')') {
result[k] = pop();
k++;
}
pop();
} else if(isOperator(c)) {
while(top != -1 && stack[top] != ')' && shouldPop(stack[top],c)) {
result[k] - pop();
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
reverse(result);
printf("Prefix: %s",result);
}
