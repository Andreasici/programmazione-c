/*
Realizzare un programma in C++ in grado di gestire una classe di studenti. 

- Ogni studente è rappresentato attraverso un identificativo numerico, un nome e un cognome (string).

- Il programma deve permettere l'introduzione degli studenti e dei voti.

- La ricerca dello studente con i voti migliori/peggiori

- L'ordinamento degli studenti per cognome/nome o per voto.    (ordinare anche per nome se cognome è uguale)

si consiglia l'uso di struct e di un vettore di allievi (quello che si chiama tabella)

Controllo id univoco (fatto), voti migliori e peggiori
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string> //per implementare il tipo string
#define NALLIEVI 30
#define NVOTI 30
#define INVIO 13
using namespace std; //per implementare il tipo string

typedef struct{
		int id;
		string nome;
		string cognome;
		int voti[NVOTI];
		int votiInseriti;
		float votoMedio;
	} studente;
	
int leggiCifra();
int leggiNumero();
char leggiLettera();
char leggiSceltaSiNoCreDec(int utilizzoScelta);
string caricaStringa();
void stampaStudente(studente tabella[], int numeroStudente, int nVoti, int votiInseriti);
void caricaStudenti(studente tabella[], int numeroStudente, int nVoti);
float media(studente tabella[], int nVoti, int numeroStudente, int i, int votiInseriti);
float votoMigliore(studente tabella[], int numeroStudente, int nVoti, int conta[], int votiInseriti);
float votoPeggiore(studente tabella[], int numeroStudente, int nVoti, int conta[], int votiInseriti);
void ordinaNome(studente tabella[], int numeroStudente, char sceltaCrescenteDecrescente);
void ordinaCognome(studente tabella[], int numeroStudente, char sceltaCrescenteDecrescente);
void ordinaVoto(studente tabella[], int numeroStudente, char sceltaCrescenteDecrescente, int conta[], int votiInseriti);
void caricaVoti(studente tabella[], int scelta, int numeroStudente, int votiInseriti);

int main () {

	int scelta, numeroStudente, migliore, peggiore, conta[NALLIEVI], i, votiInseriti, numeroVoti, utilizzoScelta;
	char sceltaSiNo, sceltaCrescenteDecrescente;
	float mediaVoti;
	numeroStudente=0;
	
 
	studente tabella[NALLIEVI];
	scelta=1;
	while(scelta!=0)
	{
		printf("\n\nScegli un'opzione inserendo il numero corrispondente\n");
		printf("1. Introduzione dei dati degli studenti \n");
		printf("2. Inserimento di un voto \n");
		printf("3. Stampa degli studenti \n");
		printf("4.Ricerca dello studente con i voti migliori\n");
		printf("5.Ricerca dello studente con i voti peggiori \n");
		printf("6.Ordinamento degli studenti per nome \n");
		printf("7.Ordinamento degli studenti per cognome \n");
		printf("8.Ordinamento degli studenti per voto \n");
		printf("0.Uscita dal programma \n");
		scelta=leggiNumero();
		printf("\n");
		switch(scelta)
 		{
	 		case 1:
	 			while(scelta!=-1 && numeroStudente<NALLIEVI)
	 			{
					printf("\n\nInserisci i dati dello studente");
					
					caricaStudenti(tabella, numeroStudente, NVOTI);
					numeroStudente++;
					
					printf("\n\nVuoi inserire un nuovo studente?\nS per si, N per no\n");
					utilizzoScelta=1;
					sceltaSiNo=leggiSceltaSiNoCreDec(utilizzoScelta);
					if(sceltaSiNo=='s' || sceltaSiNo=='S')
						scelta=1;
					else if (sceltaSiNo=='n' || sceltaSiNo=='N')
						scelta=-1;
				}
	 			break;
	 		
	 		case 2:
	 			if(numeroStudente==0)
	 			{
	 				printf("\nNon e' presente nessuno studente");
				}
				else{
					int i;
		 			
		 			while(scelta!=-1) {
		 				caricaVoti(tabella, scelta, numeroStudente, votiInseriti);
					 	printf("\n\nVuoi inserire un nuovo voto?\nS per si, N per no\n");
					 	utilizzoScelta=1;
						sceltaSiNo=leggiSceltaSiNoCreDec(utilizzoScelta);
						if(sceltaSiNo=='s' || sceltaSiNo=='S')
							scelta=1;
						else if (sceltaSiNo=='n' || sceltaSiNo=='N')
							scelta=-1;
					}
				}
	 			
	 			break;
	 			
			case 3:
				if(numeroStudente==0)
	 			{
	 				printf("\nNon e' presente nessuno studente");
				}
				else{
					stampaStudente(tabella, numeroStudente, NVOTI, votiInseriti);
				}
				
	 			break;
	 			
	 		case 4:
	 			numeroVoti=0;
	 			for(i=0;i<numeroStudente;i++) {
	 				if(tabella[i].votiInseriti!=0)
	 					numeroVoti++;
				}
	 			if(numeroVoti!=0)
	 			{
	 				if(numeroStudente==0)
	 			{
	 				printf("\nNon e' presente nessuno studente");
				}
				
				else{
					migliore=votoMigliore(tabella, numeroStudente, NVOTI, conta, votiInseriti);
	 			printf("\nLo studente con i voti migliori e' lo studente con l'id = %d ",tabella[migliore].id);cout<<"("<<tabella[migliore].nome;cout<<" "<<tabella[migliore].cognome;cout<<")";
				}
				}
	 		
	 			else if(numeroVoti==0){
					printf("\nNon e' stato inserito alcun voto");
				}
	 			break;
	 			
	 		case 5:
	 			numeroVoti=0;
	 			for(i=0;i<numeroStudente;i++) {
	 				if(tabella[i].votiInseriti!=0)
	 					numeroVoti++;
				}
	 			if(numeroVoti!=0)
	 			{
	 				if(numeroStudente==0)
	 			{
	 				printf("\nNon e' presente nessuno studente");
				}
				
				else{
					peggiore=votoPeggiore(tabella, numeroStudente, NVOTI, conta, votiInseriti);
	 				printf("\nLo studente con i voti peggiori e' lo studente con l'id = %d ",tabella[peggiore].id);cout<<"("<<tabella[peggiore].nome;cout<<" "<<tabella[peggiore].cognome;cout<<")";
				}
				}
	 		
	 			else if(numeroVoti==0){
					printf("\nNon e' stato inserito alcun voto");
				}
	 			
	 			break;
	 		
	 		case 6:
	 			if(numeroStudente==0)
	 			{
	 				printf("\nNon e' presente nessuno studente");
				}
	 			else {
				 printf("\n Vuoi ordinare i nomi in ordine crescente o decrescente?\nC per crescente, D per decrescente\n");
				 utilizzoScelta=0;
	 				sceltaCrescenteDecrescente=leggiSceltaSiNoCreDec(utilizzoScelta);
				ordinaNome(tabella, numeroStudente, sceltaCrescenteDecrescente);
	 			stampaStudente(tabella, numeroStudente, NVOTI, votiInseriti);
	 		}
	 			break;
	 			
	 		case 7:
	 			if(numeroStudente==0)
	 			{
	 				printf("\nNon e' presente nessuno studente");
				}
				else {
					printf("\n Vuoi ordinare i cognomi in ordine crescente o decrescente?\nC per crescente, D per decrescente\n");
					utilizzoScelta=0;
	 				sceltaCrescenteDecrescente=leggiSceltaSiNoCreDec(utilizzoScelta);
					ordinaCognome(tabella, numeroStudente, sceltaCrescenteDecrescente);
	 				stampaStudente(tabella, numeroStudente, NVOTI, votiInseriti);
	 			}
				break;
	 			
	 		case 8:
	 			numeroVoti=0;
	 			for(i=0;i<numeroStudente;i++) {
	 				if(tabella[i].votiInseriti!=0)
	 					numeroVoti++;
				}
	 			if(numeroVoti!=0)
	 			{
	 				if(numeroStudente==0)
	 			{
	 				printf("\nNon e' presente nessuno studente");
				}
				
				else{
					printf("\n Vuoi ordinare i voti in ordine crescente o decrescente?\nC per crescente, D per decrescente\n");
					utilizzoScelta=0;
	 				sceltaCrescenteDecrescente=leggiSceltaSiNoCreDec(utilizzoScelta);
	 				ordinaVoto(tabella, numeroStudente, sceltaCrescenteDecrescente, conta, votiInseriti);
	 				stampaStudente(tabella, numeroStudente, NVOTI, votiInseriti);
				}
				}
	 		
	 			else if(numeroVoti==0){
					printf("\nNon e' stato inserito alcun voto");
				}
	 			break;
	 		
	 		case 0:
	 			printf("\n\n\nGrazie di aver utilizzato questo programma\n\n\nSe hai trovato qualche baco scrivici qua: ");
				scelta=0;
				break;
	 			
	 			
	 		default:
				printf("\nper favore introdurre un'opzione valida\n");
	 	}
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
	for(i=0; i<2 && cifra>=0; i++)
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
	while ((lettera!=INVIO && lettera<'A') || (lettera>'Z' && lettera<'a') || lettera>'z')
	{
		lettera=getch();
	}
	return (lettera);
}

char leggiSceltaSiNoCreDec(int utilizzoScelta)
{
	char lettera;
	lettera=getch();
	if(utilizzoScelta==1) {
		while (lettera!='N' && lettera!='S' && lettera!='n' && lettera!='s')
		{
			lettera=getch();
		}
	}
	else if(utilizzoScelta==0) {
		while (lettera!='C' && lettera!='D' && lettera!='c' && lettera!='d')
		{
			lettera=getch();
		}
	}
	printf("%c",lettera);
	return (lettera);
}

/*
* funzione che legge una parola di massimo 10 lettere
* @MODIFY modifica il vettore parola[] aggiungendo le lettere inserite dall'utente come elementi
* @RETURN l'array con gli elementi inseriti
*/
string caricaStringa()
{
	int i;
	string parola;
	char lettera;
	lettera=leggiLettera();
	for(i=0;lettera!=INVIO && i<10;i++) {
		if(i==0 && (lettera>='a' && lettera<='z')) {
    		lettera=lettera - ('a'-'A');
 		}
		else if(i!=0 && (lettera>='A' && lettera<='Z')) {
			lettera=lettera-('A'-'a');
		}
		else {}
		printf("%c",lettera);
		parola+=lettera;
		lettera=leggiLettera();
	}
	
	return parola;
}

