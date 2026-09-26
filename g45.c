#include <stdio.h>
void swap(int *x,int *y) {
int temp = *x;
*x = *y;
*y = temp;
}
int insertHeap(int a[],int n,int value) {
n++;
a[n] = value;
int i = n;
while(i > 1) {
int parent = i/2;
if(a[parent] < a[i]) {
swap(&a[parent],&a[i]);
i = parent;
} else {
break;
}
}
return n;
}
int main() {
int a[20];
int n = 0;
int num,val;
printf("Enter no.of elements: ");
scanf("%d", &num);
for(int k = 1; k <= num; k++) {
printf("Enter element%d: ",k);
scanf("%d", &val);
n = insertHeap(a,n,val);
}
for(int i = 1; i <= num; i++) {
printf("%d ",a[i]);
}
printf("\n");
return 0;
}
