#include <stdio.h>
#define n 5
int dequeue[n];
int front = -1,rear = -1;
void enqueuefront(int x);
void enqueuerear(int x);
void dequeuefront();
void dequeuerear();
void display();
int main() {
int choice;
do {
int x;
printf("Enter choice(1-enqueue at front, 2-enqueue at rear, 3-dequeue at front, 4-dequeue at rear, 5-display): ");
scanf("%d", &choice);
switch(choice) {
case 1: printf("Enter data: ");
scanf("%d", &x);
enqueuefront(x);
break;
case 2: printf("Enter data: ");
scanf("%d", &x);
enqueuerear(x);
break;
case 3: dequeuefront();
break;
case 4: dequeuerear();
break;
case 5: display();
break;
default: printf("invalid choice");
}
} while(choice != 0);
return 0;
}
void enqueuefront(int x) {
if(((rear+1)%n) == front) {
printf("overflow\n");
} else if(front == -1 && rear == -1) {
front = 0;
rear = 0;
dequeue[front] = x;
} else if(front == 0) {
front = n-1;
dequeue[front] = x;
} else {
front--;
dequeue[front] = x;
}
}
void enqueuerear(int x) {
if(((rear+1)%n) == front) {
printf("overflow");
} else if(front == -1 && rear == -1) {
front = 0;
rear = 0;
dequeue[rear] = x;
} else {
rear = (rear+1)%n;
dequeue[rear] = x;
}
}
void dequeuefront() {
if(front == -1 && rear == -1) {
printf("underflow");
} else if(front == rear) {
printf("dequeued element is %d\n",dequeue[front]);
front = -1;
rear = -1;
} else {
printf("dequeued element is %d\n",dequeue[front]);
front = (front+1)%n;
}
}
void dequeuerear() {
if(front == -1 && rear == -1) {
printf("underflow");
} else if(front == rear) {
printf("dequeued element is %d\n",dequeue[rear]);
front = -1;
rear = -1;
} else if(rear == 0) {
printf("dequeued element is %d\n",dequeue[rear]);
rear = n-1;
} else {
printf("dequeued element is %d\n",dequeue[rear]);
rear--;
}
}
void display() {
int i = front;
if(front == -1 && rear == -1) {
printf("queue is empty");
} else {
while(i != rear) {
printf("%d ",dequeue[i]);
i = (i+1)%n;
}
printf("%d\n",dequeue[rear]);
}
}
