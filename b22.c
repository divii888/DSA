#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *next;
};
int main() {
int choice;
struct node *head,*tail,*temp,*newNode;
head = 0;
newNode = (struct node*)malloc(sizeof(struct node));
printf("Enter data: ");
scanf("%d", &newNode->data);
newNode->next = 0;
if(head == 0) {
head = newNode;
tail = newNode;
tail->next = head;
} else {
tail->next = newNode;
tail = newNode;
tail->next = head;
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
tail = newNode;
tail->next = head;
} else {
tail->next = newNode;
tail = newNode;
tail->next = head;
}
printf("Do u want to continue: ");
scanf("%d", &choice);
}
if(choice == 0) {
temp = head;
while(temp->next != head) {
printf("%d ",temp->data);
temp = temp->next;
}
printf("%d",temp->data);
}
return 0;
}
