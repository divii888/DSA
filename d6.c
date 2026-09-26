#include <stdio.h>
#define n 5
int queue[n];
int front = -1;
int rear = -1;
void enqueue(int x);
void display();
void dequeue();
void peek();
int main() {
for(int i = 0; i < n; i++) {
int x;
printf("Enter data to be inserted: ");
scanf("%d", &x);
enqueue(x);
}
display();
dequeue();
printf("after dequeue: ");
display();
peek();
return 0;
}
void enqueue(int x) {
if(rear == n-1) {
printf("overflow");
} else if(front == -1 && rear == -1) {
front = 0;
rear = 0;
queue[rear] = x;
} else {
rear++;
queue[rear] = x;
}
}
void display() {
if(front == -1 && rear == -1) {
printf("queue is empty");
} else {
for(int i = front; i <= rear; i++) {
printf("%d ",queue[i]);
}
}
}
void dequeue() {
if(front == -1 && rear == -1) {
printf("underflow");
} else if(front == rear) {
printf("dequeued element is %d\n",queue[front]);
front = -1;
rear = -1;
} else {
printf("dequeued element is %d\n",queue[front]);
front++;
}
}
void peek() {
if(front == -1 && rear == -1) {
printf("queue is empty");
} else {
printf("front element is %d\n",queue[front]);
}
}
