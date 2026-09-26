#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *prev;
struct node *next;
};
int main() {
int choice,pos,i=1,count=0;
struct node *head,*tail,*temp,*newNode;
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
count++;
temp = temp->next;
}
printf("Enter position: ");
scanf("%d", &pos);
if(pos == 1) {
temp = head;
head = head->next;
head->prev = 0;
free(temp);
} else if(pos == count) {
temp = tail;
tail->prev->next = 0;
tail = tail->prev;
} else {
temp = head;
while(i < pos) {
temp = temp->next;
i++;
}
temp->prev->next = temp->next;
temp->next->prev = temp->prev;
free(temp);
}
temp = head;
while(temp != 0) {
printf("%d ",temp->data);
temp = temp->next;
}
}
return 0;
}
