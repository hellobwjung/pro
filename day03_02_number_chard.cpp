

#include <stdio.h>
#define MAX (64)

int a[MAX];
int N;
int d[MAX];

void input(){
	char str[MAX];
	scanf("%s", str);

	N = 0;
	while (str[++N] > 0);
	//printf("N = %d\n", N);

	int nn;
	for (nn = 1; nn <= N; nn++){
		a[nn] = str[nn-1] - '0';
		//printf("%d ", a[nn]);
	}
	//printf("\n");

}




int main(){
	input();


	int nn;
	d[0] = 1;
	d[1] = 1;
	int num;
	for (nn = 2; nn <= N; nn++){
		if (a[nn]>0) d[nn] = d[nn-1];
		num = a[nn - 1] * 10 + a[nn];
		if (a[nn-1] > 0 && num <= 34) d[nn] +=d[nn-2];
		//printf("--> d[%d] = %d \n",nn, d[nn]);
	}
	printf("%d\n", d[N]);
}
