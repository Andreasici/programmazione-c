/* Programma che conta la frequenza delle lettere di una parola o frase inserita come vettore di caratteri e controlla se è palindroma.
@author Andrea Siciliano *
@date 07/03/2019
*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 8
#define INVIO 13
#define SPAZIO 32

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
* funzione che legge una letera maiuscola o minuscola (non accetta altri caratteri)
* @RETURN lettera maiuscola o minuscola inserita dall'utente
*/
char leggiLettera()
{
	char lettera;
	lettera=getch();
	while (lettera<INVIO || (lettera>INVIO && lettera < SPAZIO) || (lettera> SPAZIO && lettera<'A') || (lettera>'Z' && lettera<'a') || lettera>'z')
	{
		lettera=getch();
	}
	return (lettera);
}

/*
* funzione che legge una parola di massimo 10 lettere
* @MODIFY modifica il vettore parola[] aggiungendo le lettere inserite dall'utente come elementi
* @RETURN l'array con gli elementi inseriti
*/
char leggiParola(char parola[], int dim)
{
	int i;
	char lettera;
	lettera=leggiLettera();
	for(i=0; i<dim && lettera!=INVIO; i++)
	{
		parola[i]=lettera;
		printf("%c", lettera);
		lettera=leggiLettera();
	}
	return parola[i];
}

/**
* funzione che trasforma le lettere inserite dall'utente da minuscole a maiuscole
* @MODIFY trasforma le lettere minuscole in maiuscole
* @PARAM char lettera inserita dall'utente
* @RETURN lettera maiuscola
*/
char letteraMaiuscola(char lettera)
{
  if(lettera>='a' && lettera<='z')
  {
     lettera=lettera - ('a'-'A');
  }
  return(lettera);
}

/*
* Funzione che carica il vettore passato come parametro
* @PARAM parola[] vettore di caratteri
* @PARAM DIM dimensione del vettore
*/
void carica(char parola[], int dim)
{
	char lettera;
	leggiParola(parola, dim);
}

/*
* Funzione che stampa il vettore passato come parametro
* @PARAM parola[] vettore di caratteri
* @PARAM DIM dimensione del vettore
*/
void stampa(char parola[], int dim)
{
	int i;
	for(i=0; i<dim; i++)
	{
		printf("%c", parola[i]);
	}
}

/*
* Funzione che conta la frequenza delle lettere presenti nel vettore
* @PARAM parola[] vettore di caratteri
* @PARAM DIM dimensione del vettore
*/
void contaLettera(char parola[], int dim)
{
 	int i, conta;
 	char sostituto[dim], car;
 	conta=0;
 	
 	for(i=0; i<dim; i++)
	{
		sostituto[i]=parola[i];
 		sostituto[i]=letteraMaiuscola(parola[i]);
	
	}
	for(car='A'; car<='Z'; car++)
 	{
 		conta=0;
 		
		for(i=0; i<dim; i++)
	 	{
	 		
	 		if(sostituto[i]==car)
	 		{
	 			conta++;	
			}
	 		
		}
		if(conta>0)
		{
			printf("%c %d\n", car, conta);
		}
		
	}
}

/*
* Funzione che conta il numero di lettere presenti nel vettore
* @PARAM parola[] vettore di caratteri
* @PARAM DIM dimensione del vettore
* @RETURN numero di lettere presenti nel vettore
*/
int numeroLettere(char parola[], int dim)
{
	int i, numero;
	numero=0;
	for(i=0; i<dim; i++)
	{
		if(parola[i]!=0)
		numero++;
	}
	return numero;
}

/*
* Funzione che controlla il vettore passato come parametro per vedere se è palindromo
* @PARAM parola[] vettore di caratteri
* @PARAM DIM dimensione del vettore
* @RETURN 1 se il vettore non è palindromo o 0 se è palindromo
*/
int parolaPalindroma(char parola[], int dim, int nlettere)
{
	int i, j, controllo;
	char sostituto[dim];
	j=nlettere-1;
	for(i=0;i<nlettere && i<=j;i++)
	{
		sostituto[i]=letteraMaiuscola(parola[i]);
		sostituto[j]=letteraMaiuscola(parola[j]);
		if(sostituto[i]!=sostituto[j])
			{
				return 1;
			}
		j--;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	char parola[DIM];
	int palindromo, scelta, conto, nlettere;
	printf("Inserisci la parola o frase:\n");
	carica(parola, DIM);
	scelta=1;
	while(scelta!=0)
	{
		printf("\n\n1. Inserisci una nuova parola o frase: \n");
		printf("2. Conto delle lettere: \n");
		printf("3. Verifica se la parola e' palindroma: \n");
		printf("4. Stampa del vettore: \n");
		scelta=leggiNumero();
		printf("\n");
		switch(scelta)
 		{
	 		case 1:
				carica(parola, DIM);
	 			break;
			case 2:
				contaLettera(parola, DIM);
	 			break;
	 		case 3:
	 			nlettere=numeroLettere(parola, DIM);
				palindromo=parolaPalindroma(parola, DIM, nlettere);
				if(palindromo==1)
				{
					printf("Non e' palindroma");
				}
				else
				{
					printf("E' palindroma");
				}
	 			break;
	 		case 4:
	 			stampa(parola, DIM);
	 			break;
	 		default:
				printf("\nper favore introdurre un'opzione valida\n");
	 	}
	}
	
	return 0;
}





