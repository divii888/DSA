#include <stdio.h>
int main() {
int n;
printf("Enter size: ");
scanf("%d", &n);
int top = -1;
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
if(top == -1) {
printf("stack is empty");
} else {
printf("topmost element is %d",stack[top]);
}
return 0;
}
