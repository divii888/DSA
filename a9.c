#include <stdio.h>
int main() {
int n;
printf("Enter size: ");
scanf("%d", &n);
int arr[n];
for(int i = 0; i < n; i++) {
printf("Enter arr[%d]: ",i);
scanf("%d", &arr[i]);
}
for(int i = 0; i < n-1; i++) {
for(int j = i+1; j < n; j++) {
if(arr[i] > arr[j]) {
int temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
}
}
}
printf("\nSorted array:\n");
for(int i = 0; i < n; i++) {
printf("%d ",arr[i]);
}
return 0;
}
