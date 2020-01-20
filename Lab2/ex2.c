#include <stdio.h>
int count;

int min(int a, int b){
	return a < b ? a : b;
}

int gcd(int a, int b){
	count = 1;
	int base1[100] = {2};
	int base2[100] = {2};
	int exp1[100] = {0};
	int exp2[100] = {0};

	int index = 0;

	int divisor = 2;

	while(a > 1){
		if(a%divisor == 0){
			if(base1[index] == divisor){
				exp1[index]++;
			}
			else if(base1[index] != divisor){
				base1[++index] = divisor;
				exp1[index]++;
			}
			a /= divisor;
		}
		else{
			divisor++;
		}
		count++;
	}

	int index1 = index;

	divisor = 2;
	index = 0;
	while(b > 1){
		if(b%divisor == 0){
			if(base2[index] == divisor){
				exp2[index]++;
			}
			else if(base2[index] != divisor){
				base2[++index] = divisor;
				exp2[index]++;
			}
			b /= divisor;
		}
		else{
			divisor++;
		}
		count++;
	}
	int index2 = index;
	int gcd = 1;
	int i = 0;
	int j = 0;

	while(i<=index1 && j<=index2){
		if(base1[i] == base2[j]){
			if(min(exp1[i], exp2[j]) == 0){
				i++;
				j++;
			}
			else{
				gcd *= base1[i]*(min(exp1[i], exp2[j]));
				i++;
				j++;
			}
		}
		else if(base1[i] < base2[j]){
			i++;
		}
		else{
			j++;
		}
	}

	return gcd;
}

int main(){
	int a, b;

	printf("M+N\tCount\tGCD\n");
	for(int i=0; i<5; i++){
		scanf("%d %d", &a, &b);
		int ans = gcd(a, b);
		printf("%d\t%d\t%d\n", (a+b), count, ans);
	}

	return 0;
}