void caricaStudenti(studente tabella[], int numeroStudente, int nVoti) {
	int i;
	printf("\nId = ");
	tabella[numeroStudente].id=numeroStudente+1;
	printf("%d", tabella[numeroStudente].id);
	
	printf("\nNome = ");
	tabella[numeroStudente].nome=caricaStringa();
	while(tabella[numeroStudente].nome== ""){
		printf("Non hai inserito un nome ");
		tabella[numeroStudente].nome=caricaStringa();
	}
	printf("\nCognome = ");
		tabella[numeroStudente].cognome=caricaStringa();
	while(tabella[numeroStudente].cognome== ""){
		printf("Non hai inserito un cognome ");
		tabella[numeroStudente].cognome=caricaStringa();
	}
	
	tabella[numeroStudente].votiInseriti=0;
	
	
	
	
}

void stampaStudente(studente tabella[], int numeroStudente, int nVoti, int votiInseriti)
{
	int i,j;
	for(i=0;i<numeroStudente;i++)
	{
		printf("\n\nId = %d", tabella[i].id);
		
		cout<<"\nNome = "<<tabella[i].nome;
		
		cout<<"\nCognome = "<<tabella[i].cognome;
		
		for(j=0;j<tabella[i].votiInseriti;j++) {
		printf("\nVoto %d = %d", j,tabella[i].voti[j]);
		}
	}
}


