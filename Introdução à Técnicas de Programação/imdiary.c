#include <stdio.h>

typedef struct ent{
	char descricao[105];
	int h1, mi, hf, mf;
} Tarefa;


int main(){
	Tarefa agenda[105];
	int tasks, i;

	scanf("%d", &tasks);

	for(i=0; i<tasks; i++){
		scanf("%d:%d %d:%d", &agenda[i].h1, &agenda[i].mi, &agenda[i].hf, &agenda[i].mf);
		scanf(" %[^\n]s", agenda[i].descricao);  
	}

	return 0;
}
