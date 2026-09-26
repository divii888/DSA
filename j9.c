#include <stdio.h>
int climbingStairs(int n,int dp[]) {
if(n == 0) {
return 0;
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
dp[n] = climbingStairs(n-1,dp)+climbingStairs(n-2,dp);
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
printf("%d\n",climbingStairs(n,dp));
return 0;
}
