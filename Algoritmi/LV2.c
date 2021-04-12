#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

void gen_arr(float V[], int n, float dg, float gg);
int sekv_pret(float V[], int n, float x);

struct lista {
	float x;
	struct lista* sljedeci;
};
typedef struct lista node;
int search(node* head, float x);
void gen_arr(float V[], int n, float dg, float gg) {

	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++) {
		V[i] = dg + (float)rand() / RAND_MAX * (gg - dg + 1);
	}


}
int sekv_pret(float V[], int n, float x) {
	
		for (int i = 0; i < n; i++) {
			if (V[i] == x) {
				return i;
			}
		}
		return -1;
	}
int search( node* head, float x)
{
	 node* trenutni = head;  
	while (trenutni != NULL)
	{
		if (trenutni->x == x)
			return 1;
		trenutni = trenutni->sljedeci;
	}
	return 0;
}

int main() {

	int n;
	float dg, gg;
	dg = 1.0;
	gg = 10.0;
	time_t time1, time2;
	time1 = clock();
	time2 = clock();

	printf("Unesite koliko brojeva zelite generirati:\n");
	scanf("%d", &n);
	


	float* x = (float*)calloc(n, sizeof(float));
	time1 = clock();
	gen_arr(x, n, dg, gg);
	time2 = clock();
	printf("Niz se generirao u %dms\n", (time2 - time1));
	
	time1 = clock();
	node* prvi = NULL;
	node* clan = NULL;
	for (int k = 0; k < n; k++) {
		if (k == 0) {
			//head=(element*)malloc(sizeof(element));
			prvi = (node*)malloc(sizeof(node));
			clan = prvi;
		}
		else {
			//p->next=(element*)malloc(sizeof(element));
			clan->sljedeci = (node*)malloc(sizeof(node));
			clan = clan->sljedeci;
		}
		clan->x=dg + (float)rand() / RAND_MAX * (gg - dg + 1);
	}
	clan->sljedeci = NULL;
	time2 = clock();
	printf("Lista se generirala u %dms\n", (time2 - time1));

	time1 = clock();
	sekv_pret(x, n, 150.2568497);
	time2 = clock();
	printf("Niz pretrazivanje je trajalo %dms\n", (time2 - time1));
	time1 = clock();
	search(prvi, 150.2568497);
	time2 = clock();
	printf("Lista pretrazivanje je trajalo %dms\n", (time2 - time1));



	
	return 0;
}