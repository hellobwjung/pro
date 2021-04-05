

#include <stdio.h>


int N, W;
int a[1000+10][2];
int weight[1000+10];
int value[1000 + 10];
float value_per_weight[1000+10];
int minw, minw_idx;

int d[10000+10];

void input(){
	scanf("%d %d", &N, &W);
	int nn;
	minw = 0xfff0000;
	for (nn = 1; nn <= N; nn++){
		scanf("%d %d", &weight[nn], &value[nn]);
		if (minw > weight[nn]) { 
			minw = weight[nn]; 
			minw_idx = nn; }
	}
}

void printA(){
	int nn;
	for (nn = 1; nn <= N; nn++){
		printf("%d %d\n", weight[nn], value[nn]);
	}
	printf("\n");
}

int main(){
	input();
	//printA();
	int sol;

	int kk;
	int ww;
	int num, rem;
	int local_max;
	d[minw_idx] = minw;
	for (ww = 1; ww <= W; ww++){

		local_max = 0;
		for (kk = 1; kk <= N; kk++){
			rem = ww - weight[kk];
			if (rem < 0) continue;
			
			if (local_max < d[rem] + value[kk] ) 
				local_max = d[rem] + value[kk];
		}
		d[ww] = local_max;
	}

	printf("%d\n", d[W]);
}



