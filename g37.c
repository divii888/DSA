#include <stdio.h>
int main() {
int n;
printf("Enter no.of elements: ");
scanf("%d", &n);
int a[n];
for(int i = 0; i < n; i++) {
printf("Enter a[%d]: ",i);
scanf("%d", &a[i]);
}
for(int i = 1; i < n; i++) {
int temp = a[i];
int j = i-1;
while(j >= 0 && a[j] > temp) {
a[j+1] = a[j];
j--;
}
a[j+1] = temp;
}
printf("Sorted array:\n");
for(int i = 0; i < n; i++) {
printf("%d ",a[i]);
}
return 0;
}
