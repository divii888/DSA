#include <stdio.h>
#define MAX 100
char data[MAX];
int freq[MAX];
int left[MAX],right[MAX];
int isLeaf[MAX];
int total = 0;
int heap[MAX];
int heapSize = 0;
void swap(int *x,int *y) {
int temp = *x;
*x = *y;
*y = temp;
}
void insertMinHeap(int index) {
heapSize++;
int i = heapSize;
heap[i] = index;
while(i > 1) {
int parent = i/2;
if(freq[heap[parent]] > freq[heap[i]]) {
swap(&heap[parent],&heap[i]);
i = parent;
} else {
break;
}
}
}
int extractMin() {
int minIndex = heap[1];
heap[1] = heap[heapSize];
heapSize--;
int i = 1;
while(1) {
int l = 2*i;
int r = 2*i+1;
int smallest = i;
if(l <= heapSize && freq[heap[l]] < freq[heap[smallest]]) {
smallest = l;
}
if(r <= heapSize && freq[heap[r]] < freq[heap[smallest]]) {
smallest = r;
}
if(smallest == i) {
break;
}
swap(&heap[i],&heap[smallest]);
i = smallest;
}
return minIndex;
}
int buildHuffmanTree(int n) {
for(int i = 0; i < n; i++) {
insertMinHeap(i);
}
while(heapSize > 1) {
int a = extractMin();
int b = extractMin();
freq[total] = freq[a] + freq[b];
left[total] = a;
right[total] = b;
isLeaf[total] = 0;
insertMinHeap(total);
total++;
}
return extractMin();
}
void printCodes(int node,int arr[],int top) {
if(left[node] != -1) {
arr[top] = 0;
printCodes(left[node],arr,top+1);
}
if(right[node] != -1) {
arr[top] = 1;
printCodes(right[node],arr,top+1);
}
if(isLeaf[node] == 1) {
printf("%c: ",data[node]);
for(int i = 0; i < top; i++) {
printf("%d",arr[i]);
}
printf("\n");
}
}
int main() {
int n;
int codes[MAX];
printf("Enter no.of characters: ");
scanf("%d", &n);
for(int i = 0; i < n; i++) {
printf("Enter character%d: ",i+1);
scanf(" %c", &data[i]);
printf("Enter frequency: ");
scanf("%d", &freq[i]);
left[i] = -1;
right[i] = -1;
isLeaf[i] = 1;
}
total = n;
int root = buildHuffmanTree(n);
printf("\nHuffman codes:\n");
printCodes(root,codes,0);
return 0;
}
