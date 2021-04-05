


#include <stdio.h>
#define MAX (1000000+10)
typedef long long llong;

int a, b, d, N;

llong dd[MAX];
llong sum[MAX];

void input(){
	scanf("%d %d %d %d", &a, &b, &d, &N);
}

void printA(){
	printf("%d %d %d %d\n", a, b, d, N);
}





int main(){

	input();
	//printA();

	int nn, mm;


	
	 

	// d[i] = sum[i-a] - sum[i-b]
	// sum[i] = sum[i-1] + d[i]


	// sum[i] = sum[i-1] +  sum[i-a] - sum[i-b]

	dd[0] = 1; sum[0] = 1;
#if 0
	int i;
	for (i = 1; i<= N; i++){
		if (i - a >= 0)  dd[i] = sum[i-a];
		if (i - b >= 0)  dd[i] = (dd[i] - sum[i-b] + 1000) % 1000;
		sum[i] = (sum[i - 1] + dd[i]+1000) % 1000;
	
	}

#else

	dd[0] = 1; sum[0] = 1;

	for (nn = 1; nn < a; nn++){
		dd[nn] = 0;	
		sum[nn] = 1;
	}
	for (nn = 1; nn < a; nn++){ 
		dd[nn] = 0;
		sum[nn] = sum[nn-1];
	
	}

	for (nn = a; nn < b; nn++){
		dd[nn] = (sum[nn - a]+1000)%1000;
		sum[nn] = (sum[nn - 1] + dd[nn]+1000)%1000;
	}

	for (nn = b; nn <= N; nn++){
		dd[nn] = (sum[nn - a] - sum[nn - b] + 1000) % 1000;
		sum[nn] = (sum[nn - 1] + dd[nn] + 1000) % 1000;
	}
#endif

	printf("%lld\n", (sum[N]-sum[N-d]+1000)%1000);




}



