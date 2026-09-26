#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *prev;
struct node *next;
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
} else {
tail->next = newNode;
newNode->prev = tail;
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
} else {
tail->next = newNode;
newNode->prev = tail;
tail = newNode;
}
printf("Do u want to continue(0 or 1): ");
scanf("%d", &choice);
}
if(choice == 0) {
temp = head;
while(temp != 0) {
printf("%d ",temp->data);
temp = temp->next;
}
}
return 0;
}
