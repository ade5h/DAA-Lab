#include <stdio.h>

int main(){
	int adjMatrix[20][20];
	int n;
	printf("Enter the number of nodes: \n");
	scanf("%d", &n);

	printf("Enter the contents of the adjacency matrix\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &adjMatrix[i][j]);
		}
	}

	for(int i=0; i<n; i++){
		printf("%c->", ('a'+i));
		for(int j=0; j<n; j++){
			if(adjMatrix[i][j] == 1){
				printf("%c ", ('a'+j));
			}
		}
		printf("\n");
	}
}