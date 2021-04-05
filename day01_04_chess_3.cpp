

#include <stdio.h>
#define MAX (100+10)
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

int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};

void dfs(int L, int yy, int xx) {

	if (L >= sol) return;

	if (L > N/2 || L > M/2){
		return;
	}

	int nn;
	int ny, nx;
	for (nn = 1; nn <= 8; nn++){

		ny = yy + dy[nn];
		nx = xx + dx[nn];
		if (ny<1 || nx<1 || ny>N || nx>M) continue;

	
		if (ny == S && nx == K) {
			if (sol > L) { 
				sol = L; 
				////printf("sol ==> %d\n", sol);
				list[L].y = ny;
				list[L].x = nx;
				//printList(L+1);
				return;
			}
		}
		else {
			list[L].y = ny;
			list[L].x = nx;
			dfs(L+1, ny, nx);
			list[L].y = 0;
			list[L].x = 0;
		}
	
	}

}

int main(){

	input();

	sol = 0xfff7777;
	list[0].y = R; 
	list[0].x = C;

	dfs(1, R, C);
	printf("%d\n", sol);
}
