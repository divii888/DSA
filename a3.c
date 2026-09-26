#include <stdio.h>
int main() {
int n;
printf("Enter size: ");
scanf("%d", &n);
int arr[n];
for(int i = 0; i < n; i++) {
printf("Enter a[%d]: ",i);
scanf("%d", &arr[i]);
} 
int pos;
printf("Enter position: ");
scanf("%d", &pos);
n--;
for(int i = pos-1; i < n; i++) {
arr[i] = arr[i+1];
}
for(int i = 0; i < n; i++) {
printf("%d",arr[i]);
}
printf("%d\n",*arr);
printf("%d\n",*(arr+1));
printf("%d\n",*arr+1);
return 0;
}
