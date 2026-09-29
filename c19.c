#include <stdio.h>
#include <string.h>
char stack[50][50];
int top = -1;
void push(char x[]);
void pop(char x[]);
int isOperator(char c);
void postfixToInfix(char exp[]);
int main() {
char exp[50];
printf("Enter postfix: ");
scanf("%s", exp);
postfixToInfix(exp);
return 0;
}
void push(char x[]) {
top++;
strcpy(stack[top],x);
}
void pop(char x[]) {
strcpy(x,stack[top]);
top--;
}
int isOperator(char c) {
if(c == '^' || c == '%' || c == '*'|| c == '/' || c == '+' || c == '-') {
return 1;
} else {
return 0;
}
}
void postfixToInfix(char exp[]) {
char op1[50],op2[50],temp[50];
for(int i = 0; exp[i] != '\0'; i++) {
char c = exp[i];
if(!isOperator(c)) {
char s[2] = {c,'\0'};
push(s);
} else {
pop(op2);
pop(op1);
char op[2] = {c,'\0'};
strcpy(temp,"(");
strcat(temp,op1);
strcat(temp,op);
strcat(temp,op2);
strcat(temp,")");
push(temp);
}
}
printf("infix: %s\n",stack[top]);
}
