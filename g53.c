#include <stdio.h>
void countSort(int a[],int n,int pos) {
int count[10];
for(int i = 0; i < 10; i++) {
count[i] = 0;
}
for(int i = 0; i < n; i++) {
count[(a[i]/pos)%10]++;
}
for(int i = 1; i < 10; i++) {
count[i] = count[i] + count[i-1];
}
int b[n];
for(int i = n-1; i >= 0; i--) {
b[--count[(a[i]/pos)%10]] = a[i];
}
for(int i = 0; i < n; i++) {
a[i] = b[i];
}
}
void radixSort(int a[],int n) {
int max = 0;
for(int i = 0; i < n; i++) {
if(a[i] > max) {
max = a[i];
}
}
for(int pos = 1; max/pos > 0; pos = pos*10) {
countSort(a,n,pos);
}
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
radixSort(a,n);
printf("Sorted array:\n");
for(int i = 0; i < n; i++) {
printf("%d ",a[i]);
}
printf("\n");
return 0;
}
