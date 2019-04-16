#include <stdio.h>
#include <stdlib.h>
#define N 100
/* Realizzare un programma che permetta di giocare al gioco dell'impiccato: si deve permettere l'introduzione della parola segreta e poi si deve chiedere e
 verificare se le lettere sono presenti o, nel caso, se la risposta data corrisponde alla parola
*/

//Funzioni

int leggiCifra();
int leggiNumero();
char leggiLettera();
int leggiParolaSegreta(char vettoreSegreto[], int dim);
void leggiParola( char parola[], int dim);
void caricaVet(char vettoreSostituito[], int dim);
int controlloVettoreLettera(char vettoreSegreto[], int dim, char vettoreSostituito[]);
int controlloParole (char vettoresegreto[], char parola[], int dim);
void stampaVettoreSostituito(char vettoreSostituito[], int dim);


int main(int argc, char *argv[]) {
	char vettoreSegreto[N];
	char parola[N];
	char vettoreSostituito[N];
	int nuovadim;
	int flag, scelta, trovato;
	printf("inserisci la parola segreta");
	nuovadim=leggiParolaSegreta(vettoreSegreto, N);
	caricaVet( vettoreSostituito, N);
	stampaVettoreSostituito(vettoreSostituito, nuovadim);
//	controllaparole (vettoresegreto, parola, nuovadim);
	scelta=1;
	while (scelta!=0)
	{
		printf("Vuoi cercare di indovinare solo una lettera o cercare direttamente di indovinare la parola?\n");
		printf("1. Inserisco una lettera\n");
		printf("2. inserisco la Parola\n");
		printf("3. Mostra la parola\n");
		printf("0. Esci\n");
		scelta=leggiCifra();
		switch (scelta)
		{
		case 1: controlloVettoreLettera(vettoreSegreto, nuovadim, vettoreSostituito);
				if (trovato==1)
				{
					printf("La lettera non e' presente'");

				}
				else if( trovato==0)
				{
					printf("La lettera e' presente");
				}
				break; 
		case 2: controlloParole(vettoreSegreto, parola, nuovadim);
				if (flag==0)
				{
					printf("La parola e' diversa!");
				}
				else 
					printf("Bravo! Hai indovintato!");
		        break;
		case 3 : stampaVettoreSostituito(vettoreSostituito, nuovadim);
				break;
		case 0 : 
				break;
		}
	}
	return 0;
}



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

 /** funz maiuscolizza  **/
 
 char maiuscolizza(char lettera){
 	
  if (lettera<='a' && lettera>= 'z')
{
lettera = lettera - ('a'-'A');
}
 return (lettera);
 }
 
char leggiLettera()
 {
  char lettera;
 int letteraIntera;

lettera=getch();
lettera=maiuscolizza(lettera);
 while((lettera<='A' && lettera>='Z') || ( lettera<='a' && lettera>= 'z'))
 {
 lettera=getch();
 lettera=maiuscolizza(lettera);
 }

  return lettera ;

}
 
	int leggiParolaSegreta(char vettoreSegreto[] , int dim) {
	int numerocar, i;
	for(i=0; i<dim; i++) 
		{
		 vettoreSegreto[i]=leggiLettera();
		 if(vettoreSegreto[i]!=13) 
		 {
			 printf("%c", vettoreSegreto[i]);
			 numerocar=i;
		 }
		 else
		 {
			 numerocar=i;
			 i=N;
		}
		}
printf("\n");
return(numerocar);
}


void leggiParola( char parola [] , int dim) 
{
	int i ;
	char lettera ; 
	
	
	for(i = 0  ; i< dim ; i++)
	{
		parola[i] = leggiLettera();
			
	}	
}
 




int controlloParole (char vettoresegreto[], char parola[], int dim)
	{
		int i; 
		
		for (i=0; i<dim; i++)
			{
				if(vettoresegreto[i]!=parola[i])
				{
					return 0;
				}
				else 
			{
				return 1;
				
			}
		}
	}
	
	
	/* Funzione che effettua un controllo tra il vettore segreto e la lettera inserita dall'utente 
@Param vettore segreto
@Param dim dimensione del vettore segreto
@Param vettore sostitutivo
*/
int controlloVettoreLettera(char vettoreSegreto[], int dim, char vettoreSostituito[])
{
	char lettera;
	int i, trovato;
	lettera=leggiLettera();
	trovato=1;
	for(i=0;i<dim; i++)
	{
		if(vettoreSegreto[i]==lettera)
		{
			vettoreSostituito[i]=lettera;
			trovato=0;
		}
	}
	return trovato;
}

/* Funzione che stampa il vettoreSostituito[]
@Param vettoreSostituito[]
@Param dim dimensione del vettore segreto
*/
void stampaVettoreSostituito(char vettoreSostituito[], int dim)
{
	int i;
	for(i=0; i<dim; i++)
	{
		printf("%c ", vettoreSostituito[i]);
	}
}

/**
* funzione che carica il vettoreSostituito[] con degli _
*@Modify vettoreSostituito[] viene caricato con degli _
@Author Andrea Siciliano
*/
void caricaVet(char vettoreSostituito[], int dim)
{
	int i;
	char lettera='_';
	for(i=0; i<dim; i++)
	{
		vettoreSostituito[i]==lettera;
		
	}
}
