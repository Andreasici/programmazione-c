/* programma che legge 5 lettere (minuscole) e le stampa maiuscole */
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define INVIO 13
/* funzione che legge solo una lettera minuscola o il tasto invio e restituisce il valore*/
/* @return lettera minuscola letta o tasto invio*/

int leggiCifra()
{
	char cifra;	
	int cifraInt;
	
	cifra=getch();
	
	while((cifra<'0' && cifra!=INVIO) || cifra>'9')
	{
		cifra=getch();
	}
	cifraInt=cifra-'0';
	return (cifraInt);
	
}

int main(int argc, char *argv[])
{
	int c, n, cifra, cifrap, peso;
	peso=1;
	n=0;
	printf("Introduci un numero di massimo 8 cifre: ");	
	c=0;
	while(c<8)
	{
	if(cifra!=INVIO)
	{
		cifra=leggiCifra();
		peso=peso*10;
		cifrap=cifra*peso;
		n=n*10+cifra;	
		c++;
	}
	else
	{
		return 0;
	}
}
	
	printf("\n %d\n",n);
	return 0;
}
