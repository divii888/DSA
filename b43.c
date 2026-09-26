#include <stdio.h>
int main() {
int n;
int top = -1;
printf("Enter size: ");
scanf("%d", &n);
int stack[n];
for(int i = 0; i < n; i++) {
int x;
printf("Enter data: ");
scanf("%d", &x);
if(top == n-1) {
printf("overflow");
} else {
top++;
stack[top] = x;
}
}
int item;
if(top == -1) {
printf("underflow");
} else {
item = stack[top];
top--;
}
printf("popped out element is %d",item);
return 0;
}
