#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bombaglobal;

void carrega_matriz(int campo[10][10]){
	int x, y, z = 1;

	for(y=0; y<10; y++){
		for(x=0; x<10; x++){
			campo[x][y] = z;
			z++;
		}
	}
}

void imprime_matriz(int ncampo[10][10]){
	int a,b;

	for(b=0; b<10; b++){
		for(a=0; a<10; a++){
			if(((ncampo[a][b]) < 10))
				printf(" %d ", ncampo[a][b]);
			else if((ncampo[a][b]) >= 10 && (ncampo[a][b]) < 100)
				printf("%d ", ncampo[a][b]);
			else if((ncampo[a][b] == 100))
				printf("%d", ncampo[a][b]);
			else if((ncampo[a][b] == 101))
				printf(" N ");
			else if((ncampo[a][b] == 201))
				printf(" B ");

		}
		printf("\n");
	}
}

int tem_bomba(int bomba, int tembomba[10]){
	int res = 0, i;

	for(i=0; i<9; i++){
		if(tembomba[i] == bomba)
			res = 1;
	}
	return res;
}

void explode(int simucampo[10][10], int bomb, int vet_bomb[10]){
	if ((bomb <= 10) && (tem_bomba(bomb, vet_bomb))){ //se o valor escolhido pelo usuario for menor ou igual a 10, E nesse lugar existir uma bomba...
		simucampo[(bomb-1)][0] = 201; //se tiver bomba, muda o valor da casa para 201, que na impressao sera mudado para B
		glo_bomb++; //incrementa o contador de bombas encontradas
	}
	else if ((bomb <= 10) && !(tem_bomba(bomb, vet_bomb))){ //se o valor escolhido pelo usuario for menor ou igual a 10, E nesse lugar NAO existir uma bomba...
		simucampo[(bomb-1)][0] = 101; //se NAO tiver bomba, muda o valor da casa para 101, que na impressao sera mudado para N
		if(bomb == 1){ ////transforma em N os valores em volta, caso neles NAO exista bomba, para o canto da esquerda
                if(!(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         simucampo[1][0] = 101;
                         simucampo[0][1] = 101;
                         simucampo[1][1] = 101;
                }
        }
        else if(bomb == 10){ //transforma em N os valores em volta, caso neles NAO exista bomba, para o canto da direita
             if(!(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb))){
                         simucampo[8][0] = 101;
                         simucampo[8][1] = 101;
                         simucampo[9][1] = 101;
             }
        }
        else{ ////transforma em N os valores em volta, caso neles NAO exista bomba, para todos outros entre 2 e 9
             if(!(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         simucampo[(bomb-2)][0] = 101;
                         simucampo[bomb][0] = 101;
                         simucampo[(bomb-2)][1] = 101;
                         simucampo[(bomb-1)][1] = 101;
                         simucampo[bomb][1] = 101;
             }
        }
	else if ((bomb >= 11) && (bomb <= 20) && (tem_bomba(bomb, vet_bomb))){
		simucampo[(bomb-11)][1] = 201;
		bombaglobal++;
	}
	else if ((bomb >= 11) && (bomb <= 20) && !(tem_bomba(bomb, vet_bomb))){
		mat3[(bomb-11)][1] = 101;
		if(bomb == 11){
                if(!(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         simucampo[0][0] = 101;
                         simucampo[1][0] = 101;
                         simucampo[1][1] = 101;
                         simucampo[0][2] = 101;
                         simucampo[1][2] = 101;
		}
		}
        }
        else if(bomb == 20){
             if(!(tem_bomba((bomb-11), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb))){
                         simucampo[8][0] = 101;
                         simucampo[9][0] = 101;
                         simucampo[8][1] = 101;
                         simucampo[8][2] = 101;
                         simucampo[9][2] = 101;
             }
        }
        else{
             if(!(tem_bomba((bomb-11), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         simucampo[(bomb-12)][0] = 101;
                         simucampo[(bomb-11)][0] = 101;
                         simucampo[(bomb-10)][0] = 101;
                         simucampo[(bomb-12)][1] = 101;
                         simucampo[(bomb-10)][1] = 101;
                         simucampo[(bomb-12)][2] = 101;
                         simucampo[(bomb-11)][2] = 101;
                         simucampo[(bomb-10)][2] = 101;
	     }
        }
	else if ((bomb >= 21) && (bomb <= 30) && (tem_bomba(bomb, vet_bomb))){
		simucampo[(bomb-21)][2] = 201;
		bombaglobal++;
	}
	else if ((bomb >= 21) && (bomb <= 30)  && !(tem_bomba(bomb, vet_bomb))){
		simucampo[(bomb-21)][2] = 101;
		if(bomb == 21){
                if(!(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         simucampo[0][1] = 101;
                         simucampo[1][1] = 101;
                         simucampo[1][2] = 101;
                         simucampo[0][3] = 101;
                         simucampo[1][3] = 101;
		}
		}
        }
        else if(bomb == 30){
             if(!(tem_bomba((bomb-11), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb))){
                         simucampo[8][1] = 101;
                         simucampo[9][1] = 101;
                         simucampo[8][2] = 101;
                         simucampo[8][3] = 101;
                         simucampo[9][3] = 101;
              }
        }
        else{
             if(!(tem_bomba((bomb-11), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         simucampo[(bomb-22)][1] = 101;
                         simucampo[(bomb-21)][1] = 101;
                         simucampo[(bomb-20)][1] = 101;
                         simucampo[(bomb-22)][2] = 101;
                         simucampo[(bomb-20)][2] = 101;
                         simucampo[(bomb-22)][3] = 101;
                         simucampo[(bomb-21)][3] = 101;
                         simucampo[(bomb-20)][3] = 101;
             }
        }
	else if ((bomb >= 31) && (bomb <= 40) && (tem_bomba(bomb, vet_bomb))){
		simucampo[(bomb-31)][3] = 201;
		bombaglobal++;
	}
	else if ((bomb >= 31) && (bomb <= 40) && !(tem_bomba(bomb, vet_bomb))){
		simucampo[(bomb-31)][3] = 101;
		if(bomb == 31){
                if(!(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         simucampo[0][2] = 101;
                         simucampo[1][2] = 101;
                         simucampo[1][3] = 101;
                         simucampo[0][4] = 101;
                         simucampo[1][4] = 101;
		}
		}
        }
        else if(bomb == 40){
             if(!(tem_bomba((bomb-11), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb))){
                         simucampo[8][2] = 101;
                         simucampo[9][2] = 101;
                         simucampo[8][3] = 101;
                         simucampo[8][4] = 101;
                         simucampo[9][4] = 101;
             }
        }
        else{
             if(!(tem_bomba((bomb-11), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         simucampo[(bomb-32)][2] = 101;
                         simucampo[(bomb-31)][2] = 101;
                         simucampo[(bomb-30)][2] = 101;
                         simucampo[(bomb-32)][3] = 101;
                         simucampo[(bomb-30)][3] = 101;
                         simucampo[(bomb-32)][4] = 101;
                         simucampo[(bomb-31)][4] = 101;
                         simucampo[(bomb-30)][4] = 101;
             }
        }
	else if ((bomb >= 41) && (bomb <= 50) && (tem_bomba(bomb, vet_bomb))){
		simucampo[(bomb-41)][4] = 201;
		bombaglobal++;
	}
	else if ((bomb >= 41) && (bomb <= 50) && !(tem_bomba(bomb, vet_bomb))){
		simucampo[(bomb-41)][4] = 101;
		if(bomb == 41){
                if(!(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         simucampo[0][3] = 101;
                         simucampo[1][3] = 101;
                         simucampo[1][4] = 101;
                         simucampo[0][5] = 101;
                         simucampo[1][5] = 101;
		}
		}
        }
        else if(bomb == 50){
             if(!(tem_bomba((bomb-11), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb))){
                         simucampo[8][3] = 101;
                         simucampo[9][3] = 101;
                         simucampo[8][4] = 101;
                         simucampo[8][5] = 101;
                         simucampo[9][5] = 101;
             }
        }
        else{
             if(!(tem_bomba((bomb-11), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         simucampo[(bomb-42)][3] = 101;
                         simucampo[(bomb-41)][3] = 101;
                         simucampo[(bomb-40)][3] = 101;
                         simucampo[(bomb-42)][4] = 101;
                         simucampo[(bomb-40)][4] = 101;
                         simucampo[(bomb-42)][5] = 101;
                         simucampo[(bomb-41)][5] = 101;
                         simucampo[(bomb-40)][5] = 101;
	     }
        }
	else if ((bomb >= 51) && (bomb <= 60) && (tem_bomba(bomb, vet_bomb))){
		simucampo[(bomb-51)][5] = 201;
		bombaglobal++;
	}
	else if ((bomb >= 51) && (bomb <= 60) && !(tem_bomba(bomb, vet_bomb))){
		simucampo[(bomb-51)][5] = 101;
		if(bomb == 51){
                if(!(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         simucampo[0][4] = 101;
                         simucampo[1][4] = 101;
                         simucampo[1][5] = 101;
                         simucampo[0][6] = 101;
                         simucampo[1][6] = 101;
		}
		}
        }
        else if(bomb == 60){
             if(!(tem_bomba((bomb-11), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb))){
                         simucampo[8][4] = 101;
                         simucampo[9][4] = 101;
                         simucampo[8][5] = 101;
                         simucampo[8][6] = 101;
                         simucampo[9][6] = 101;
             }
        }
        else{
             if(!(tem_bomba((bomb-11), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         simucampo[(bomb-52)][4] = 101;
                         simucampo[(bomb-51)][4] = 101;
                         simucampo[(bomb-50)][4] = 101;
                         simucampo[(bomb-52)][5] = 101;
                         simucampo[(bomb-50)][5] = 101;
                         simucampo[(bomb-52)][6] = 101;
                         simucampo[(bomb-51)][6] = 101;
                         simucampo[(bomb-50)][6] = 101;
             }
        }
	else if ((bomb >= 61) && (bomb <= 70) && (tem_bomba(bomb, vet_bomb))){
		simucampo[(bomb-61)][6] = 201;
		bombaglobal++;
	}
	else if ((bomb >= 61) && (bomb <= 70) && !(tem_bomba(bomb, vet_bomb))){
		simucampo[(bomb-61)][6] = 101;
		if(bomb == 61){
                if(!(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         simucampo[0][5] = 101;
                         simucampo[1][5] = 101;
                         simucampo[1][6] = 101;
                         simucampo[0][7] = 101;
                         simucampo[1][7] = 101;
		}
		}
        }
        else if(bomb == 70){
             if(!(tem_bomba((bomb-11), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb))){
                         simucampo[8][5] = 101;
                         simucampo[9][5] = 101;
                         simucampo[8][6] = 101;
                         simucampo[8][7] = 101;
                         simucampo[9][7] = 101;
             }
        }
        else{
             if(!(tem_bomba((bomb-11), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         simucampo[(bomb-62)][5] = 101;
                         simucampo[(bomb-61)][5] = 101;
                         simucampo[(bomb-60)][5] = 101;
                         simucampo[(bomb-62)][6] = 101;
                         simucampo[(bomb-60)][6] = 101;
                         simucampo[(bomb-62)][7] = 101;
                         simucampo[(bomb-61)][7] = 101;
                         simucampo[(bomb-60)][7] = 101;
             }
        }
	else if ((bomb >= 71) && (bomb <= 80) && (tem_bomba(bomb, vet_bomb))){
		simucampo[(bomb-71)][7] = 201;
		bombaglobal++;
	}
	else if ((bomb >= 71) && (bomb <= 80) && !(tem_bomba(bomb, vet_bomb))){
		simucampo[(bomb-71)][7] = 101;
		if(bomb == 71){
                if(!(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         simucampo[0][6] = 101;
                         simucampo[1][6] = 101;
                         simucampo[1][7] = 101;
                         simucampo[0][8] = 101;
                         simucampo[1][8] = 101;
		}
		}
        }
        else if(bomb == 80){
             if(!(tem_bomba((bomb-11), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb))){
                         simucampo[8][6] = 101;
                         simucampo[9][6] = 101;
                         simucampo[8][7] = 101;
                         simucampo[8][8] = 101;
                         simucampo[9][8] = 101;
             }
        }
        else{
             if(!(tem_bomba((bomb-11), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         simucampo[(bomb-72)][6] = 101;
                         simucampo[(bomb-71)][6] = 101;
                         simucampo[(bomb-70)][6] = 101;
                         simucampo[(bomb-72)][7] = 101;
                         simucampo[(bomb-70)][7] = 101;
                         simucampo[(bomb-72)][8] = 101;
                         simucampo[(bomb-71)][8] = 101;
                         simucampo[(bomb-70)][8] = 101;
             }
        }
	else if ((bomb >= 81) && (bomb <= 90) && (tem_bomba(bomb, vet_bomb))){
		simucampo[(bomb-81)][8] = 201;
		bombaglobal++;
	}
	else if ((bomb >= 81) && (bomb <= 90) && !(tem_bomba(bomb, vet_bomb))){
		simucampo[(bomb-81)][8] = 101;
		if(bomb == 81){
                if(!(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         simucampo[0][7] = 101;
                         simucampo[1][7] = 101;
                         simucampo[1][8] = 101;
                         simucampo[0][9] = 101;
                         simucampo[1][9] = 101;
		}
		}
        }
        else if(bomb == 90){
             if(!(tem_bomba((bomb-11), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb))){
                         simucampo[8][7] = 101;
                         simucampo[9][7] = 101;
                         simucampo[8][8] = 101;
                         simucampo[8][9] = 101;
                         simucampo[9][9] = 101;
             }
        }
        else{
             if(!(tem_bomba((bomb-11), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         simucampo[(bomb-82)][7] = 101;
                         simucampo[(bomb-81)][7] = 101;
                         simucampo[(bomb-80)][7] = 101;
                         simucampo[(bomb-82)][8] = 101;
                         simucampo[(bomb-80)][8] = 101;
                         simucampo[(bomb-82)][9] = 101;
                         simucampo[(bomb-81)][9] = 101;
                         simucampo[(bomb-80)][9] = 101;
             }
        }
	else if ((bomb >= 91) && (bomb <= 100) && (tem_bomba(bomb, vet_bomb))){
		simucampo[(bomb-91)][9] = 201;
		bombaglobal++;
	}
	else if ((bomb >= 91) && (bomb <= 100) && !(tem_bomba(bomb, vet_bomb))){
		simucampo[(bomb-91)][9] = 101;
		if(bomb == 91){
                if(!(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb))){
                         simucampo[1][9] = 101;
                         simucampo[0][8] = 101;
                         simucampo[1][8] = 101;
		}
		}
        }
        else if(bomb == 100){
             if(!(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-11), vet_bomb))){
                         simucampo[8][9] = 101;
                         simucampo[8][8] = 101;
                         simucampo[9][8] = 101;
             }
        }
        else{
             if(!(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-11), vet_bomb))){
                         simucampo[(bomb-92)][9] = 101;
                         simucampo[bomb-90][9] = 101;
                         simucampo[(bomb-92)][8] = 101;
                         simucampo[(bomb-91)][8] = 101;
                         simucampo[bomb-90][8] = 101;
             }
        }
}


int main(){
	int cm[10][10];
	int jogar, bombas, i, tenta = 1;
	int vetor_bombas[10];

	printf("Bem-vindo ao jogo de Campo Minado em C\n\n\n");
	printf("O que voce deseja?\n\n1 - Jogar\n2 - Sair\n\n");
	scanf("%d", &jogar);

	if(op == 2){
		exit(1);
	}
	else{
		system("cls"); // Limpa a tela 

		// Vai iniciar e criar o vetor de valores aleatorios de onde serao colocadas as bombas
		srand(time(NULL));
		for(i=0; i<10; i++){
			vetor_bombas[i] = 1 + rand() % (100 - 1);
		}

		carrega_matriz(cm); // Carrega a matriz original
		bombaglobal = 0;
		printf("Intrucoes de Jogo:\n\n");
		printf("\tVoce devera escolher um numero de 1 a 100 para desarmar as bombas.\n\tExistem 10 bombas espalhadas pelo cenario. Caso voce escolha um \n\tnumero de onde se encontra uma bomba, aparecera o simbolo B no lugar.\n\tCaso voce escolha um numero de onde nao ha bomba, \n\taparecera o simbolo N.\n\tO objetivo do jogo é encontrar as 10 bombas em ate 35 tentativas.\n\n\tUpdate: Simulando um jogo real de Campo Minado, caso voce escolha \n\tum valor que nao exista bomba e que em todos ao redor deles tambem \n\tnao exista bomba, todos sao trocados por N.\n\n\n");
		printf("Esta pronto para comecar o jogo?\n\n1 - Jogar\n2 - Sair\n\n");
		scanf("%d", &op);

		if(op == 2){
			exit(1);
		}
		else{
			while((tenta <= 36) && (bombaglobal <= 9)){
				system("cls"); // Limpa a tela 
				imprime_matriz(cm); // Imprime a matriz, ja com as alteracoes
				printf("\n\n\n");
				if(tenta < 36)
					printf("Tentativa: %da\tBombas encontradas: %d\n\n\n\n", tenta, bombaglobal);
				else if (tenta == 36){
					printf("Tentativa: %da\tBombas encontradas: %d\n\n\n\n", (tenta-1), bombaglobal);
					break;
				}
				printf("Qual numero voce deseja explodir?\n");
				scanf("%d", &bombas);
				explode(cm, bombas, vetor_bombas); // Manda a matriz, o valor escolhido e o vetor de bombas para verificar se era um B ou um N
				tenta++;
			}
			if(bombaglobal <=9)
				printf("Que pena, voce nao conseguiu. Tente de novo!\n\n");
			else if(bombaglobal==10)
				printf("Parabens! voce conseguiu!\n\n");
		}
	}
	return 0;
}
