

#include <stdio.h>
#define MAX (100+10)

int M, N;
int a[MAX][MAX], sr, sc, sd, er, ec, ed;
int sol;

typedef enum _Dir{
	EAST = 1,
	WEST,
	SOUTH,
	NORTH,
} Dir;

typedef struct _Point {
	int y, x;
	int d;
	int dir;
	int cnt;
} Point;
Point Queue[40040];
int fr, re;

int wp, rp;
void Enqueue(int sy, int sx, Dir dir){
	Queue[wp].y = sy;
	Queue[wp].x = sx;
	Queue[wp].dir = dir;
	wp++;
}
Point Dequeue(){
	return Queue[rp++];
}


Point startP, endP;

void input(){
	scanf("%d %d", &M, &N);
	int nn, mm;
	for (nn = 1; nn <= N; nn++){
		for (mm = 1; mm <= M; mm++){
			scanf("%d", &a[nn][mm]);
		}
	}

	scanf("%d %d %d", &startP.y, &startP.x, &startP.dir);
	scanf("%d %d %d", &endP.y, &endP.x, &endP.dir);

}

void printA(){
	int nn, mm;
	for (nn = 1; nn <= N; nn++){
		for (mm = 1; mm <= M; mm++){
			printf("%2d ", a[nn][mm]);
		}
		printf("\n");
	}

	printf("%d %d %d\n", startP.y, startP.x, startP.dir);
	printf("%d %d %d\n", endP.y, endP.x, endP.dir);
	printf("\n");
}

/*
int dy[] = {0, 0, 1, -1};
int dx[] = { 1, -1, 0, 0};
*/

int dr[] = {0, 0, 0, 1, }

int bfs(){

	data tmp;
	int nr nc;
	enq(sr, sc, sd, 0);

	for (r = 0; fr < re; fr++){

		tmp = Q[fr];
		if (tmp.d < 3){
			enq(tmp.r, tmp.c, 3, tmp.cnt+1);
			enq(tmp.r, tmp.c, 4, tmp.cnt + 1);
		}
		else {
			enq(tmp.r, tmp.c, 1, tmp.cnt + 1);
			enq(tmp.r, tmp.c, 2, tmp.cnt + 1);
		}

		for (i = 1; i <= 3; i++){
			nr = tmp.r + dr[tmp.d] * i;
			nc = tmp.c + dc[tmp.d] * i;

			if (boundry_condition || obstacle) break;
			enqueue(nr, nc, tmp.d, tmp.cnt);
		}

		if (chk[er][ec][ed]) return tmp.cnt+1;
	
	}



	return 0;


}


int main(){
	
	input();
	//printA();


	sol = bfs();
	printf("%d\n", sol);


}














