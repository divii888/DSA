#include <stdio.h>
#include <math.h>
int stack[50];
int top = -1;
void push(int x);
int pop();
int main() {
int m;
printf("Enter no.of operands: ");
scanf("%d", &m);
int val[m];
for(int i = 0; i < m; i++) {
printf("Enter %c: ",'a'+i);
getchar();
scanf("%d", &val[i]);
}
int n;
printf("Enter no.of tokens: ");
scanf("%d", &n);
char token;
for(int i = 0; i < n; i++) {
getchar();
printf("Enter token: ");
scanf("%c", &token);
if(token >= 'a' && token <= 'z') {
push(val[token-'a']);
} else {
int op2 = pop();
int op1 = pop();
if(token == '+') {
push(op1+op2);
} else if(token == '-') {
push(op1-op2);
} else if(token == '*') {
push(op1*op2);
} else if(token == '/') {
push(op1/op2);
} else if(token == '^') {
push(pow(op1,op2));
}
}
}
printf("result is %d\n",stack[top]);
return 0;
}
void push(int x) {
top++;
stack[top] = x;
}
int pop() {
int item = stack[top];
top--;
return item;
}
