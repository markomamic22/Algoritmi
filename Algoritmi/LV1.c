#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

void gen_arr(float V[], int n, float dg, float gg);
int sekv_pret(float v[], int n, float x);
int bin_pret(float V[], int n, float x);

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
void swap(float* a, float* b)
{
	float t = *a;
	*a = *b;
	*b = t;
}
int partition(float arr[], int low, int high)
{
	float pivot = arr[high]; // pivot 
	int i = (low - 1); // index manjeg elementa i index pravoga mjesta particiji do sad

	for (int j = low; j <= high - 1; j++)
	{
		// ako je trenutni element manji od pivota 
		if (arr[j] < pivot)
		{
			i++; // povecaj index manjeg elementa 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

//Qucik sort O(n*log(n))
void quickSort(float arr[], int low, int high)
{
	if (low < high)
	{
		/* pi - index particije, arr[p] sada na pravome mjestu */
		int pi = partition(arr, low, high);

		//zasebno sortiraj elemente lijevo i desno od particije
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
//O(1) -iterativno - O(logn) -rekurzivno
int bin_pret(float V[], int n, float x) {
	//iterativno
	int dg = 0;
	int gg = n - 1;
	
	while (dg <= gg) {
		int m = dg + (gg - dg) / 2;

		// Broj u sredini
		if (V[m] == x)
			return m;

		// Ukoliko veci zanemari lijevu stranu
		if (V[m] < x)
			dg = m + 1;

		// Ukoliko manji zanemari desnu
		else
			gg = m - 1;
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
	rez = sekv_pret(x, n, 150.2568497);
	time2 = clock();
	printf("Broj se nalazi na indexu: %d\nVrijeme potrebno za pretragu: %dms\n", rez,(time2-time1));
	time1 = clock();
	quickSort(x, 0, n - 1);
	time2 = clock();
	printf("Vrijeme potrebno za sortiranje: %dms\n", (time2 - time1));
	time1 = clock();
	rez = bin_pret(x, n, 150.2568497);
	time2 = clock();
	printf("Vrijeme potrebno za binarno: %dms\n", (time2 - time1));



	return 0;
}