float media(studente tabella[], int nVoti, int numeroStudente, int j, int votiInseriti)
{
	float media;
	int somma,i,numeroSomme;
	somma=0;
	numeroSomme=0;
	
		for(i=0;i<tabella[j].votiInseriti;i++) //numeroStudente cambia con l'aggiunta di studenti  //votiInseriti impazzisce ordineVoto
		{
			printf("\ni media =%d", numeroSomme);
			somma=somma+tabella[j].voti[i];
			numeroSomme++;
			printf("\ni media =%d", numeroSomme);
		}
		if(numeroSomme==0)
		{
			
			return 0;
		}
		tabella[j].votoMedio = (float) somma/numeroSomme;
		printf("media %f", tabella[j].votoMedio);
	return tabella[j].votoMedio;
}

float votoMigliore(studente tabella[], int numeroStudente, int nVoti, int conta[], int votiInseriti)
{
	float votoMedio, votoMigliore;
	int i,indexMax;
	i=0;
	votoMigliore=tabella[0].votoMedio;
	indexMax=0;
	for(i=0;i<numeroStudente;i++)
	{
		votoMedio=tabella[i].votoMedio;
		if(votoMigliore<votoMedio) {
			votoMigliore=votoMedio;
			indexMax=i;
		}
			
	}
	
	return indexMax;
}

