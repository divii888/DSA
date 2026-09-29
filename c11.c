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
printf("Do u want to continue: ");
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
if(top == 0) {
printf("stack is empty");
} else {
printf("topmost element is %d",top->data);
}
}
return 0;
}
