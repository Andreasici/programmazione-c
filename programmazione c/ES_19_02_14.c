/* Programma che attraverso l’uso delle funzioni carica un vettore, lo stampa, restituire l’indice massimo e
minimo, restituisce la somma degli elemntei del vettore, scambia i valori di due posizione del vettore e
lo ordina in ordine crescente
@author Andrea Siciliano *
@date 14/02/2019
*/
#include <stdio.h>
#include <stdlib.h>
#define DIM 5
int vet[DIM];

 /** * funzione che legge solo una cifra esadecimale o INVIO * @RETURN il valore intero corrispondente alla cifra
oppure un valore negativo se inserito INVIO
*/
int leggiCifra()
{
 int cifra;
 char car;
 car=getch();
 while((car<'0' && car!=13) || car>'9')
 {
 car=getch();
 }
 printf("%c", car);
 cifra=car-'0';
 return(cifra);
}
/**
* funzione che legge un numero esadecimale di massimo 7 cifre terminato con INVIO (non accetta altri caratteri)
* @RETURN il numero decimale corrispondente al numero esadecimale
*/
int leggiNumero()
{
 int num, c, cifra, base;
 num=0;
 base=10;
 cifra=leggiCifra();
 for(c=0; c<8 && cifra>=0; c++)
 {
 num=num*base+cifra;
 cifra=leggiCifra();
 }
 return(num);
}
/**
 * funzione che carica il vettore vet[]
 *@MODIFY vet[] vettore definito globalmente
 */
void carica()
{
	int i, num;
	printf("\nInserisci dei valori: ", i);
 	for(i=0; i<DIM; i++)
 	{
		printf("\nvet[%d]: ", i);
		num=leggiNumero();
		vet[i]=num;
	
}
}
/**
 * funzione che stampa il vettore vet[]
 */
void stampa()
{
	int i;
	for(i=0; i<DIM; i++)
	{
		printf("\nvet[%d]=%d", i, vet[i]);
	}
}
/**
 * funzione che restituire l'indice massimo del vettore vet[]
 * @RETURN indice massimo
 */
int indiceMax()
{
	int i, imax, max;
	max=vet[0];
	imax=0;
	for(i=0; i<DIM; i++)
	{
		if (vet[i] > max)
		{
			max=vet[i];
			imax=i;
		}
	}
	return(imax);
}
/**
 * funzione che restituire l'indice minimo del vettore vet[]
 *PARAM start indice da cui partire per la ricerca
 * @RETURN indice minimo
 */
int indiceMin(int start)
{
	int i, imin, min;
	min=vet[start];
	imin=start;
	for(i=start+1; i<DIM; i++)
	{
		if (vet[i] < min)
		{
		min=vet[i];
		imin=i;
		}
	}
	return(imin);
}
/**
 * funzione che restituisce la somma degli elementi del vettore vet[]
 * @RETURN somma degli elementi del vettore vet[]
 */
int sommaElementi()
{
	int i, somma;
	somma=0;
	for(i=0; i<DIM; i++)
	{
		somma=somma+vet[i];
	}
	return(somma);
}
/**
 * funzione che scambia i valori contenuti nell'array nelle posizioni x e y (che vengono passati alla funzione)
 *@PARAM posX e posY
 */
void scambio(int posX, int posY)
{
	int aux;
	aux=vet[posX];
	vet[posX]=vet[posY];
	vet[posY]=aux;
}
/**
 * funzione che ordina in ordine crescente gli elementi del vettore
 *@MODIFY vet[] array dichiarato globalmente
 */
void ordine()
{
	int imin, start;
	for(start=0; start<DIM-1; start++)
	{
		imin=indiceMin(start);
		scambio(start, imin);
	}
}


int main(int argc, char *argv[])
{
int num;
carica();
printf("I valori dell'array sono:\n");
stampa();

scamio();
ordine();



return 0;
}
