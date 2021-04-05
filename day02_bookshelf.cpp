

#include <stdio.h>

#define MAXL (50000+10)
#define MAXN (20000+10)

typedef long long llong;

#define SWAP(x,y) {llong z=(x); (x)=(y); (y)=z;}

llong N;
llong Hsize;
llong a[MAXN];
llong heap[MAXN];

void input(){
	scanf("%d", &N);
	int nn;
	for (nn = 1; nn <= N; nn++){
		scanf("%lld", &a[nn]);
	}
}

void printHeap(){
	int nn;
	for (nn = 1; nn <= N; nn++){
		printf("%lld\n", heap[nn]);	
	}
	printf("\n");

}


void push(int s){
	if (s <= 1 || heap[s/2] < heap[s]) return;
	SWAP(heap[s/2], heap[s]);
	push(s/2);
}

void pop(llong s){
	llong next = s * 2;
	//if (next > Hsize) return;
	if (next < Hsize && heap[next] > heap[next + 1]) next++;
	if (next > Hsize || heap[s] <= heap[next]) return;
	SWAP(heap[s], heap[next]);
	pop(next);
}


void insert(){
	int nn;
	for (nn = 1; nn <= N; nn++){
		heap[nn] = a[nn];
		Hsize++;
		push(nn);	
	}

}

int main(){

	input();

	insert();

	//printHeap();

	llong ans = 0;
	llong acc = 0, tmp1, tmp2;
	
	while (Hsize > 1) {
		ans = 0;
		tmp1 = heap[1]; heap[1] = heap[Hsize--]; pop(1);
		tmp2 = heap[1]; heap[1] = heap[Hsize--]; pop(1);
		ans = tmp1 + tmp2;
		acc += ans;

		heap[++Hsize] = ans; push(Hsize);
		//printf("Hsize = %lld, acc= %lld \n", Hsize, acc);
	}

	printf("%lld\n", acc);


}
