#include <stdio.h>
int min(int a,int b) {
if(a < b) {
return a;
} else {
return b;
}
}
int helper(int cost[],int i) {
if(i == 0) {
return cost[0];
}
if(i == 1) {
return cost[1];
}
int a = cost[i] + helper(cost,i-1);
int b = cost[i] + helper(cost,i-2);
return min(a,b);
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
int a = helper(cost,n-1);
int b = helper(cost,n-2);
int c = min(a,b);
printf("Minimum cost: %d\n",c);
return 0;
}
