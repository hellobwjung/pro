

#include <stdio.h>

#define MAX (100000+10)
int N;
int order;
int a[MAX];
int b[MAX];

void input(){
	scanf("%d", &N);
	scanf("%d", &order);
	int nn;
	for (nn = 1; nn <= N; nn++){
		scanf("%d", &a[nn]);
	}
}

void printA(){
	int nn;
	if (order == 0){
		for (nn = 1; nn <= N; nn++){
			printf("%d\n", a[nn]);
		}
	}
	else {
		for (nn = N; nn >= 1; nn--){
			printf("%d\n", a[nn]);
		}
	}
}

void m_sort(int s, int e){

	if (s >= e) return; //
	int m = (s + e) / 2;
	int i = s, j = m + 1, k = s;

	m_sort(s, m);
	m_sort(m+1, e);

	while (i <= m && j <= e) b[k++] = a[i] < a[j] ? a[i++] : a[j++];
	while (i <= m) b[k++] = a[i++];
	while (j <= e) b[k++] = a[j++];

	for (i = s; i <= e; i++) a[i] = b[i];


}


int main()
{
	input();

	m_sort(1, N);

	printA();

	return 0;
}
