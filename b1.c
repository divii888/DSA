#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *next;
};
int main() {
int choice;
struct node *head,*newNode,*temp;
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
temp = temp->next;
}
printf("Do u want to continue(0 or 1): \n");
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
temp = head;
while(temp != 0) {
printf("%d",temp->data);
temp = temp->next;
}
}
return 0;
}
