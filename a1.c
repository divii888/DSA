#include <stdio.h>
int main() {
int n;
printf("Enter size of array: ");
scanf("%d", &n);
int arr[n];
for(int i = 0; i < n; i++) {
printf("Enter arr[%d]: ",i);
scanf("%d", &arr[i]);
printf("\n");
}
int pos;
printf("Enter position of insertion: ");
scanf("%d", &pos);
int num;
printf("Enter number to be inserted: ");
scanf("%d", &num);
n++;
for(int i = n-1; i > pos-1; i--) {
arr[i] = arr[i-1];
}
arr[pos-1] = num;
printf("Modified array is: \n");
for(int i = 0; i < n; i++) {
printf("%d ",arr[i]);
}
return 0;
}
