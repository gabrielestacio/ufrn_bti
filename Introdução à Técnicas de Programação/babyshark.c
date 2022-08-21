/**/

#include <stdio.h>

int main(){

	int f,i,n,e;
	int ap[15] = {0};
	i = f = e = 0;

	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d", &f);

		if(ap[f] == 0){
			e++;
			ap[f] = 1;
		}
	}

	printf("%d espécies diferentes.\n", e);

	for(i=1;i<=14;i++){
		if(ap[i] == 1){
			switch(i){
				case 1: printf("Tubarão Branco"); break;
				case 2: printf("Tubarão Martelo"); break;
				case 3: printf("Tubarão Touro"); break;
				case 4: printf("Tubarão Baleia"); break;
				case 5: printf("Tubarão Lixa"); break;
				case 6: printf("Tubarão Frade"); break;
				case 7: printf("Tubarão Tigre"); break;
				case 8: printf("Tubarão Cabeça-chata"); break;
				case 9: printf("Tubarão Serra"); break;
				case 10: printf("Tubarão de Pontas Negras"); break;
				case 11: printf("Tubarão Raposa"); break;
				case 12: printf("Tubarão Mako"); break;
				case 13: printf("Tubarão Bruxa"); break;
				case 14: printf("Tubarão Azul"); break;				
			}
			printf("\n");
		}
	}
	return 0;
}