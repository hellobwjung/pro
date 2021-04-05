

#include <stdio.h>
#define MAX (300+10)
int N;
int a[MAX];
int d_o[MAX];
int d_e[MAX];
//int d[MAX];
int d[MAX][2];


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
	d[0][0] = 0; // 0 : 안밟고 
	d[0][1] = 0; // 0 : 밟고 

	d[1][0] = a[1]; // 0 : 안밟고 
	d[1][1] = 0; // 0 : 밟고 

	for (nn = 2; nn <= N; nn++){

		d[nn][0] = a[nn] + max(d[nn-2][0], d[nn-2][1]);
		d[nn][1] = a[nn] + d[nn - 1][0];		
	}

	printf("%d\n", max(d[N][0], d[N][1]));
	


}












