#include <stdio.h>
int min(int a,int b) {
if(a < b) {
return a;
} else {
return b;
}
}
int stairs(int cost[],int i,int n) {
if(i >= n) {
return 0;
}
int a = cost[i] + stairs(cost,i+1,n);
int b = cost[i] + stairs(cost,i+2,n);
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
int a = stairs(cost,0,n);
int b = stairs(cost,1,n);
int c = min(a,b);
printf("Minimun cost: %d\n",c);
return 0;
}
