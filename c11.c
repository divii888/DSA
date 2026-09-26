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
scanf("%d", &val[i]);
}
int n;
printf("Enter no.of tokens: ");
scanf("%d", &n);
char token[n];
for(int i = 0; i < n; i++) {
printf("Enter token: ");
getchar();
scanf("%c", &token[i]);
}
for(int i = n-1; i >= 0; i--) {
if(token[i] >= 'a' && token[i] <= 'z') {
push(val[token[i]-'a']);
} else {
int op1 = pop();
int op2 = pop();
if(token[i] == '+') {
push(op1+op2);
} else if(token[i] == '-') {
push(op1-op2);
} else if(token[i] == '*') {
push(op1*op2);
} else if(token[i] == '/') {
push(op1/op2);
} else if(token[i] == '^') {
push(pow(op1,op2));
} 
}
}
printf("result is %d",stack[top]);
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
