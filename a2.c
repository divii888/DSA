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
n++;
for(int i = n-1; i > 0; i--) {
arr[i] = arr[i-1];
}
arr[0] = 10;
for(int i = 0; i < n; i++) {
printf("%d", arr[i]);
}
return 0;
}
