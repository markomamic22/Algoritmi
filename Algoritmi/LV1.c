#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>


void gen_arr(float V[], int n, float dg, float gg) {

	for (int i = 0; i < n; i++) {

		srand((unsigned)time(NULL));
		V[i] = dg + (float)rand() / RAND_MAX * (gg - dg + 1);
		
	}


}

int main(){

	int n;
	printf("Unesite koliko brojeva zelite generirati:\n");
	scanf("%d", &n);
	float dg, gg;
	printf("Unesite donju granicu za brojeve:\n");
	scanf("%f", &dg);
	printf("Unesite gornju granicu:\n");
	scanf("%f", &gg);
	float* x = (float*)calloc(n, sizeof(float));
	gen_arr(x, n, dg, gg);
	

	return 0;
}

