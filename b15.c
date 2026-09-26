#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *next;
struct node *prev;
};
int main() {
int choice,count = 0,i = 1,pos;
struct node *head,*tail,*newNode,*temp;
head = 0;
newNode = (struct node*)malloc(sizeof(struct node));
printf("Enter data: ");
scanf("%d", &newNode->data);
newNode->prev = 0;
newNode->next = 0;
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
newNode->prev = 0;
newNode->next = 0;
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
count++;
temp = temp->next;
}
printf("Enter position: ");
scanf("%d", &pos);
if(pos < 1 || pos > count+1) {
printf("invalid position");
} else if(pos == 1) {
newNode = (struct node*)malloc(sizeof(struct node));
printf("Enter data to be inserted: ");
scanf("%d", &newNode->data);
newNode->prev = 0;
newNode->next = 0;
head->prev = newNode;
newNode-> next = head;
head = newNode;
} else {
newNode = (struct node*)malloc(sizeof(struct node));
printf("Enter data to be inserted: ");
scanf("%d", &newNode->data);
newNode->next = 0;
newNode->prev = 0;
temp = head;
while(i < pos-1) {
temp = temp->next;
i++;
}
newNode->prev = temp;
newNode->next = temp->next;
temp->next = newNode;
newNode->next->prev = newNode;
}
temp = head;
while(temp != 0) {
printf("%d ",temp->data);
temp = temp->next;
}
}
return 0;
}
