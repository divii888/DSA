#include <stdio.h>
int climbingStairs(int dp[],int n) {
if(n == 0) {
return 1;
}
if(n == 1) {
return 1;
}
if(n == 2) {
return 2;
}
if(dp[n] != -1) {
return dp[n];
}
dp[n] = climbingStairs(dp,n-1) + climbingStairs(dp,n-2);
return dp[n];
}
int main() {
int n;
printf("Enter n: ");
scanf("%d", &n);
int dp[n+1];
for(int i = 0; i <= n; i++) {
dp[i] = -1;
}
printf("%d\n",climbingStairs(dp,n));
return 0;
}
