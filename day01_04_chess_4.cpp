

#include <stdio.h>
#define MAX (100+10)
int a[110][110];
int N, M;
int R, C, S, K;
int sol;

typedef struct _Point { int y, x; } Point;
Point list[MAX];
int cnt;
void printList(int L){
	printf("%2d ) : ", ++cnt);
	int nn;
	for (nn = 0; nn < L; nn++){
		printf("(%2d, %2d), ", list[nn].y, list[nn].x);
	}
	printf("\n");
}

void input(){
	scanf("%d %d", &N, &M);
	scanf("%d %d", &R, &C);
	scanf("%d %d", &S, &K);

	//printf("size   : %d, %d\n", N, M);
	//printf("start  : %d, %d\n", R, C);
	//printf("finish : %d, %d\n", S, K);
}

int dr[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dc[] = { -2, -1, 1, 2, 2, 1, -1, -2 };

void dfs(int rr, int cc, int cnt) {

	if (rr<1 || cc<1 || rr>N || cc>M) return;
	if (cnt >= a[rr][cc] || cnt >= a[S][K]) return;
	a[rr][cc] = cnt;

	int nn;
	int nr, nc;
	for (nn = 0; nn < 8; nn++){
		nr = rr + dr[nn];
		nc = cc + dc[nn];
		dfs(nr, nc, cnt + 1);
	}

}

int main(){

	input();
	int yy, xx;
	for (yy = 1; yy <= N; yy++){
		for (xx = 1; xx <= M; xx++){
			a[yy][xx] = 123456789;
		}
	}

	dfs(R, C, 0);
	printf("%d\n", a[S][K]);
}
