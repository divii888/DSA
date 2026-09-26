#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *next;
};
int main() {
int choice;
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
