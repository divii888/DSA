#include <stdio.h>
void swap(int *x,int *y) {
int temp = *x;
*x = *y;
*y = temp;
}
void maxHeapify(int a[],int n,int i) {
int largest = i;
int l = (2*i);
int r = (2*i)+1;
if(l <= n && a[l] > a[largest]) {
largest = l;
}
if(r <= n && a[r] > a[largest]) {
largest = r;
}
if(largest != i) {
swap(&a[i],&a[largest]);
maxHeapify(a,n,largest);
}
}
void heapSort(int a[],int n) {
for(int i = n/2; i >= 1; i--) {
maxHeapify(a,n,i);
}
for(int i = n; i >= 1; i--) {
swap(&a[1],&a[i]);
maxHeapify(a,i-1,1);
}
}
int main() {
int n;
printf("Enter no.of elements: ");
scanf("%d", &n);
int a[n];
for(int i = 1; i <= n; i++) {
printf("Enter element%d: ",i);
scanf("%d", &a[i]);
}
heapSort(a,n);
printf("Sorted array:\n");
for(int i = 1; i <= n; i++) {
printf("%d ",a[i]);
}
printf("\n");
return 0;
}
