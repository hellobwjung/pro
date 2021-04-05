

#include<stdio.h>
#define MAX (40+5)

int a[MAX];
int b[MAX];
int f[MAX];
int M, N;

int d[MAX];
int e[MAX];

void input(){
	scanf("%d", &N);
	scanf("%d", &M);
	int mm;
	int num;
	for (mm = 1; mm <= M; mm++){
		scanf("%d", &num);
		b[mm] = num;
		//printf("---> %d\n", num);
		f[num] = 1;
	}
	b[0] = 0;
	b[M+1] = N+1;
	f[0] = 1;

}


int main(){
	input();

	int nn;
	d[1] = 1;
	d[2] = 2;
	d[3] = 3;
	for (nn = 4; nn <= N; nn++){
		d[nn] = d[nn - 1] + d[nn-2];	
	}

	int sol = 1;
	int local=0;
	int mm = 0;
	int sz=0;
	if (M == 0) sol = d[N];
	else if (N == M) sol = 1;
	else{
		for (mm = 1; mm <= M+1; mm++){
			sz = b[mm] - b[mm-1]-1;
			if (d[sz]>0)	sol *= d[sz];
			//printf("d[%d] = %d, sol = %d\n", sz, d[sz], sol);
		}
	}
	printf("%d\n", sol);

}



