#include <stdio.h>
#include <stdlib.h>
#define N 100
/* Realizzare un programma che permetta di giocare al gioco dell'impiccato: si deve permettere l'introduzione della parola segreta e poi si deve chiedere e
 verificare se le lettere sono presenti o, nel caso, se la risposta data corrisponde alla parola
 @Author: Andrea Bauzano, Andrea Siciliano, Leonardo Cesati *
 @date: 21/03/2019
*/

//Funzioni

int leggiCifra();
int leggiNumero();
char maiuscolizza(char lettera);
char leggiLettera();
int leggiParolaSegreta(char vettoreSegreto[], int dim);
void leggiParola( char parola[], int dim);
void caricaVet(char vettoreSostituito[], int dim);
int controlloVettoreLettera(char vettoreSegreto[], int dim, char vettoreSostituito[]);
int controlloParole (char vettoresegreto[], char parola[], int dim);
void stampaVettoreSostituito(char vettoreSostituito[], int dim);
void stampaParolaSegreta(char vettoreSegreto[], int dim);
void wait();
/*GIOCO DELL'IMPICCATO
@Author Andrea Bauzano
*/

int main(int argc, char *argv[]) {
	char vettoreSegreto[N];
	char parola[N];
	char vettoreSostituito[N];
	int nuovadim, i;
	int vita=100;
	int flag, scelta, trovato;
	printf("inserisci la parola segreta:\n");
	nuovadim=leggiParolaSegreta(vettoreSegreto, N);
	printf("%d", nuovadim);
	caricaVet(vettoreSostituito, nuovadim);
	stampaVettoreSostituito(vettoreSostituito, nuovadim);
	
	scelta=1;
	while (scelta!=0 && vita>0)
	{
		system("cls");
		printf("Vuoi cercare di indovinare solo una lettera o cercare direttamente di indovinare la parola?\n");
		printf("Hai %d punti vita.\nSe sbagli una lettera ti vengono sottratti 10 punti vita (HP), se sbagli la parola vengono sottratti 50 punti vita.\n", vita);
		printf("1. Inserisco una lettera\n");
		printf("2. inserisco la Parola\n");
		printf("3. Mostra la parola\n");
		printf("0. Esci\n");
		scelta=leggiCifra();
		printf("%d\n", scelta);
		switch (scelta)
		{
		case 1: trovato=controlloVettoreLettera(vettoreSegreto, nuovadim, vettoreSostituito);
				if (trovato==1)
				{
					printf("La lettera non e' presente\n");
					vita=vita-10;
					printf("\nHP=%d\n", vita);
					stampaVettoreSostituito(vettoreSostituito, nuovadim);
				}
				else if( trovato==0)
				{
					printf("La lettera e' presente\n");
					stampaVettoreSostituito(vettoreSostituito, nuovadim);
				}
				wait();
				break; 
		case 2: leggiParola(parola, nuovadim);
				flag=controlloParole(vettoreSegreto, parola, nuovadim);
				if (flag==0)
				{
					vita=vita-50;
					printf("\nHP=%d\n", vita);
					printf("La parola e' diversa!\n");
				}
				else if (flag==1){
					printf("\nLa parola segreta:");
					stampaParolaSegreta(vettoreSegreto, nuovadim);
					printf("\nBravo! Hai indovintato!");
				}	
				wait();
				  break;
		case 3 : stampaVettoreSostituito(vettoreSostituito, nuovadim);
			wait();
				break;
		case 0 : printf("esci");
				break;
		default: 
				printf("per favore introdurre opzione valida\n");
		}
	}
	if(vita==0)
	{
		printf("\nGAME OVER hai finito gli HP\n");
	}
	return 0;
}

/**
* funzione che legge una cifra decimale o INVIO (non accetta altri caratteri)
* @RETURN il valore intero corrispondente alla cifra oppure un valore negativo se inserito INVIO
@Author Andrea Siciliano
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
@Author Andrea Siciliano
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
* funzione che maiuscolizza una lettera
* @RETURN lettera maiuscola
@Author Leonardo Cesati
*/
 char maiuscolizza(char lettera){
 	
  if (lettera<='a' && lettera>= 'z')
{
lettera = lettera - ('a'-'A');
}
 return (lettera);
 }
 
 /**
* funzione che legge una lettera
* @RETURN lettera inserita dall’utente
@Author Leonardo Cesati
*/
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
 /*
* funzione che carica il vettoreSegreto[]
@Param  char vettoreSegreto[]
@Param int dim
@Modify vettoreSegreto[] con valori della parola segreta
@Author Leonardo Cesati
*/
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

/*
* funzione che carica il vettore parola[]
@Param  char parola[]
@Param int dim
@Modify parola[] con valori insirti dall’utente
@Author Leonardo Cesati
*/
void leggiParola( char parola [] , int dim) 
{
	int i ;
	char lettera ; 
	
	
	for(i = 0  ; i< dim ; i++)
	{
		parola[i] = leggiLettera();	
		printf("%c", parola[i]);		
	}	
}
 


/* Funzione che effettua un controllo tra il vettore segreto e il vettore parola
@Param vettore vettoreSegreto[]
@Param dim dimensione del vettore segreto
@Param vettore parola[]
@Return 0 se é sbagliata && 1 se é giusta
@Author Andrea Bauzano
*/
int controlloParole (char vettoreSegreto[], char parola[], int dim)
	{
		int i; 
		int flag;
		for (i=0; i<dim; i++)
			{
				if(vettoreSegreto[i]!=parola[i])
				{
					flag=0;
					break;
				}
				else 
			{
				flag=1;
				
			}
		}
		return flag;
	}
	
	
/* Funzione che effettua un controllo tra il vettore segreto e la lettera inserita dall'utente 
@Param vettore segreto
@Param dim dimensione del vettore segreto
@Param vettore sostitutivo
@Author Andrea Siciliano
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
			printf("%c", lettera);
			trovato=0;
		}
	}
	return trovato;
}

/* Funzione che stampa il vettoreSostituito[]
@Param vettoreSostituito[]
@Param dim dimensione del vettore segreto
@Author Andrea Siciliano
*/
void stampaVettoreSostituito(char vettoreSostituito[], int dim)
{
	int i;
	for(i=0; i<dim; i++)
	{
		printf("%c ", vettoreSostituito[i]);
	}
}

/* Funzione che stampa il vettoreSegreto[]
@Param vettoreSegreto[]
@Param dim dimensione del vettore segreto
@Author Andrea Bauzano
*/
void stampaParolaSegreta(char vettoreSegreto[], int dim)
{
	int i;
	for(i=0; i<dim; i++)
	{
		printf("%c", vettoreSegreto[i]);
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
		vettoreSostituito[i]=lettera;
		
	}
}

/**
* Interrompe l'esecuzione del programma in attesa che l'utente prema un tasto qualsiasi
@Author Andrea Bauzano
*/
void wait() {
	printf("\n\nSchiaccia un tasto qualsiasi per continuare...");
	getch();
}
