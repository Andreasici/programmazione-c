#include <stdio.h>
#include <stdlib.h>

/**
* Funzione che scambia i valori delle due variabili
* @param pa puntatore al primo valore
* @param pb puntatore al secondo valore
* @moify pa, pb con i valori scambiati
*/
void scambia(int *pa, int *pb)  //vengono passati i puntatori delle variabili e non le variabili, asterisco si legge contenuto di (es. *pa = contenuto di a), p si usa per non confondersi
{
	int aux;
	
	aux=*pa;
	*pa=*pb;
	*pb=aux;
}

int main(int argc, char *argv[])
{
	int a, b;
	
	a=100;
	b=200;
	printf("\nPRIMA valore a: %d    valore b: %d", a, b);

	scambia(&a, &b); // & serve a passare come valori l'indirizzo di dove si trovano le variabili
	
	printf("\nDOPO valore a: %d    valore b: %d", a, b);
	
	
	
	
	
	
	
	return 0;
}
