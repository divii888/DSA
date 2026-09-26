#include <stdio.h>
int main() {
int n;
printf("Enter n: ");
scanf("%d", &n);
int nums[n];
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
printf("true for %d",nums[i]);
} else {
printf("false for %d",nums[i]);
}
}
return 0;
}
