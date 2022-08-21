#include <stdio.h>
#include <stdlib.h>

int main(){
	int m,n,g,f;
	int r,s,t,u;
	int x[11] = {};
	int y[11] = {};
	int a[11][11];
	m = n = f = 0;

	scanf("%d %d", &m, &n);

	while(f!=n){
		for(g=0;g<m;g++){
			scanf("%d", &a[m][f]);
			if(a[m][f]==1){
				x[g]++;
				r=m;
				t=f;
			}
		}
		if(a[f][n]==1){
			y[g]++;
			s=f;
			u=n;
		}
	f++;
	}
	printf("Linha com maior quantidade de 1 (%d): %d\n",r, a[r][t]);
	printf("Coluna com maior quantidade de 1 (%d): %d\n", s, a[s][u]);

	return 0;
}