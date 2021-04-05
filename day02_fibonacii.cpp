

#include<stdio.h>

long long d[50] = {0, 1, 1};


int main(){

	int n;
	scanf("%d", &n);

	int i;
	for (i = 3; i <= n; i++) d[i] = d[i - 2] + d[i-1];


	printf("%lld\n", d[n]);

	return 0;
}
