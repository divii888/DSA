#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *prev;
struct node *next;
};
int main() {
int choice,count=0,i=1,pos;
struct node *head,*tail,*newNode,*temp;
head = 0;
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
newNode->next = head;
newNode->prev = tail;
head->prev = newNode;
tail = newNode;
}
printf("Do u want to continue(0 or1): ");
scanf("%d", &choice);
}
if(choice == 0) {
temp = head;
while(temp != tail) {
count++;
temp = temp->next;
}
count++;
printf("Enter position: ");
scanf("%d", &pos);
if(pos < 1 || pos > count+1) {
printf("invalid position");
} else if(pos == 1) {
newNode = (struct node*)malloc(sizeof(struct node));
printf("Enter data to be inserted: ");
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
} else if(pos == count+1) {
newNode = (struct node*)malloc(sizeof(struct node));
printf("Enter data to be inserted: ");
scanf("%d", &newNode->data);
if(head == 0) {
head = newNode;
tail = newNode;
head->next = head;
head->prev = head;
} else {
newNode->next = head;
newNode->prev = tail;
tail->next = newNode;
head->prev = newNode;
}
} else {
newNode = (struct node*)malloc(sizeof(struct node));
printf("Enter data to be inserted: ");
scanf("%d", &newNode->data);
temp = head;
while(i < pos-1) {
temp = temp->next;
i++;
}
newNode->prev = temp;
newNode->next = temp->next;
temp->next->prev = newNode;
temp->next = newNode;
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
