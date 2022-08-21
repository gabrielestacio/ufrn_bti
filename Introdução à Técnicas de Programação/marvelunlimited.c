#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hq{
  char titulo[50];
  int num, ano, mes;
  char lido
} quad;

int files(quad hqs[50], int casos){
  int x;

  FILE* banco;
  banco = fopen("hqmarvel.txt", "w+");

  for(x=0;x<casos;x++){
    fprintf(banco, "%s\n", hqs[x]);
  }
  fclose(banco);
  return 0;
}

int main(){
  quad info[50];
  int i, ct;
  char cadst;
  
  scanf("%d", &ct);
  
  for(i=0; i<ct; i++){
    printf("Cadastrar HQ? (S/N)");
    scanf("%c", &cadst);
    scanf(" %[^\n]s", &info[i].titulo);
    scanf("%d %d %d", &info[i].num, &info[i].ano, &info[i].mes);

    files(info[50], ct);
  }

  return 0;
}
