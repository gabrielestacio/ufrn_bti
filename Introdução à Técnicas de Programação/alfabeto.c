#include <stdio.h>

int main(){
	char letra;

	scanf("%c", &letra);

	while(letra!='\n'){
		printf("%c", letra-32);
		scanf("%c", &letra);
	}

	printf("\n");

	return 0;
}