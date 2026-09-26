#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *next;
};
int main() {
int choice,i=1,count=0,pos;
struct node *tail,*newNode,*current,*prev,*temp,*nextnode;
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
if(pos < 1 || pos > count) {
printf("Invalid position");
} else if(pos == 1) {
temp = tail->next;
if(tail == 0) {
printf("List is empty");
} else if(temp->next = temp) {
tail = 0;
free(temp);
} else {
tail->next = temp->next;
free(temp);
}
} else if(pos == count) {
current = tail->next;
if(tail == 0) {
printf("list is empty");
} else if(current->next == current) {
tail = 0;
free(current);
} else {
while(current->next != tail->next) {
prev = current;
current = current->next;
}
prev->next = current->next;
tail = prev;
}
} else {
current = tail->next;
while(i < pos-1) {
current = current->next;
i++;
}
nextnode = current->next;
current->next = nextnode->next;
free(nextnode);
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
