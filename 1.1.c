#include <stdio.h>
void compare(int *a,int *b);
int main() {
int x,y;
printf("Enter two numbers: ");
scanf("%d %d", &x, &y);
compare(&x,&y);
return 0;
}
void compare(int *a,int *b) {
if(*a < *b) {
printf("%d is smaller than %d\n",*a,*b);
} else if(*a > *b) {
printf("%d is greater than %d\n",*a,*b);
} else if(*a == *b) {
printf("%d is equal to %d\n",*a,*b);
}
}
