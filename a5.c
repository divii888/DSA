#include <stdio.h>
int main() {
int n;
printf("Enter size: ");
scanf("%d", &n);
int nums[n];
for(int i = 0; i < n; i++) {
printf("Enter nums[%d]: ",i);
scanf("%d", &nums[i]);
}
for(int i = 0; i < n; i++) {
int count = 0;
for(int j = 0 ; j < n; j++) {
if(nums[i] == nums[j]) {
count++;
}
}
if(count > n/2) {
printf("Majority element is %d\n", nums[i]);
break;
}
}
return 0;
}
