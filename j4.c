#include <stdio.h>
int fib(int n) {
if(n == 0) {
return 0;
}
int dp[n+1];
dp[0] = 0;
dp[1] = 1;
for(int i = 2; i <= n; i++) {
dp[i] = dp[i-1] + dp[i-2];
}
return dp[n];
}
int main() {
int n;
printf("Enter term: ");
scanf("%d", &n);
printf("%d\n",fib(n));
return 0;
}
