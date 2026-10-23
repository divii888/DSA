#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *next;
};
int main() {
int choice;
struct node *front,*rear,*newNode,*temp;
front = 0;
rear = 0;
newNode = (struct node*)malloc(sizeof(struct node));
printf("Enter data: ");
scanf("%d", &newNode->data);
newNode->next = 0;
if(front == 0 && rear == 0) {
front = newNode;
rear = newNode;
} else {
rear->next = newNode;
rear = newNode;
}
printf("Do u want to continue(0 or 1): ");
scanf("%d", &choice);
while(choice) {
newNode = (struct node*)malloc(sizeof(struct node));
printf("Enter data: ");
scanf("%d", &newNode->data);
newNode->next = 0;
if(front == 0 && rear == 0) {
front = newNode;
rear = newNode;
} else {
rear->next = newNode;
rear = newNode;
}
printf("Do u want to continue(0 or 1): ");
scanf("%d", &choice);
}
if(choice == 0) {
printf("Elements: ");
if(front == 0 && rear == 0) {
printf("queue is empty");
} else {
temp = front;
while(temp != 0) {
printf("%d ",temp->data);
temp = temp->next;
}
}
printf("\n");
if(front == 0 && rear == 0) {
printf("underflow");
} else {
temp = front;
printf("dequeued element is %d\n",front->data);
front = front->next;
free(temp);
}
printf("after dequeue: ");
temp = front;
while(temp != 0) {
printf("%d ",temp->data);
temp = temp->next;
}
if(front == 0 && rear == 0) {
printf("queue is empty");
} else {
printf("front element is %d\n",front->data);
}
}
return 0;
}
