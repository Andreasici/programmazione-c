/** MASTER MIND
- rosso , verde ,giallo , blu (COMBINAZIONE SEGRETA DA INSERIRE )
- combinazione di 4 lettere dall' utente

- inserimento manuale colori per combinazione
 
- deve permettere di dire quanti colori giusti 
al posto giusto ci sono e quanti quelli sbagliati 

- carattere giusto al posto giusto stampa O
- colore giusto al posto sbagliato stampa o
stampare prima O e poi o 

- il programma deve accettare solo quelle 4 lettere
*/



#include <stdio.h>
#include <stdlib.h>
#define DIM 4 

// prototipi
int leggiCifra();
int leggiNumero();
char leggiLettera();
void leggiCombinazioneSegreta(char combinazioneSegreta[], int dim);
void leggiCombinazioneUtente(char combinazioneSegreta[], int dim);
void vettoreSostituto(char combinazioneSegreta[], int dim, char sostituto[]);
int giustaGiusta(char combinazioneUtente[], int dim, char sostituto[]);
int giustaSbagliata(char combinazioneUtente[], int dim, char sostituto[]);

int main(int argc, char *argv[])
{
	int tentativiMassimi, tentativiEffettuati, gg, i, gs;
	char combinazioneUtente[DIM], combinazioneSegreta[DIM], sostituto[DIM];
	printf("Inserisci la combinazione segreta\n");
	leggiCombinazioneSegreta(combinazioneSegreta, DIM);
	printf("\nInserisci i numeri di tentativi massimi\n");
	tentativiMassimi=leggiNumero();
	for(i=0; i<30; i++)
	{
		printf("\n");
	}
	printf("La combinazione corretta si trova in cima, non guardare\nbO significa che hai trovato il posto corretto di un colore\no significa che hai trovato un colore esatto nel posto sbagliato");
	tentativiEffettuati=0;
	while(gg<4 && tentativiEffettuati<tentativiMassimi)
	{
		vettoreSostituto(combinazioneSegreta, DIM, sostituto);
		printf("\nInserisci la combinazione che vuoi provare\n");
		leggiCombinazioneUtente(combinazioneUtente, DIM);
		gg=giustaGiusta(combinazioneUtente, DIM, sostituto);
		printf("  ");
		for(i=0; i<gg; i++)
		{
			printf("O");
		}
		
		gs=giustaSbagliata(combinazioneUtente,  DIM, sostituto);
		printf(" ");
		for(i=0; i<gs; i++)
		{
			printf("o");
		}
		tentativiEffettuati++;
		if(gg==4)
		{
			printf("\nComplimenti hai vinto");
		}
	}
	
	if(tentativiEffettuati==tentativiMassimi)
		{
			printf("\nMi dispiace hai perso");
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

/*
* funzione che legge la combinazione inserita dall'utente
* @Param vettore combinazioneUtente[] vettore di caratteri
* @Param dimensione del vettore combinazioneUtente[]
* @Modify modifica il vettore combinazioneUtente[] aggiungendo i caratteri inseriti dall'utente come elementi
*/
void leggiCombinazioneUtente(char combinazioneUtente[], int dim)
{
	int i;
	char lettera;
	lettera=leggiLettera();
	for(i=0; i<dim; i++)
	{
		combinazioneUtente[i]=lettera;
		printf("%c", lettera);
		lettera=leggiLettera();
	}
}

/*
* funzione che sostituisce il vettore combinazioneSegreta[] con il vettore sostituto[]
* @Param vettore combinazioneUtente[] vettore di caratteri
* @Param dimensione del vettore combinazioneUtente[]
* @Param vettore sostituto[] vettore di caratteri
* @Modify modifica il vettore sostituto[] aggiungendo con i caratteri del vettore combinazioneSegreta[]
*/
void vettoreSostituto(char combinazioneSegreta[], int dim, char sostituto[])
{
	int i;
	for(i=0; i<dim; i++)
	{
		sostituto[i]=combinazioneSegreta[i];
	}	
}

/*
* funzione che controlla se i colori sono posizionati al posto giusto
* @Param vettore combinazioneUtente[] vettore di caratteri
* @Param dimensione dei vettori combinazioneUtente[] e sostituto[]
* @Param vettore sostituto[] vettore di caratteri
* @Return il numero di colori inseriti nel posto giusto
*/
int giustaGiusta(char combinazioneUtente[], int dim, char sostituto[])
{
	int i, conta;

	
	conta=0;
	for(i=0; i<dim; i++)
	{
		if(combinazioneUtente[i]==sostituto[i]) {
		
			combinazioneUtente[i]='X';
			sostituto[i]='Y';
			conta++;
		}
	}
	return conta;
}

/*
* funzione che controlla se dei colori presenti anche nella combinazione segreta siano posizionati al posto sbagliato
* @Param vettore combinazioneUtente[] vettore di caratteri
* @Param dimensione dei vettori combinazioneUtente[] e sostituto[]
* @Param vettore sostituto[] vettore di caratteri
* @Return il numero di colori inseriti nel posto sbagliato
*/
int giustaSbagliata(char combinazioneUtente[], int dim, char sostituto[])
{
	int i,j, conta;
	conta=0;
	for(i=0; i<dim; i++)
	{
		for(j=0;j<dim;j++) {
		
			if(combinazioneUtente[i]==sostituto[j]) {
			combinazioneUtente[i]='X';
			sostituto[j]='Y';				
				conta++;
			}
		}
	}
	return conta; 
}
