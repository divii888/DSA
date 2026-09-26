#include <stdio.h>
int ways(int coins[],int n,int amount) {
int a[n][amount+1];
for(int i = 0; i < n; i++) {
a[i][0] = 1;
}
for(int j = 1; j <= amount; j++) {
if(coins[0] > j) {
a[0][j] = 0;
} else {
a[0][j] = a[0][j-coins[0]];
}
}
for(int i = 1; i < n; i++) {
for(int j = 1; j <= amount; j++) {
if(coins[i] > j) {
a[i][j] = a[i-1][j];
} else {
a[i][j] = a[i-1][j] + a[i][j-coins[i]];
}
}
}
return a[n-1][amount];
}
int main() {
int coins[10];
int n = 0;
int choice;
printf("Want to enter?(0 or 1): ");
scanf("%d", &choice);
while(choice) {
printf("Enter: ");
scanf("%d", &coins[n]);
n++;
printf("Enter another?(0 or 1): ");
scanf("%d", &choice);
}
int amount;
printf("Enter amount: ");
scanf("%d", &amount);
int a = ways(coins,n,amount);
printf("Total no.of ways: %d\n",a);
return 0;
}
