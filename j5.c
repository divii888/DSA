#include <stdio.h>
int fib(int n) {
int prev1 = 0;
int prev2 = 1;
int current;
for(int i = 2; i <= n; i++) {
current = prev1 + prev2;
prev1 = prev2;
prev2 = current;
}
return current;
}
int main() {
int n;
printf("Enter term: ");
scanf("%d", &n);
printf("%d\n",fib(n));
return 0;
}
