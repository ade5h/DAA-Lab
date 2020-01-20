#include <stdio.h>
int count;

int gcd(int a, int b){
	int t = (a<b ? a : b);
	count = 1;
	while(t >= 1){
		if(a%t == 0 && b%t == 0){
			return t;
		}
		count++;
		t--;
	}
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