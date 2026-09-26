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
int seen = 0;
for(int j = 0; j < n; j++) {
if(nums[i] == nums[j]) {
count++;
}
}
for(int k = 0; k < i; k++) {
if(nums[k] == nums[i]) {
seen = 1;
}
}
if(seen) {
continue;
}
if(count >= 2) {
printf("true for %d\n",nums[i]);
} else {
printf("false for %d\n",nums[i]);
}
}
return 0;
}
