#include <stdio.h>
int min(int a,int b) {
if(a < b) {
return a;
} else {
return b;
}
}
int stairs(int cost[],int n) {
int prev1 = 10;
int prev2 = 15;
int current;
for(int i = 2; i < n; i++)  {
current = cost[i] + min(prev1,prev2);
prev1 = prev2;
prev2 = current;
}
int c = min(prev1,prev2);
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
int a = stairs(cost,n);
printf("Minimum cost: %d\n",a);
return 0;
}
