#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *next;
};
int main() {
int choice,pos,i=1,count=0;
struct node *tail,*newNode,*temp;
tail = 0;
newNode = (struct node*)malloc(sizeof(struct node));
printf("Enter data: ");
scanf("%d", &newNode->data);
newNode->next = 0;
if(tail == 0) {
tail = newNode;
tail->next = newNode;
} else {
newNode->next = tail->next;
tail->next = newNode;
tail = newNode;
}
printf("Do u want to continue(0 or 1): ");
scanf("%d", &choice);
while(choice) {
newNode = (struct node*)malloc(sizeof(struct node));
printf("Enter data: ");
scanf("%d", &newNode->data);
newNode->next = 0;
if(tail == 0) {
tail = newNode;
tail->next = newNode;
} else {
newNode->next = tail->next;
tail->next = newNode;
tail = newNode;
}
printf("Do u want to continue(0 or 1): ");
scanf("%d", &choice);
}
if(choice == 0) {
temp = tail->next;
while(temp->next != tail->next) {
count++;
temp = temp->next;
}
count++;
printf("Enter position: ");
scanf("%d", &pos);
if(pos < 1 || pos > count+1) {
printf("Invalid position");
} else if(pos == 1) {
newNode = (struct node*)malloc(sizeof(struct node));
printf("Enter data to be inserted: ");
scanf("%d", &newNode->data);
newNode->next = 0;
if(tail == 0) {
tail = newNode;
tail->next = newNode;
} else {
newNode->next = tail->next;
tail->next = newNode;
tail = newNode;
}
} else if(pos == count+1) {
newNode = (struct node*)malloc(sizeof(struct node));
printf("Enter data to be inserted: ");
scanf("%d", &newNode->data);
newNode->next = 0;
if(tail == 0) {
tail = newNode;
tail->next = newNode;
} else {
newNode->next = tail->next;
tail->next = newNode;
tail = newNode;
}
} else {
newNode = (struct node*)malloc(sizeof(struct node));
printf("Enter data to be inserted: ");
scanf("%d", &newNode->data);
newNode->next = 0;
if(tail == 0) {
tail = newNode;
tail->next = newNode;
} else {
temp = tail->next;
while(i < pos-1) {
temp = temp->next;
i++;
} 
newNode->next = temp->next;
temp->next = newNode;
}
}
temp = tail->next;
while(temp->next != tail->next) {
printf("%d ",temp->data);
temp = temp->next;
}
printf("%d",temp->data);
}
return 0;
}
