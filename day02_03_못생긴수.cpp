

#include<stdio.h>
#define MAX (1500*5+10)


typedef long long llong;


#define SWAP(x,y) {llong z=(x); (x)=(y); (y)=z;}

llong N;
llong heap[MAX];
llong ans[MAX];
llong hn;

#if 0
void push(llong p){
	if (p <= 1 || heap[p / 2] > heap[p]) return;
	SWAP(heap[p/2], heap[p]);
	push(p/2);
}


void pop(llong p, llong n){
	llong next = p * 2;
	if (next > n) return;
	if (next<n && heap[next] < heap[next + 1]) next++;
	if (heap[p] < heap[next]){
		SWAP(heap[p], heap[next]);
		pop(next, n);
	}

}
#else

void push(llong s){
	if (s <= 1 || heap[s / 2] <= heap[s]) return;
	SWAP(heap[s/2], heap[s]);
	push(s/2);
}

void pop(llong s){
	llong ns = s * 2;
	if (ns > hn) return;
	if (ns < hn && heap[ns] > heap[ns + 1]) ns++;
	if (ns > hn || heap[s] <= heap[ns]) return;
	SWAP(heap[s], heap[ns]);
	pop(ns);
}

#endif

int main(){
	
	int nn;
	hn = 1;
	heap[1] = 1;

	
	//ans[1] = heap[1];
	for (nn = 1; nn <= 1500; nn++){
		
		do{
			ans[nn] = heap[1];
			heap[1] = heap[hn--]; // 마지막꺼 앞에다 가져다 놓고
			pop(1); // pop정렬
		} while (ans[nn] == ans[nn-1]);
		

		heap[++hn] = ans[nn] * 2; push(hn);
		heap[++hn] = ans[nn] * 3; push(hn);
		heap[++hn] = ans[nn] * 5; push(hn);

	}
	
	while(1){
		scanf("%lld", &N);
		if (N == 0) { break; }
		printf("%lld\n", ans[N]);		
	}

	return 0;

}
