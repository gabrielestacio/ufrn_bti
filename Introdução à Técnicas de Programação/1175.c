#include <stdio.h>

int main(){
	int n[20] = {0};
	int i,a;

	a=19;

	for(i=0;i<20;i++){
		scanf("%d", &n[i+a]);
		a=a-2;
	}
	/*for(i=0;i<20;i++){
		n[20] = n[i+a];
		n[i+a] = n[i];
		n[i] = n[20];
		a=a-2;
	}*/	
	for(i=0;i<20;i++){
		printf("N[%d] = %d\n", i, n[i]);
	}
	return 0;
}