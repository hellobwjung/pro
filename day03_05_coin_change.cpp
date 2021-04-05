


#include <stdio.h>
//#define MAX (10+6)
#define MAX (64000+10)


int sol = 0;
int N;
int W;
int a[MAX];
int d[MAX];

void input(){
	scanf("%d", &N);
	int nn;
	for (nn = 1; nn <= N; nn++){
		scanf("%d", &a[nn]);	
	}
	scanf("%d", &W);


	int mm;
	for (nn = 1; nn < N; nn++){
		for (mm = nn + 1; mm <= N; mm++){
			if (a[nn]>a[mm]){
				int t = a[nn];
				a[nn] = a[mm];
				a[mm] = t;
			}
		}
	}
}

void printA(){
	int nn;
	for (nn = 1; nn <= N; nn++){
		printf("%d ", a[nn]);
	}
	printf("\n%d\n", W);	
}

// d[i] = min(d[i -coin[j]]+1]), i-coin[j]>=0, j: ������ ����

int main(){
	input();
	//printA();
#if 1
	int nn, kk;
	int local_min = 0;
	

	for (nn = 1; nn <= N; nn++) d[a[nn]] = 1;

	int num, rem;
	for (nn = 1; nn <= W; nn++){
		num = nn;

		local_min = 0xfff0000;
		for (kk = 1; kk <= N; kk++){
			rem = num - a[kk];
			if (rem < 0) continue;
			
			if (local_min > d[rem] + 1) local_min  = d[rem]+ 1;
		
		}
		d[nn] = local_min;

	}
#endif

	if (d[W] == 0xfff0000) printf("impossible\n");
	else printf("%d\n", d[W]);



}













