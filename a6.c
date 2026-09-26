#include <stdio.h>
int main() {
int n;
printf("Enter n: ");
scanf("%d", &n);
int nums[n];
for(int i = 0; i < n; i++) {
printf("Enter nums[%d]: ",i);
scanf("%d", &nums[i]);
}
int me = 0, vote = 0;
for(int i = 0; i < n; i++) {
if(vote == 0) {
me = nums[i];
}
if(me == nums[i]) {
vote++;
} else {
vote--;
}
}
printf("Majority element is %d\n", me);
return 0;
}
