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
printf("Enter data: ");
scanf("%d", &x);
enqueue(x);
}
printf("\n");
display();
printf("\n");
printf("After dequeue: ");
dequeue();
printf("\n");
display();
peek();
return 0;
}
void enqueue(int x) {
if(((rear+1)%n) == front) {
printf("overflow");
} else if(front == -1 && rear == -1) {
front = 0;
rear = 0;
queue[rear] = x;
} else {
rear = (rear+1)%n;
queue[rear] = x;
}
}
void display() {
int i = front;
if(front == -1 && rear == -1) {
printf("queue is empty");
} else {
printf("Queue is: ");
while(i != rear) {
printf("%d ",queue[i]);
i = (i+1)%n;
}
printf("%d",queue[rear]);
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
front = (front+1)%n;
}
}
void peek() {
if(front == -1 && rear == -1) {
printf("queue is empty");
} else {
printf("front element is %d\n",queue[front]);
}
}
