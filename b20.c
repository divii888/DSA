#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *prev;
struct node *next;
};
int main() {
int choice;
struct node *head,*temp,*newNode;
head = 0;
newNode = (struct node*)malloc(sizeof(struct node));
printf("Enter data: ");
scanf("%d", &newNode->data);
newNode->next = 0;
if(head == 0) {
head = newNode;
temp = newNode;
} else {
temp->next = newNode;
temp = newNode;
}
printf("Do u want to continue(0 or 1): ");
scanf("%d", &choice);
while(choice) {
newNode = (struct node*)malloc(sizeof(struct node));
printf("Enter data: ");
scanf("%d", &newNode->data);
newNode->next = 0;
if(head == 0) {
head = newNode;
temp = newNode;
} else {
temp->next = newNode;
temp = newNode;
}
printf("Do u want to continue(0 or 1): ");
scanf("%d", &choice);
}
if(choice == 0) {
temp->next = head;
temp = head;
while(temp->next != head) {
printf("%d ",temp->data);
temp = temp->next;
}
printf("%d",temp->data);
}
return 0;
}
