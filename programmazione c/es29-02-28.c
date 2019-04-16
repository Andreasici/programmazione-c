/*
Si vogliono gestire le informazioni relative agli invitati ad una festa in maschera. Per ogni invitato si conosce il nome (rappresentato con l'iniziale), l’età ed il costume che indosserà 
(ad es. Biancaneve, Zorro anche questo rappresentato con l'iniziale). Tutte queste informazioni dovranno essere memorizzate in vettori paralleli.
Scrivere un programma che permetta di realizzare, tramite un menù, quanto segue:
1. Stampa di tutti i dati.
2. Dato un costume, stampa dei nomi di tutte le persone che indosseranno quel costume (infatti possono esserci più persone che indosseranno uno stesso costume.
	Se nessuna persona indosserà quel costume, dovrà essere stampato un opportuno messaggio.
3. Dato un costume, calcolo e stampa dell’età media delle persone che indosseranno quel costume.
4. Calcolo e stampa della fascia d’età degli invitati (ad es. l’età degli invitati va dai 15 ai 21 anni).
5. Dato un costume, stampa della persona più vecchia che indosserà quel costume.
6. Dato il nome di un invitato, stampa di tutti i suoi dati, oppure se l’invitato non esiste, stampa di un messaggio di errore.
7. Ordinamento di tutti i dati in ordine alfabetico del nome.
8. Facoltativo: elenco contenente tutti i costumi che saranno indossati, e per ognuno di essi il numero di persone che lo indosseranno (ovviamente ogni costume dovrà comparire una sola volta nell’elenco).

Per svolgere l’esercizio, occorrerà utilizzare le funzioni con eventuale passaggio di parametri. I vettori dovranno essere passati come parametri.
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

/**
* funzione che legge una letera maiuscola o minuscola (non accetta altri caratteri)
* @RETURN lettera maiuscola o minuscola inserita dall'utente
*/
int leggiCarattere()
{
	char carattere;
	carattere=getch();
	while (carattere<'A' || (carattere>'Z' && carattere<'a') || carattere>'z')
	{
		carattere=getch();
	}
	printf("%c", carattere);
	return (carattere);
}


/*
* Funzione che carica con valori interi un vettore passato come parametro
* @PARAM eta[] vettore di interi
* @PARAM nome[] vettore di caratteri
* @PARAM carattere[] vettore di caratteri
* @PARAM DIM dimensione del vettore
* @MODIFY eta[], nome[], costume[] modificato con i valori inseriti dall'utente
*/
void carica(int eta[], char nome[], char costume[], int dim)
{
	int i;
	for(i=0; i<dim; i++)
	{
		printf("\nIntroduci l'eta': ", i);
		scanf("%d",&eta[i]);
		printf("\n");
	}
	
	for(i=0; i<dim; i++)
	{
		printf("\nIntroduci il nome: ", i);
		nome[i]=leggiCarattere();
		printf("\n");
	}
	
	for(i=0; i<dim; i++)
	{
		printf("\nIntroduci il costume: ", i);
		costume[i]=leggiCarattere();
		printf("\n");
	}
}

void stampa(int eta[], char nome[], char costume[], int dim)
{
	int i;
	for(i=0; i<dim; i++)
	{
		printf("\neta[%d]=%d",i,eta[i]);
	}
	for(i=0; i<dim; i++)
	{
		printf("\nnome[%d]=%c",i,nome[i]);
	}
	for(i=0; i<dim; i++)
	{
		printf("\ncostume[%d]=%c",i,costume[i]);
	}
}

int main(int argc, char *argv[])
{
	int eta[DIM], scelta, dim;
	char nome[DIM], costume[DIM];
	scelta=1;
	carica(eta, nome, costume, dim);
	while(scelta!=0)
	{
		printf("\n\n1. Stampa del vettore\n");
		scelta=leggiNumero();
		switch(scelta)
 		{
			case 1:
				stampa(eta, nome, costume, dim);
	 			break;
			default:
				printf("\\nper favore introdurre un'opzione valida\n");
		}
	}
	
	
	return 0;
}
