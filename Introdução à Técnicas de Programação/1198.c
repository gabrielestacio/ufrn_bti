#include <stdio.h>
#include <stdlib.h>

int main(){
	long long int h,o;

	while(scanf("%Ld %Ld", &h,&o) != EOF){
		h>o ? printf("%Ld\n", h-o) : printf("%Ld\n", o-h);
	}
	return 0;
}