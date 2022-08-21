
#include <stdio.h>
#include <string.h>

int main()
{
    char a[1000], b[1000], soma[1000];
    int i, j, k, tama, tamb, tams, aux=0, ai, bi, s;
    
    printf("Digite um numero:\n");
    scanf("%1000s%*c", a);
    printf("\nDigite um sequndo numero:\n");
    scanf("%1000s%*c", b);
    
    tama = strlen(a);
    tamb = strlen(b);
    //Tamanho da soma é 1 a mais que o maior número entre tamanho de a e de b:
    tams = (tama > tamb ? tama : tamb) + 1;
    
    soma[tams] = '\0'; //Fim da string soma
    for(i=tama-1, j=tamb-1, k=tams-1; k >= 0; i--, j--, k--){
        ai = i >= 0 ? a[i] - '0' : 0; //Se ainda está dentro do vetor converte o
        bi = j >= 0 ? b[j] - '0' : 0; //caractere para inteiro, senão guarda 0.
        s = ai + bi + aux; //Soma
        soma[k] = s % 10 + '0'; //Guarda apenas 1 digito como caractere
        aux = s / 10; //Carrega o que sobrou para somar no próximo ciclo
    }
    
    //Elimina o zero à esquerda da soma, se o último aux não carregou nada:
    if(soma[0] == '0'){
        for(i=0; soma[i]; i++){ //move todos os caracteres 1 posição
            soma[i] = soma[i+1];
        }
    }

    printf("\nSoma: \n%s\n", soma);
    
    return 0;
}
_____________________________________________________________________________________________________
#include <stdio.h>
#include <string.h>

int main(){
    char num1[1000], num2[1000], result[1000];
    int op, i, tnum1, tnum2, tfinal;
    i = 0;

    scanf("%c %c", &num1, &num2);
    printf("Adição = a \n Subtração = s \n Divisão = d \n Produto = p");
    scanf("%d", op);

    tnum1 = strlen(num1);
    tnum2 = strlen(num2);

    if(op == 'a'){
        while(num1[i]!='\n'){
                result[i] = num1[i] + num2[i];
                if(result[i] > 10){
                
                }
            i++;   
        }
    }
    else if(op == 's'){
        
    }
    else if(op == 'd'){
        
    }
    else if(op == 'p'){

    }
    else{
        print("Operação inválida.");
    }

    return 0;
}