float votoPeggiore(studente tabella[], int numeroStudente, int nVoti, int conta[], int votiInseriti)
{
	float votoMedio, votoPeggiore;
	int i,indexMin;
	i=0;
	votoPeggiore=tabella[0].votoMedio;
	indexMin=0;
	for(i=0;i<numeroStudente;i++)
	{
		votoMedio=tabella[i].votoMedio;
		if(votoPeggiore>votoMedio && votoMedio!=0) {
			votoPeggiore=votoMedio;
			indexMin=i;
		}
			
	}
	return indexMin;
}

void ordinaNome(studente tabella[], int numeroStudente, char sceltaCrescenteDecrescente)
{
	int i, j;
	studente tmp;
	for(i=0;i<numeroStudente;i++)
	{
		for(j=0; j<numeroStudente; j++) {
			if(sceltaCrescenteDecrescente=='C' || sceltaCrescenteDecrescente=='c') {
				if(tabella[i].nome<tabella[j].nome || (tabella[i].nome==tabella[j].nome && tabella[i].cognome<tabella[j].cognome)) {
				tmp=tabella[i];
				tabella[i]=tabella[j];
				tabella[j]=tmp;
			}
		}
			else if(sceltaCrescenteDecrescente=='D' || sceltaCrescenteDecrescente=='d') {
				if(tabella[i].nome>tabella[j].nome || (tabella[i].nome==tabella[j].nome && tabella[i].cognome>tabella[j].cognome)) {
				tmp=tabella[i];
				tabella[i]=tabella[j];
				tabella[j]=tmp;
				}
			}
		}
	}
}

void ordinaCognome(studente tabella[], int numeroStudente, char sceltaCrescenteDecrescente)
{
	int i, j;
	studente tmp;
	for(i=0;i<numeroStudente;i++)
	{
		for(j=0; j<numeroStudente; j++) {
			if(sceltaCrescenteDecrescente=='C' || sceltaCrescenteDecrescente=='c') {
				if(tabella[i].cognome<tabella[j].cognome || (tabella[i].cognome==tabella[j].cognome && tabella[i].nome<tabella[j].nome)) {
				tmp=tabella[i];
				tabella[i]=tabella[j];
				tabella[j]=tmp;
			}
		}
			else if(sceltaCrescenteDecrescente=='D' || sceltaCrescenteDecrescente=='d') {
				if(tabella[i].cognome>tabella[j].cognome || (tabella[i].cognome==tabella[j].cognome && tabella[i].nome>tabella[j].nome)) {
				tmp=tabella[i];
				tabella[i]=tabella[j];
				tabella[j]=tmp;
				}
			}
		}
	}
}

void ordinaVoto(studente tabella[], int numeroStudente, char sceltaCrescenteDecrescente, int conta[], int votiInseriti)
{
	int i, j;
	float votoMedioI, votoMedioJ;
	studente tmp;
	for(i=0;i<numeroStudente;i++)
	{
		votoMedioI=tabella[i].votoMedio;
		for(j=0; j<numeroStudente; j++) {
			votoMedioJ=tabella[j].votoMedio;
			if(sceltaCrescenteDecrescente=='C' || sceltaCrescenteDecrescente=='c') {
				if(votoMedioI<votoMedioJ) {
				tmp=tabella[i];
				tabella[i]=tabella[j];
				tabella[j]=tmp;
				}
			}
			else if(sceltaCrescenteDecrescente=='D' || sceltaCrescenteDecrescente=='d') {
				if(votoMedioI>votoMedioJ) {
				tmp=tabella[i];
				tabella[i]=tabella[j];
				tabella[j]=tmp;
				}
			}
		}
	}
}

void caricaVoti(studente tabella[], int scelta, int numeroStudente, int votiInseriti) {
	int id, trovato, i, j;
	trovato=0;
	printf("\nInserire l'id dello studente ");
	id=leggiNumero();
	for(i=0;i<numeroStudente && trovato==0;i++) {
		if(id==tabella[i].id) {
			trovato=1;
			j=i;
		}
	}
	if(trovato==1) {
		printf("\nInserisci il voto");
		tabella[j].voti[tabella[j].votiInseriti]=leggiNumero();
		tabella[j].votiInseriti++;
		stampaStudente(tabella, numeroStudente, NVOTI, votiInseriti);
		tabella[j].votoMedio=media(tabella, NVOTI, numeroStudente, j, votiInseriti);
	}
	else {
		printf("\nstudente non trovato");
	}
}


