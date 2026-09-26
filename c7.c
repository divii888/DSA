#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *link;
};
int main() {
int choice;
struct node *top = 0;
struct node *newNode,*temp;
newNode = (struct node*)malloc(sizeof(struct node));
printf("Enter data: ");
scanf("%d", &newNode->data);
newNode->link = top;
top = newNode;
printf("Do u want to continue(0 or 1): ");
scanf("%d", &choice);
while(choice) {
newNode = (struct node*)malloc(sizeof(struct node));
printf("Enter data: ");
scanf("%d", &newNode->data);
newNode->link = top;
top = newNode;
printf("Do u want to continue(0 or 1): ");
scanf("%d", &choice);
}
if(choice == 0) {
temp = top;
if(top == 0) {
printf("stack is empty");
} else {
while(temp != 0) {
printf("%d ",temp->data);
temp = temp->link;
}
}
}
return 0;
}
