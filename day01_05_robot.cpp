

#include <stdio.h>
#define MAX (100+10)

int M, N;
int a[MAX][MAX];
int sol;

typedef enum _Dir{
	EAST=1,
	WEST,
	SOUTH,
	NORTH,	
} Dir;

typedef struct _Point { 
	int y, x;
	Dir dir;	
} Point;
Point Queue[MAX*MAX*MAX];
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

int dr[] = {}

int bfs(){
	
	int ny, nx, nd;


}


int main(){
	///printf("%d, %d, %d, %d", EAST, WEST, SOUTH, NORTH);
	input();
	//printA();


	sol = bfs();
	printf("%d\n", sol);


}














