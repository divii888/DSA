#include <stdio.h>
void swap(int *x,int *y) {
int temp = *x;
*x = *y;
*y = temp;
}
int main() {
int n;
printf("Enter no.of elements: ");
scanf("%d", &n);
int a[n];
for(int i = 0; i < n; i++) {
printf("Enter element%d: ",i);
scanf("%d", &a[i]);
}
for(int gap = n/2; gap >= 1; gap = gap/2) {
for(int j = gap; j < n; j++) {
for(int i = j-gap; i >= 0; i = i-gap) {
if(a[i+gap] > a[i]) {
break;
} else {
swap(&a[i+gap],&a[i]);
}
}
}
}
printf("Sorted array:\n");
for(int i = 0; i < n; i++) {
printf("%d ",a[i]);
}
printf("\n");
return 0;
}
