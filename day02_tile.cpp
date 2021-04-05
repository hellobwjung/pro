

#include <stdio.h>

#define MAX (100000+20)
#define DIVIDER (20100529)


typedef long long llong;

llong d[MAX];

llong sol;

int N;


int main(){

	scanf("%d", &N); 

	d[1] = 1;
	d[2] = 3;

	int nn;
	for (nn = 3; nn <= N; nn++){
		d[nn] = d[nn - 2] * 2 + d[nn-1];
	}

	printf("%lld\n", d[N]%DIVIDER);



}

