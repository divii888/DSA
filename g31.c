#include <stdio.h>
int main() {
int n;
printf("Enter the no.of elements: ");
scanf("%d", &n);
int arr[n];
for(int i = 0; i < n; i++) {
printf("Enter arr[%d]: ",i);
scanf("%d", &arr[i]);
}
int data;
printf("Enter data to be searched: ");
scanf("%d", &data);
int found = 0;
for(int i = 0; i < n; i++) {
if(arr[i] == data) {
printf("Element found in %d index\n",i);
found = 1;
break;
}
}
if(found == 0) {
printf("Element not found\n");
}
return 0;
}
