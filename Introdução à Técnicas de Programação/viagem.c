#include <stdio.h>

int main(){
	int n,i,cont,pv,altm;
	int c,t,a;
	int cid[10005] = {};
	cont = altm = 0;

	scanf("%d", &n);

	for(i=0;i<n;i++){
		scanf("%d %d %d",&c,&t,&a);
		if(i==0){
			pv=c;
		}
		if(pv>c){
			pv=c;
		}
		while(cid[c]!=cid[t]){
			if(a>cid[c+cont]){
				cid[c+cont]=a;
			}
			cont++;
		}
	}
	
	printf("%d ", pv);
	for(i=0; i<(n*3); i++){
		if(altm!=cid[i]){
			printf(" %d %d ", i, cid[i]);
			altm = cid[i];
		}
	} 
	printf("0");

	return 0;
}