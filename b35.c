#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *next;
struct node *prev;
};
int main() {
int choice;
struct node *head,*tail,*newNode,*temp;
head = 0;
newNode = (struct node*)malloc(sizeof(struct node));
printf("Enter data: ");
scanf("%d", &newNode->data);
if(head == 0) {
head = newNode;
tail = newNode;
head->next = newNode;
head->prev = newNode;
} else {
tail->next = newNode;
newNode->prev = tail;
newNode->next = head;
head->prev = newNode;
tail = newNode;
}
printf("Do u want to continue(0 or 1): ");
scanf("%d", &choice);
while(choice) {
newNode = (struct node*)malloc(sizeof(struct node));
printf("Enter data: ");
scanf("%d", &newNode->data);
if(head == 0) {
head = newNode;
tail = newNode;
head->next = head;
head->prev = head;
} else {
tail->next = newNode;
newNode->prev = tail;
newNode->next = head;
head->prev = newNode;
tail = newNode;
}
printf("Do u want to continue(0 or 1): ");
scanf("%d", &choice);
}
if(choice == 0) {
newNode = (struct node*)malloc(sizeof(struct node));
printf("Enter data: ");
scanf("%d", &newNode->data);
if(head == 0) {
head = newNode;
tail = newNode;
head->next = head;
head->prev = head;
} else {
newNode->next = head;
newNode->prev = tail;
head->prev = newNode;
tail->next = newNode;
head = newNode;
}
temp = head;
while(temp != tail) {
printf("%d ",temp->data);
temp = temp->next;
}
printf("%d",temp->data);
}
return 0;
}
