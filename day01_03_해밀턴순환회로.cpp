

#include<stdio.h>
#define MAX (12+3)

int N;
int a[MAX][MAX];
int sol;

int best[MAX];
int list[MAX];
int cnt;
void printList(int L, int S){
	printf("%2d) : ", ++cnt);
	int nn;
	for (nn = 1; nn < L; nn++){
		printf("%d ", list[nn]);	
	}
	printf(", %d\n", S);
	printf("\n");
}


void input(){
	scanf("%d", &N);
	int xx, yy;
	for (yy = 1; yy <= N; yy++){
		for (xx = 1; xx <= N; xx++){
			scanf("%d", &a[yy][xx]);		
		}
	}
}

void printA(){
	
	int xx, yy;
	for (yy = 1; yy <= N; yy++){
		for (xx = 1; xx <= N; xx++){
			printf("%3d ", a[yy][xx]);
		}
		printf("\n");
	}
	printf("\n");

}

int visit[MAX];
void dfs(int L, int sp, int S){
	if (S >= sol) return;

	if (L>=N){
		S = S + a[sp][1];
		if (a[sp][1] && S < sol){
			sol = S;
			//printList(L, sol);
			return;
			
		}


		/*
		S = S + a[sp][1];
		if (S < sol) {
			sol = S;
			printList(L, sol);
		}*/
		//printList(L, S);
		return;
	}

	int nn;
	for (nn = 2; nn <= N; nn++){
		if (visit[nn] == 0 && a[sp][nn]>0){
			visit[nn] = 1;
			list[L] = nn;
			dfs(L+1, nn, S+a[sp][nn]);
			list[L] = 0;
			visit[nn] = 0;		
		}
	
	}

}

int main(){

	input();
	//printA();

	//visit[1] = 1;
	sol = 0xfff7777;
	dfs(1, 1, 0);

	printf("%d\n", sol);
	//printf("%d", a[3][4]);

}











