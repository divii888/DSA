#include <stdio.h>
int min(int a,int b) {
if(a < b) {
return a;
} else {
return b;
}
}
int stairs(int cost[],int i,int dp[]) {
if(i == 0) {
return cost[0];
}
if(i == 1) {
return cost[1];
}
if(dp[i] != -1) {
return dp[i];
}
int a = cost[i] + stairs(cost,i-1,dp);
int b = cost[i] + stairs(cost,i-2,dp);
dp[i] = min(a,b);
return dp[i];
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
int dp[n+1];
int a = stairs(cost,n-1,dp);
int b = stairs(cost,n-2,dp);
int c = min(a,b);
printf("Minimum cost: %d\n",c);
return 0;
}
