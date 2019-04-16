/* programma che legge un numero di 6 cifre carattere per carattere */
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

/* funzione che legge una cifra decimale come carattere e restituisce il valore numerico corrispondete*/
/* @return valore intero corrispondente alla cifra inserita */

int leggiCifra()
{
	char cifra;	
	int cifraInt;
	
	cifra=getch();
	
	while(cifra<'0' || cifra>'9')
	{
		cifra=getch();
	}
	cifraInt=cifra-'0';
	return (cifraInt);
	
}


int main(int argc, char *argv[])
{
	int n, cifra, ncifre, c;
	
	printf("Introduci quante cifre ha il numero [1-6]: ");
	
	ncifre=leggiCifra();
	while(ncifre>6 || ncifre<1)
	{
		ncifre=leggiCifra();
	}
	printf("%d",ncifre);
	
	n=0;
		printf("\nIntroduci un numero di %d cifre: ",ncifre);
	for(c=0;c<ncifre;c++)
	{
		cifra=leggiCifra();
		printf("%d",cifra);
		n=n*10+cifra;	
	}
	
	printf("\n n = %d\n", n);
}
