#include <stdio.h>
int climbingStairs(int n) {
if(n == 0) {
return 1;
}
if(n == 1) {
return 1;
}
if(n == 2) {
return 2;
}
return climbingStairs(n-1)+climbingStairs(n-2);
}
int main() {
int n;
printf("Enter n: ");
scanf("%d", &n);
printf("%d\n",climbingStairs(n));
return 0;
}
