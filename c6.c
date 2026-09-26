#include <stdio.h>
int n;
int top = -1;
int stack[10];
void push();
void pop();
void peek();
void display();
int main() {
printf("Enter size: ");
scanf("%d", &n);
int ch;
do {
printf("Enter choice(1-push,2-pop,3-peek,4-display): ");
scanf("%d", &ch);
switch(ch) {
case 1: push();
break;
case 2: pop();
break;
case 3: peek();
break;
case 4: display();
break;
default: printf("invalid input");
} 
} while(ch != 0);
return 0;
}
void push() {
int x;
printf("Enter data: ");
scanf("%d", &x);
if(top == n-1) {
printf("overflow");
} else {
top++;
stack[top] = x;
}
}
void pop() {
int item;
if(top == -1) {
printf("underflow");
} else {
item = stack[top];
top--;
}
printf("popped out element is %d\n",item);
}
void peek() {
if(top == -1) {
printf("stack is empty");
} else {
printf("topmost element is %d\n",stack[top]);
}
}
void display() {
for(int i = top; i >= 0; i--) {
printf("%d ",stack[i]);
}
}
