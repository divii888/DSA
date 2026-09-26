#include <stdio.h>
int binarySearch(int a[],int n,int data);
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
for(int j = i+1; j < n; j++) {
if(a[i] > a[j]) {
int temp = a[i];
a[i] = a[j];
a[j] = temp;
}
}
}
int data;
printf("Enter data to search: ");
scanf("%d", &data);
int index = binarySearch(a,n,data);
printf("Element is present in index %d of sorted array\n",index);
return 0;
}
int binarySearch(int a[],int n,int data) {
int l = 0;
int r = n-1;
while(l <= r) {
int mid = (l+r)/2;
if(data == a[mid]) {
return mid;
} else if(data < a[mid]) {
r = mid-1;
} else {
l = mid+1;
}
}
return -1;
}
