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
printf("Enter a[%d]: ",i);
scanf("%d", &a[i]);
}
for(int i = 0; i < n-1; i++) {
int min = i;
for(int j = i+1; j < n; j++) {
if(a[j] < a[min]) {
min = j;
}
}
if(min != i) {
swap(&a[i],&a[min]);
}
}
for(int i = 0; i < n; i++) {
printf("%d ", a[i]);
}
return 0;
}
