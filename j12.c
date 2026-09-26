#include <stdio.h>
int climbingStairs(int n) {
if(n == 0) {
return 0;
}
if(n == 1) {
return 1;
}
if(n == 2) {
return 2;
}
int prev1 = 1;
int prev2 = 2;
int current;
for(int i = 3; i <= n; i++) {
current = prev1 + prev2;
prev1 = prev2;
prev2 = current;
}
return current;
}
int main() {
int n;
printf("Enter n: ");
scanf("%d", &n);
printf("%d\n",climbingStairs(n));
return 0;
}

