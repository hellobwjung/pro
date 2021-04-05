
#include<stdio.h>

#define MAX (500+10)

int N;
typedef struct _data { int num, s, e; } data;
data a[MAX];

int time_table[24 + 5];

void input(){
	scanf("%d", &N);
	int nn;
	for (nn = 1; nn <= N; nn++){
		scanf("%d %d %d", &a[nn].num, &a[nn].s, &a[nn].e);
	}
}


void sort(){
	int i, j;
	data tmp;
	for (i = 1; i < N; i++){
		for (j = i + 1; j <= N; j++){
			if ( a[i].e > a[j].e){
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}		
		}
	}
}


int ans = 0;
int sel[MAX];
int grd(){
	int i, end_time=0;
	for (i = 1; i <= N; i++){
		if (a[i].s >= end_time){
			ans++;
			sel[ans] = a[i].num;
			end_time = a[i].e;
		}
	
	}

}
 
int main(){
	input();

	sort();

	grd();
	printf("%d\n", ans);
	int i;
	for (i = 1; i <= ans; i++){
		printf("%d ", sel[i]);
	}
	printf("\n");


	 
	return 0;
}

