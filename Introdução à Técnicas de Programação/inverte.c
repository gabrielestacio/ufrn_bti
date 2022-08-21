#include <stdio.h>

int main(){

	int num[100];
	int i;

	for(i=0;i<5;i++){
		scanf("%d", &num[i]);
	}

	for(i=4;i>=0;i--){
		printf("%d\n", num[i]);
	}

	return 0;
}