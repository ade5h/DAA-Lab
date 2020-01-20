#include <stdio.h>
int count;

void bubbleSort(int* a, int n){
	count = 0;
	for(int i=0; i<n-1; i++){
		int swap = 0;
		for(int j=0; j<n-i-1; j++){
			count++;
			if(a[j] > a[j+1]){
				int temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
				swap = 1;
			}
		}
		if(swap == 0) return;
	}
}

int main(){
	printf("N\tCount\n");
	for(int i=0; i<4; i++){
		int n;
		scanf("%d", &n);
		int a[100];

		for(int i=0; i<n; i++){
			scanf("%d ", &a[i]);
		}

		bubbleSort(a, n);

		printf("%d\t%d\n", n, count);
	}
}