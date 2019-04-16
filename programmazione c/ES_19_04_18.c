#include <iostream>
#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	nAllievi=leggiNumero();
	
	Struct allievi{
		int id;
		char nome[nAllievi];
		char cognome[nAllievi];
	}
	return 0;
}


/**
* funzione che legge una cifra decimale o INVIO (non accetta altri caratteri)
* @RETURN il valore intero corrispondente alla cifra oppure un valore negativo se inserito INVIO
*/
int leggiCifra()
{
	char cifra;
	int cifraDecimale;
	cifra=getch();
	while ((cifra<'0' && cifra!=13) || cifra>'9')
	{
		cifra=getch();
	}
	cifraDecimale=cifra-'0';
	return (cifraDecimale);
}
/*
* funzione che legge un numero naturale (decimale) di max 5 cifre terminato con INVIO (non accetta altri
caratteri)
* @RETURN il valore corrispondente al numero inserito
*/
int leggiNumero()
{
	int cifra, numero, i;
	numero=0;
	int base= 10;
	cifra=leggiCifra();
	for(i=0; i<5 && cifra>=0; i++)
	{
		numero=numero*base+cifra;
		printf("%d", cifra);
		cifra=leggiCifra();
	}
	return (numero);
}
/**
* funzione che legge una lettera maiuscola o minuscola (non accetta altri caratteri)
* @RETURN lettera inserita dall'utente sottoforma di lettera maiuscola
*/
char leggiLettera()
{
	char lettera;
	lettera=getch();
	if(lettera>='a' && lettera<='z')
	{
		lettera=lettera - ('a'-'A');
	}
	while (lettera!='B' && lettera!='G' && lettera!='R' && lettera!='V')
	{
		lettera=getch();
		if(lettera>='a' && lettera<='z')
		{
			lettera=lettera - ('a'-'A');
		}
	}
	
	return (lettera);
}
/*
* funzione che legge la combinazione segreta da trovare
* @Param vettore combinazioneSegreta[] vettore di caratteri
* @Param dimensione del vettore combinazioneSegreta[]
* @Modify modifica il vettore combinazioneSegreta[] aggiungendo i caratteri inseriti dall'utente come elementi
*/
void leggiCombinazioneSegreta(char combinazioneSegreta[], int dim)
{
	int i;
	char lettera;
	lettera=leggiLettera();
	for(i=0; i<dim; i++)
	{
		combinazioneSegreta[i]=lettera;
		printf("%c", lettera);
		lettera=leggiLettera();
	}
}
