/* Programma che controlla se due parole inserite come vettori di caratteri sono uguali.
@author Andrea Siciliano *
@date 28/02/2019
*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 8

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
* @RETURN lettera inserita dall'utente
*/
char leggiLettera()
{
	char lettera;
	lettera=getch();
	while(lettera<'A' || (lettera>'Z' && lettera<'a') || lettera>'z')
	{
		lettera=getch();
	}
	printf("%c", lettera);
	return (lettera);
}

/**
* funzione che trasforma la lettera inserita dall'utente da minuscola in maiuscola
* @PARAM p1[] vettore di caratteri
* @PARAM p2[] vettore di caratteri
* @PARAM DIM dimensione del vettore
*/
void Maiuscola(char p1[], char p2[], int dim)
{
	int i;
	for(i=0; i<dim; i++)
	{
		while (p1[i]>='a' && p1[i]<='z')
		{
			p1[i]=p1[i]+'A'-'a';
		}
		while (p2[i]>='a' && p2[i]<='z')
		{
			p2[i]=p2[i]+'A'-'a';
		}
	}
}

/*
* Funzione che carica con dei valori interi due vettori di caratteri passati come parametri
* @PARAM p1[] vettore di caratteri
* @PARAM p2[] vettore di caratteri
* @PARAM DIM dimensione del vettore
* @MODIFY p1[], p2[] modificati con i valori inseriti dall'utente
*/
void carica(char p1[], char p2[], int dim)
{
	int i;
	printf("\nIntroduci la parola 1: ");
	for(i=0; i<dim; i++)
	{
		p1[i]=leggiLettera();
	}
	printf("\nIntroduci la parola 2: ");
	for(i=0; i<dim; i++)
	{
		p2[i]=leggiLettera();
	}
}

/*
* Funzione che stampa i vettori passati come parametri
* @PARAM p1[] vettore di caratteri
* @PARAM p2[] vettore di caratteri
* @PARAM DIM dimensione del vettore
*/
void stampa(char p1[], char p2[], int dim)
{
	int i;
	printf("\nparola1: ");
	for(i=0; i<dim; i++)
	{
		printf("%c",p1[i]);
	}
	printf("\nparola2: ");
	for(i=0; i<dim; i++)
	{
		printf("%c",p2[i]);
	}
}

/*
* Funzione che controlla se i due vettori sono uguali
* @PARAM p1[] vettore di caratteri
* @PARAM p2[] vettore di caratteri
* @PARAM DIM dimensione del vettore
* @RETURN numero di lettere uguali dei due vettori con lo stesso indice
*/
int controlloCaseSensitive(char p1[], char p2[], int dim)
{
	int i, conta;
	conta=0;
	for(i=0; i<dim; i++)
	{
		if(p1[i]==p2[i])
		{
			conta++;
		}
	}
	return conta;
}

/*
* Funzione che controlla se i due vettori sono uguali
* @PARAM p1[] vettore di caratteri
* @PARAM p2[] vettore di caratteri
* @PARAM DIM dimensione del vettore
* @RETURN numero di lettere uguali dei due vettori con lo stesso indice
*/
int controlloNonCaseSensitive(char p1[], char p2[], int dim, char lettera)
{
	int i, conta;
	conta=0;
	
	for(i=0; i<dim; i++)
	{
		Maiuscola(p1, p2, DIM);
		if(p1[i]==p2[i])
		{
			conta++;
		}
	}
	return conta;
}

int main(int argc, char *argv[])
{
	char p1[DIM], p2[DIM], lettera;
	int controllo, scelta;
	printf("Inserisci delle lettere\n");
	scelta=1;
	carica(p1, p2, DIM);
	while(scelta!=0)
	{
		printf("\n\n1. Stampa del vettore: \n");
		printf("2. Verifica se sono uguali (case sensitive): \n");
		printf("3. Verifica se sono uguali (no case sensitive): \n");
		scelta=leggiNumero();
		printf("\n");
		switch(scelta)
 		{
			case 1:
				stampa(p1, p2, DIM);
	 			break;
	 		case 2:
	 			controllo=controlloCaseSensitive(p1, p2, DIM);
				if(controllo==DIM)
				{
					printf("Le parole sono uguali");
				}
				else
				{
					printf("Le parole non sono uguali");
				}
	 			break;
	 		case 3:
	 			controllo=controlloNonCaseSensitive(p1, p2, DIM, lettera);
				if(controllo==DIM)
				{
					printf("\nLe parole sono uguali");
				}
				else
				{
					printf("\nLe parole non sono uguali");
				}
	 			break;
	 		default:
				printf("\nper favore introdurre un'opzione valida\n");
			}
		}
		return 0;
}
