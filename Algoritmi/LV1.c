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
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot 
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element 
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
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before 
		// partition and after partition 
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
int bin_pret(float V[], int n, float x) {
	
	int dg = 0;
	int gg = n - 1;
	
	while (dg <= gg) {
		int m = dg + (gg - dg) / 2;

		// Check if x is present at mid
		if (V[m] == x)
			return m;

		// If x greater, ignore left half
		if (V[m] < x)
			dg = m + 1;

		// If x is smaller, ignore right half
		else
			gg = m - 1;
	}

	// if we reach here, then element was
	// not present
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

