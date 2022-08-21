#include <stdio.h>
#include <stdlib.h>

int main(){
	int m,n,g,f,d,e,r,s;
	int x[m];
	int y[m];
	int a[m][n];
	int u,z;
	u = z = m = n = f = d = e = r = s = 0;

	scanf("%d %d", &m, &n);

	for (g=0;g<n;g++){
		for(g=0;g<m;g++){
			scanf("%d", &a[m][f]);		
			switch(a[m][f]){
				case 1: x[m]++; break;
			}
			if(g!=0){
				if(a[m][f]>a[m-1][f]){
					d=m;
					r=n;
				}
			}
		}
		if(a[f][n]==1){
			y[m]++;
		}
		if(g!=0){
			if(a[f][n]>a[f][n-1]){
				e=n;
				s=m;
			}
		}
		f++;
	}
	printf("Linha com maior quantidade de 1 (%d): %d",d, a[d][r]);
	printf("Coluna com maior quantidade de 1 (%d): %d", e, a[s][e]);

	return 0;
}