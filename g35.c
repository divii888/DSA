#include <stdio.h>
int main() {
int n;
printf("Enter the no.of elements: ");
scanf("%d", &n);
int a[n];
for(int i = 0; i < n; i++) {
printf("Enter a[%d]: ",i);
scanf("%d", &a[i]);
}
for(int i = 0; i < n-1; i++) {
int flag = 0;
for(int j = 0; j < n-1-i; j++) {
if(a[j] > a[j+1]) {
int temp = a[j];
a[j] = a[j+1];
a[j+1] = temp;
flag = 1;
}
}
if(flag == 0) {
break;
}
}
printf("Sorted array:\n");
for(int i = 0; i < n; i++) {
printf("%d ",a[i]);
}
printf("\n");
return 0;
}
