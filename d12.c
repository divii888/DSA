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
rear->next = front;
} else {
rear->next = newNode;
rear = newNode;
rear->next = front;
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
rear->next = front;
} else {
rear->next = newNode;
rear = newNode;
rear->next = front;
}
printf("Do u want to continue(0 or 1): ");
scanf("%d", &choice);
}
if(choice == 0) {
temp = front;
if(front == 0 && rear == 0) {
printf("queue is empty");
} else {
printf("queue is: ");
while(temp->next != front) {
printf("%d ",temp->data);
temp = temp->next;
}
printf("%d",temp->data);
}
printf("\n");
temp = front;
if(front == 0 && rear == 0) {
printf("queue is empty");
} else if(front == rear) {
printf("dequeued element is %d\n",front->data);
front = 0;
rear = 0;
free(temp);
} else {
printf("dequeued element is %d\n",front->data);
front = front->next;
rear->next = front;
free(temp);
}
printf("After dequeue: ");
temp = front;
while(temp->next != front) {
printf("%d ",temp->data);
temp = temp->next;
}
printf("%d",temp->data);
if(front == 0 && rear == 0) {
printf("queue is empty\n");
} else {
printf("front element is %d\n",front->data);
}
}
return 0;
}
