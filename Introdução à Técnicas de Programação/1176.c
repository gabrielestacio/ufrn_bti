#include <stdio.h>

int main(){
	int t,i;
	unsigned long long int f[t],a[t];

	scanf("%d", &t);

	for(i=0;i<t;i++){
		scanf("%llu",&f[i]);
		if(f[i]==0){
			f[i] = 0;
		}
		else{
			a[i] = f[i]; 
			f[i] = f[i]-1;
		}
	}
	for(i=0;i<t;i++){
		printf("Fib(%llu) = %llu\n",a[i],f[i]);
	}
}