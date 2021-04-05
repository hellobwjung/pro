

#include <stdio.h>
#define MAX (300+10)
int N;
int a[MAX];
int d[MAX];


void input(){

	scanf("%d", &N);
	int nn;
	for (nn = 1; nn <= N; nn++){
		scanf("%d", &a[nn]);
	}
}

int max(int a, int b){
	return a > b ? a : b;
}
int main(){

	input();


	int nn; 
	d[1] = 10;
	int num0, num1;

	for (nn = 2; nn <= N; nn++){
		num0 = a[nn] + d[nn - 2];
		num1 = a[nn] + a[nn-1] + d[nn - 3];
		

		d[nn] = max(num0, num1);
	}

	printf("%d\n", d[N]);



}












