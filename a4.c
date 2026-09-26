#include <stdio.h>
int main() {
int n;
printf("enter size of array: ");
scanf("%d", &n);
int nums[n];
for(int i = 0; i < n; i++) {
printf("Enter nums[%d]: ",i);
scanf("%d", &nums[i]);
}
int val;
printf("Enter value to be removed: ");
scanf("%d", &val);
int count = 0;
for(int i = 0; i < n; i++) {
if(nums[i] != val) {
nums[count] = nums[i];
count++;
}
}
for(int i = 0; i < count; i++) {
printf("%d ",nums[i]);
}
printf("No.of elements: %d",count);
return 0;
}

