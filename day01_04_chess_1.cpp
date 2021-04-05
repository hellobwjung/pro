

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

int rr[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int cc[] = { -2, -1, 1, 2, 2, 1, -1, -2 };

void bfs_scan() {

	int level, i, j, l;
	int nr, nc;

	for (level = 0;; level++){
		for (i = 1; i <= N; i++){
			for (j = 1; j <= M; j++){

				if (a[i][j] == level){

					for (l = 0; l < 8; l++){
						nr = i + rr[l];
						nc = j + cc[l];

						if (nr<1 || nr>N || nc <1 || nc>M || a[nr][nc] < level) continue;
						//a[nr][nc] = Min(a[nr][nc], level+1);
						a[nr][nc] = level + 1;
						if (nr == S && nc == K) return;
					}				
					
				}
			}
		}	
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

	a[R][C] = 0;
	bfs_scan();
	printf("%d\n", a[S][K]);
}
