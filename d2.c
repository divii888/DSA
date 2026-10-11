#include <stdio.h>
int main() {
int n;
printf("Enter size: ");
scanf("%d", &n);
int queue[n];
int front = -1;
int rear = -1;
for(int i = 0; i < n; i++) {
int x;
printf("Enter data: ");
scanf("%d", &x);
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
for(int i = front; i <= rear; i++) {
if(front == -1 && rear == -1) {
printf("queue is empty");
} else {
printf("%d ",queue[i]);
}
}
return 0;
}
