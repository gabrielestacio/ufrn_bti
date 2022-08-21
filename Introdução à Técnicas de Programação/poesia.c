#include <stdio.h>

int main(){
	FILE* arquivo;
	char palavra[100];
	int cont = 0;

	arquivo = fopen("poesia.txt", "r");

	if(arquivo == NULL)
		printf("Vixi...\n");
	else{
		while(fscanf(arquivo, " %s", palavra) != EOF){
			switch(palavra[0]){
				case 'A':
				case 'a':
				case 'E':
				case 'e':
				case 'I':
				case 'i':
				case 'O':
				case 'o':
				case 'U':
				case 'u':
					cont++;
					break;
			}
		}

		printf("Existem %d palavras que começam com vogais\n", cont);

		fclose(arquivo);
	}


	return 0;
}