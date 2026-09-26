#include <stdio.h>
int main() {
int n;
printf("Enter size: ");
scanf("%d", &n);
int stack[n];
int top = -1;
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
for(int i = top; i >= 0; i--) {
printf("%d ",stack[i]);
}
return 0;
}
