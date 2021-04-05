
#include<stdio.h>

#define MAX (500+10)

int N;
int a[MAX][5];

int time_table[24 + 5];

void input(){
	scanf("%d", &N);
	int nn;
	for (nn = 1; nn <= N; nn++){
		scanf("%d %d %d", &a[nn][1], &a[nn][2], &a[nn][3]);
	}
}

void printA(){
	int nn;
	for (nn = 1; nn <= N; nn++){
		printf("%3d %3d %3d\n", a[nn][1], a[nn][2], a[nn][3]);
	}
};

int isEmpty(int s, int e){
	int nn;
	if (s == e && time_table[s] == 1) return 0;
	//for (nn = s; nn <= e; nn++){
	for (nn = s; nn < e; nn++){
		if (time_table[nn] == 1) return 0;
	}
	return 1;
}

void fill_time(int s, int e, int num){
	int nn;
	for (nn = s; nn < e; nn++){
		time_table[nn] = num;
	}
}

void print_time(){
	int nn;
	for (nn = 1; nn <= 24; nn++){
		printf("%3d ", nn);
	}
	printf("\n");
	for (nn = 1; nn <= 24; nn++){
		printf("%3d ", time_table[nn]);
	}
	printf("\n\n");
}


int list[MAX];
int cnt;
void printList(int L){
	printf("%3d ) : ");
	int nn;
	for (nn = 1; nn<L; nn++){
		printf("%d ", list[nn]);
	}
	printf("\n");
}

int sol;

int visit[MAX];
int best[MAX];
void dfs(int L){
	int nn;

	if (sol < L - 1) {
		sol = L - 1;
		for (nn = 1; nn <= sol; nn++) best[nn] = list[nn];
		//printList(L);
	}

	if (L>N){
		//printf("what the.... : ");
		//printList(L);
		return;
	}


	for (nn = 1; nn <= N; nn++){
		if (visit[nn] == 0
			&& isEmpty(a[nn][2], a[nn][3])){
			visit[nn] = 1;
			fill_time(a[nn][2], a[nn][3], 1);
			list[L] = nn;
			dfs(L + 1);
			list[L] = 0;
			fill_time(a[nn][2], a[nn][3], 0);
			visit[nn] = 0;
		}

	}

}

int main(){
	input();
	//  printA();
	//
	//  print_time();
	//  fill_time(3,8,1);
	//
	//  print_time();
	//  fill_time(4,5,0);
	//
	//  print_time();
	////    fill_time(3,5,1);
	//  printf("%d\n", isEmpty(4, 5));

	sol = 0;
	dfs(1);
	printf("%d\n", sol);
	int nn;
	for (nn = 1; nn <= sol; nn++) printf("%d ", best[nn]);
	printf("\n");

}

