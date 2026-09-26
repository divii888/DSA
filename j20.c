#include <stdio.h>
int min(int a,int b) {
if(a < b) {
return a;
} else {
return b;
}
}
int stairs(int cost[],int n) {
int dp[n+1];
dp[0] = 10;
dp[1] = 15;
for(int i = 2; i < n; i++) {
dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
}
int c = min(dp[n-1],dp[n-2]);
return c;
}
int main() {
int cost[10];
int n = 0;
int choice;
printf("Want to enter?(0 or 1): ");
scanf("%d", &choice);
while(choice) {
printf("Enter: ");
scanf("%d", &cost[n]);
n++;
printf("Enter another?(0 or 1): ");
scanf("%d", &choice);
}
int c = stairs(cost,n);
printf("Minimum cost: %d\n",c);
return 0;
}
