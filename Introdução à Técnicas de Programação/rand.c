#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int a;

	srand(time(NULL));

	for(a=0;a<10;a++)
		printf("%d\n", rand()%10+1);

	return 0;
}