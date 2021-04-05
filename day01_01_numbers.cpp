

#include <stdio.h>
#define MAX (100000+10)
int N;
int a[MAX];
int cntp, cntm;

void input(){
	scanf("%d", &N);
	int nn;
	for (nn = 1; nn <= N; nn++){
		scanf("%d", &a[nn]);
	}
}

void printA(){
	int nn;
	for (nn = 1; nn <= N; nn++){
		printf("%d ", a[nn]);
	}
	printf("\n");
}

int main(){ 
	input();
	//printA();

	int nn;
	cntp = 1;
	cntm = 1;
	int longest = 1;
	int local_long = 1;
#if 1
	for (nn = 2; nn <= N; nn++){
		if (a[nn - 1] < a[nn]) { 
			cntp++; 
			cntm = 1; 
		} 
		else if (a[nn - 1] > a[nn]) { 
			cntp = 1; 
			cntm++; 
		}
		else if (a[nn - 1] == a[nn]) {
			cntp++;
			cntm++;
		}
		local_long = cntp > cntm ? cntp : cntm;
		//printf("ll = %d\n", local_long);
		if (longest < local_long) longest = local_long;
	}
#else
	
	cntp = 1;
	for (nn = 2; nn <= N; nn++){
		if (a[nn - 1] <= a[nn]) {
			cntp++;			
		}
		else  {
			cntp = 1;
		}
		//printf("cntp = %d\n", cntp);
		if (local_long < cntp)  local_long = cntp;
	}
	
	cntm = 1;
	for (nn = 2; nn <= N; nn++){
		if (a[nn - 1] >= a[nn]) {
			cntm++;
		}
		else  {
			cntm = 1;
		}
		if (local_long < cntm)  local_long = cntm;
	}

	//if (longest < local_long)  longest = local_long;
#endif

	//if (N == 1) local_long = 1;
	 
	//printf("%d\n", local_long);
	printf("%d\n", longest);

}



