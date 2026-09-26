#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *next;
};
int main() {
int choice,pos,count = 0,i = 1;
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
temp = head;
while(temp != 0) {
temp = temp->next;
count++;
}
printf("Enter position after which node to be inserted: ");
scanf("%d", &pos);
if(pos > count) {
printf("invalid position\n");
} else {
temp = head;
while(i < pos) {
temp = temp->next;
i++;
}
newNode = (struct node*)malloc(sizeof(struct node));
printf("Enter data to be inserted: ");
scanf("%d", &newNode->data);
newNode->next = temp->next;
temp->next = newNode;
}
temp = head;
while(temp != 0) {
printf("%d ",temp->data);
temp = temp->next;
}
}
return 0;
}

