#include <stdio.h>
int main() {
int n;
printf("Enter no.of elements: ");
scanf("%d", &n);
int a[n];
for(int i = 0; i < n; i++) {
printf("Enter element%d: ",i);
scanf("%d", &a[i]);
}
int k = 0;
for(int i = 0; i < n; i++) {
if(a[i] > k) {
k = a[i];
}
}
int count[k+1],b[n];
for(int i = 0; i <= k; i++) {
count[i] = 0;
}
for(int i = 0; i < n; i++) {
count[a[i]]++;
}
for(int i = 1; i <= k; i++) {
count[i] = count[i] + count[i-1];
}
for(int i = n-1; i >= 0; i--) {
b[--count[a[i]]] = a[i];
}
for(int i = 0; i < n; i++) {
a[i] = b[i];
}
printf("Sorted array:\n");
for(int i = 0; i < n; i++) {
printf("%d ",a[i]);
}
printf("\n");
return 0;
}
