#include <stdio.h>
#include <math.h>

int partition(int* a, int n){
	int total = pow(2,n);
	int sum = 0;

	int a1[100], a2[100];
	int i1 = 0;
	int i2 = 0;

	for(int i=0; i<n; i++){
		sum += a[i];
	}

	for(int i=0; i<total; i++){
		int sum1 = 0;
		for(int j=0; j<n; j++){

            if (i & (1<<j)) 
                sum1 += a[j]; 
		}
		int sum2 = sum - sum1;

		if(sum1 == sum2){
			for(int j=0; j<n; j++){
            	if (i & (1<<j))
            		a1[i1++] = a[j];
            	else
            		a2[i2++] = a[j];
			}
			printf("Partition 1: ");
			for(int k=0; k<i1; k++){
				printf("%d ",a1[k]);
			}
			printf("\nPartition 2: ");
			for(int k=0; k<i2; k++){
				printf("%d ",a2[k]);
			}
			printf("\n");

			return 1;
		}
	}
	return 0;
}

int main(){
	int a[] = {2,3,5};
	int n = 3;

	int ans = partition(a, n);

	if(ans == 0) printf("Cannot be partitioned!\n");
}