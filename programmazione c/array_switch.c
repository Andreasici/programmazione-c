/* Programma che permette di gestire le informazioni relative ai prezzi di uno smartphone in vari distributori.
attraverso l’uso di alcune funzioni che caricano un vettore, lo stampano, restituire l’il prezzo medio, quello minore
e quello minore e maggiore di un prezzo assegnato dall'utente e il prezzo aumentato di una percentuale
assegnata dall'utente
@author Andrea Siciliano
@date 21/02/2019
*/
#include <stdio.h>
#include <stdlib.h>
#define DIM 5
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
/*
* Funzione che carica con valori interi un vettore passato come parametro
* @PARAM vet[] vettore
* @PARAM DIM dimensione del vettore
* @MODIFY v[] modificato con i valori inseriti dall'utente
*/
void carica(int vet[], int dim)
{
 int i;
 for(i=0; i<dim; i++)
 {
 printf("\nIntroduci il prezzo dello smartphone del distributore n.%d: ", i+1);
 scanf("%d",&vet[i]);
 printf("\n");
 }
}
/*
* Funzione che stampa un vettore passato come parametro
* @PARAM vet[] vettore
* @PARAM DIM dimensione del vettore
*/
void stampa(int vet[], int dim)
{
 int i;
 for(i=0; i<dim; i++)
 {
 printf("\nvet[%d]=%d",i,vet[i]);
 }
}
/*
* Funzione che calcola il prezzo medio
* @PARAM vet[] vettore
* @PARAM DIM dimensione del vettore
* @RETURN prezzo medio
*/
float prezzoMedio(int vet[], int dim)
{
int i;
float media, somma;
somma=0;
for(i=0; i<dim; i++)
{
somma=somma+vet[i];
}
media = ((float) somma)/ DIM;
}
/** Funzione che restituisce il prezzo e il distributore minore di quello inserito in input
* @PARAM vet[] vettore
* @PARAM DIM dimensione del vettore
* @RETURN prezzo e distributore minore di quello inserito in input
*/
int minoreDiInput(int vet[], int dim)
{
	int input, i, controllo;
	controllo=0;
	input=leggiNumero();
	printf("\nIl prezzi minori sono: ");
	for(i=0; i<DIM; i++)
	{
		if(vet[i]<input)
		{
			printf("\n%d nel distributore %d",vet[i],i+1);
			controllo=1;
		}
	}
	return(controllo);
}
/** Funzione che restituisce il prezzo e il distributore minore
* @PARAM vet[] vettore
* @PARAM DIM dimensione del vettore
* @RETURN prezzo e distributore minore
*/
int prezzoMinore(int vet[], int dim)
{
int min, imin, i;
min=vet[0];
imin=0;
for(i=0; i<DIM; i++)
{
if(vet[i]<min)
{
min=vet[i];
imin=i;
}
}
imin=imin+1;
printf("\nIl prezzo minore e' %d del distributore %d\n", min, imin);
}
/** Funzione che restituisce il prezzo e il distributore maggiore tra quelli minori di quello inserito in input
* @PARAM vet[] vettore
* @PARAM DIM dimensione del vettore
* @RETURN prezzo e distributore maggiore tra quelli minori di quello inserito in input
*/
int massimoTraInput(int vet[], int dim)
{
int input, i, tmp, tem, max, imax;
tem=0;
printf("\nInserisci un prezzo: ");
input=leggiNumero();
for(i=0; i<DIM; i++)
{
if(vet[i]<input)
{
tmp=vet[i];
imax=i;
if(tmp>tem)
{
tem=tmp;
imax=i;
max=tem;
}
tem=tmp;
}
}
printf("\nIl prezzo maggiore tra i minori di quello dato in input e' %d del distributore %d\n", max, imax+1);
}
/** Funzione che dato un prezzo restituisce il numero del distributore
* @PARAM vet[] vettore
* @PARAM DIM dimensione del vettore
* @RETURN numero del distributore
*/
int distributore(int vet[], int dim)
{
int i, prezzo, tmp, tem;
prezzo=leggiNumero();
for(i=0; i<DIM; i++)
{
if(prezzo==vet[i])
{
tmp=0;
tem=i+1;
}
}
if(tmp==0)
{
printf("\nDistributore numero %d", tem);
}
else
{
printf("\nDistributore non trovato");
}
}
/** Funzione che dati in input il numero del distributore e il nuovo prezzo dello smartphone, modifica del prezzo
del distributore fornito in input con il prezzo fornito in input
* @PARAM vet[] vettore
* @PARAM DIM dimensione del vettore
* @RETURN prezzo variato
* @MODIFY un valore di vet[] viene modificato con un valore inserito dall'utente
*/
int modificaPrezzo(int vet[], int dim)
{
int i, prezzo, distr;
printf("\nInserisci un distributore: ");
i=leggiNumero();
distr=i-1;
printf("\nInserisci un prezzo: ");
prezzo=leggiNumero();
vet[distr]=prezzo;
return(prezzo);
}
/** funzione che data in input una percentuale, aumenta i prezzi di tutti i distributori della percentuale fornita in
input
* @PARAM vet[] vettore
* @PARAM DIM dimensione del vettore
* @RETURN prezzo variato
* @MODIFY i valori di vet[] vengono modificati con l'aumento in percentuale di una percentuale inserita
dall'utente
*/
float aumentoPercentuale(int vet[], int dim)
{
int i;
float percentuale, aumentato;
percentuale=leggiNumero();
percentuale=percentuale/100;
for(i=0; i<dim; i++)
{
aumentato=(float) vet[i]+vet[i]*percentuale;
printf("\nIl prezzo nel distributore n.%d e' %f",i+1,aumentato);
}
}
int main(int argc, char *argv[])
{
int vet[DIM];
int i, scelta, minoreInput, min, imin, massimoInput, dist, nuovoPrezzo;
float media, percentuale, controllo;
scelta=1;
carica(vet, DIM);
while(scelta!=0)
{
 printf("\n\n1. Stampa del vettore\n");
 printf("2. Stampa del prezzo medio\n");
 printf("3. Prezzo minore di uno dato in input\n");
 printf("4. Prezzo minore\n");
 printf("5. Prezzo maggiore tra i prezzi minori di uno dato in input\n");
 printf("6. Trovare il distributore dal prezzo dello smartphone\n");
 printf("7. Immettere un nuovo prezzo in un distributore\n");
 printf("8. Prezzo aumentato da una percentuale data in input\n");
 printf("0. USCITA\n");
 printf("Introduci la tua scelta: ");
 scelta=leggiNumero();
 switch(scelta)
 {
case 1:
 stampa(vet, DIM);
 break;
 case 2:
 media=prezzoMedio(vet, DIM);
 printf("\nIl prezzo medio e': %f", media);
 break;
 case 3:
printf("\nInserisci un prezzo: ");
 minoreInput=minoreDiInput(vet, DIM);
 if(controllo==0)
	printf("Non esistono");
 break;
 case 4:
 min=prezzoMinore(vet, DIM);
 break;
 case 5:
 massimoInput=massimoTraInput(vet, DIM);
 break;
 case 6:
 printf("\nInserisci un prezzo:");
dist=distributore(vet, DIM);
 break;
 case 7:
nuovoPrezzo=modificaPrezzo(vet, DIM);
for(i=0; i<DIM; i++)
{
printf("\nIl prezzo nel distributore n.%d e' %d",i+1,vet[i]);
}
 break;
case 8:
printf("\nInserisci una percentuale:");
percentuale=aumentoPercentuale(vet, DIM);
 break;
case 0:
 printf("grazie per aver usato il nostro programma\n");
 break;
 default:
 printf("per favore introdurre un'opzione valida\n");
}
}
system("PAUSE");
return 0;
}
