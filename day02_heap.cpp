

#include <stdio.h>

#define MAX (500000+10)
#define SWAP(x,y) {int z=(x); (x)=(y); (y)=z;}

int N;
//int n;
int heap[MAX];

void push(int s){

	if (s <= 1 || heap[s / 2] > heap[s]) return;
	SWAP(heap[s / 2], heap[s]);
	push(s / 2);
}



void pop(int s, int n){ // n 현재 heap의 크기
//void pop(int s){ // n 현재 heap의 크기
	int next = s * 2;
	if (next > n) return; // 자식이 없어, 그냥 pop가능
	if (next < n && heap[next] < heap[next + 1]) next++; // 자식중 큰걸 골라
	if (heap[s] < heap[next]){ // 큰놈이랑 바꿔
		SWAP(heap[s], heap[next]);
		pop(next, n); // 큰놈 pop

	}

}


void input(){
	scanf("%d", &N);
	int nn;
	for (nn = 1; nn <= N; nn++){
		scanf("%d", &heap[nn]);
		push(nn);
	}
}
 
 




void output(){
	for (int i = 1; i <= N; i++){
		printf("%d ", heap[i]);	
	}
	printf("\n");
}

int main()
{
	input();

	output();
	
	int i;
	for (i = N; i > 1; i--){
		SWAP(heap[1], heap[i]);
		pop(1, i - 1);
	}
	
	output();
	return 0;
}














