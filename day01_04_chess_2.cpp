

#include <stdio.h>
#define MAX (100+10)
int a[110][110];
int N, M;
int R, C, S, K;
int sol;

typedef struct _Point { int r, c, cnt; } Point;
Point Queue[MAX*MAX];
int rp, wp;
void Enqueue(int r, int c, int cnt){
	Queue[wp].r = r;
	Queue[wp].c = c;
	Queue[wp].cnt = cnt;
	wp++;
}
Point Dequeue(){
	return Queue[rp++];
}



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

void bfs() {

	int i;
	Point out;
	Enqueue(R, C, 0);
	while (wp>rp){

		for (i = 0; i < 8; i++){
			Enqueue(Queue[rp].);
		
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
	printf("%d\n", bfs());
}
