#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

void gen_arr(float V[], int n, float dg, float gg);
int sekv_pret(float v[], int n, float x);



void gen_arr(float V[], int n, float dg, float gg) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++) {
		V[i] = dg + (float)rand() / RAND_MAX * (gg - dg + 1);

	}


}
//O(n)
int sekv_pret(float V[], int n, float x) {

	for (int i = 0; i < n; i++) {
		if (V[i] == x) {
			return i;
		}
	}
	return -1;
}


int main() {

	int n;
	float dg, gg;
	
	
	printf("Unesite koliko brojeva zelite generirati:\n");
	scanf("%d", &n);
	printf("Unesite donju granicu za brojeve:\n");
	scanf("%f", &dg);
	printf("Unesite gornju granicu:\n");
	scanf("%f", &gg);
	
	
	float* x = (float*)calloc(n, sizeof(float));
	gen_arr(x, n, dg, gg);
	

	int rez;
	time_t time1, time2;
	printf("Sekvencijalno pretrazivanje:\n");
	time1 = clock();
	rez = sekv_pret(x, n, 7.2568497);
	time2 = clock();
	printf("Broj se nalazi na indexu: %d\nVrijeme potrebno za pretragu: %dms\n", rez,(time2-time1));




	return 0;
}

