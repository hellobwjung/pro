

#include <stdio.h>
#define MAX (100+10)
int N, M;
int R, C, S, K;
int a[MAX][MAX];
int sol;

typedef struct _Point { int y, x; } Point;
Point Queue[MAX*MAX];
int wp, rp;
void Enqueue(int sy, int sx){
	Queue[wp].y = sy;
	Queue[wp].x = sx;
	wp++;
}
Point Dequeue(){
	return Queue[rp++];
}




void input(){
	scanf("%d %d", &N, &M);
	scanf("%d %d", &R, &C);
	scanf("%d %d", &S, &K);
	//printf();
}

void initA(){
	int xx, yy;
	for (yy = 1; yy <= N; yy++){
		for (xx = 1; xx <= N; xx++){
			a[yy][xx] = 123456;
		}	
	}
}


int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 }; 

int bfs(int sy, int sx){
	Point out;
	int ny, nx;

	int nn;

	Enqueue(sy, sx);
	a[sy][sx] = 0;

	while (wp>rp){
		out = Dequeue();

		for (nn = 0; nn < 8; nn++){

			ny = out.y + dy[nn];
			nx = out.x + dx[nn];

			if (ny<1 || nx<1 || ny>N || nx>M) continue; 

			if (ny == S && nx == K){
				a[ny][nx] = a[out.y][out.x] + 1;
				return a[ny][nx];
			
			} else {
				if (a[ny][nx] > a[out.y][out.x]+1){
					a[ny][nx] = a[out.y][out.x] + 1;
					Enqueue(ny, nx);
				}
			}
			



		}
	
	}

}

int main(){

	input();
	initA();

	//sol = 0xfff7777;
	sol = bfs(R, C);
	printf("%d\n", sol);
}
