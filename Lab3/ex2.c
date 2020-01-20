#include <stdio.h>
#include <string.h>

int strMatch(char *s, char *p){
	int n = strlen(s);
	int m = strlen(p);
	for(int i=0; i<=n-m; i++){
		int j=0;
		while(j<m && s[i+j]==p[j])
			j++;

		if(j==m) return 1;
	}
	return 0;
}

int main(){
	char str1[] = "Hello";
	char str2[] = "k";

	int ans = strMatch(str1, str2);
	printf("%d\n", ans);
}