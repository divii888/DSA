#include <stdio.h>
#define n 5
int s1[n],s2[n];
int top1 = -1,top2 = -1;
int count = 0;
void push1(int x);
int pop1();
void push2(int x);
int pop2();
void enqueue(int x);
void dequeue();
void display();
int main() {
for(int i = 0; i < n; i++) {
int x;
printf("Enter data: ");
scanf("%d", &x);
enqueue(x);
}
printf("queue is: ");
display();
printf("\n");
printf("after dequeue: ");
dequeue();
printf("\n");
printf("queue is: ");
display();
return 0;
}
void push1(int x) {
if(top1 == n-1) {
printf("overflow");
} else {
top1++;
s1[top1] = x;
}
}
int pop1() {
int item = s1[top1];
top1--;
return item;
}
void push2(int x) {
if(top2 == n-1) {
printf("overflow");
} else {
top2++;
s2[top2] = x;
}
}
int pop2() {
int item = s2[top2];
top2--;
return item;
}
void enqueue(int x) {
push1(x);
count++;
}
void dequeue() {
int a,b;
if(top1 == -1 && top2 == -1) {
printf("underflow");
} else {
for(int i = 0; i < count; i++) {
a = pop1();
push2(a);
}
b = pop2();
printf("dequeued element is %d\n",b);
count--;
for(int i = 0; i < count; i++) {
a = pop2();
push1(a);
}
}
}
void display() {
if(top1 == -1) {
printf("queue is empty");
} else {
for(int i = 0; i <= top1; i++) {
printf("%d ",s1[i]);
}
}
}
