/* Programma che permette di gestire le informazioni relative agli invitati ad una festa in maschera.
@author Andrea Siciliano *
@date 28/02/2019
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
* funzione che legge una lettera maiuscola o minuscola (non accetta altri caratteri) e se è minsucola la trasforma in maiuscola
* @RETURN lettera maiuscola inserita dall'utente
*/
int leggiCarattere()
{
	char carattere;
	carattere=getch();
	while (carattere<'A' || (carattere>'Z' && carattere<'a') || carattere>'z')
	{
		carattere=getch();
	}
		while (carattere>='a' && carattere<='z')
	{
		carattere=carattere+'A'-'a';

	}
	printf("%c", carattere);
	return (carattere);
}


/*
* Funzione che carica con valori dei interi tre vettori paralleli passati come parametri
* @PARAM eta[] vettore di interi
* @PARAM nome[] vettore di caratteri
* @PARAM carattere[] vettore di caratteri
* @PARAM DIM dimensione del vettore
* @MODIFY eta[], nome[], costume[] modificati con i valori inseriti dall'utente
*/
void carica(int eta[], char nome[], char costume[], int dim)
{
	int i;
	for(i=0; i<dim; i++)
	{
		printf("\nIntroduci l'eta' della persona %d: ", i);
		scanf("%d",&eta[i]);
		printf("\nIntroduci il nome della persona %d: ", i);
		nome[i]=leggiCarattere();
		printf("\nIntroduci il costume della persona %d: ", i);
		costume[i]=leggiCarattere();
		printf("\n");
	}
}

/*
* Funzione che stampa i vettori passati come parametri
* @PARAM eta[] vettore di interi
* @PARAM nome[] vettore di caratteri
* @PARAM carattere[] vettore di caratteri
* @PARAM DIM dimensione del vettore
*/
void stampa(int eta[], char nome[], char costume[], int dim)
{
	int i;
	for(i=0; i<dim; i++)
	{
		printf("\neta[%d]=%d",i,eta[i]);
		printf("\nnome[%d]=%c",i,nome[i]);
		printf("\ncostume[%d]=%c",i,costume[i]);
	}
}

/*
* Funzione che dato un costume restituisce il nome delle persone che lo indosseranno
* @PARAM eta[] vettore di interi
* @PARAM nome[] vettore di caratteri
* @PARAM carattere[] vettore di caratteri
* @PARAM DIM dimensione del vettore
* @PARAM carattere costumeIndossato che rappresenta il costume da cercare
* @RETURN nome della persona che indossa il costume cosyìtumeIndossato o -1 se nessuno indossa quel costume
*/
char nomiDaCostume(int eta[], char nome[], char costume[], int dim, char costumeIndossato)
{
	int i, controllo, inome;
	controllo=-1;
	for(i=0; i<dim; i++)
	{
		if(costumeIndossato==costume[i])
		{
			controllo=0;
			inome=i;
			return inome;
		}
	}
	
	if(controllo==0)
	{
		return inome;
	}
	else
	{
		return -1;
	}
}

/*
* Funzione che dato un costume restituisce l'età media delle persone che lo indosseranno
* @PARAM eta[] vettore di interi
* @PARAM nome[] vettore di caratteri
* @PARAM carattere[] vettore di caratteri
* @PARAM DIM dimensione del vettore
* @PARAM carattere costumeIndossato che rappresenta il costume da cercare
* @RETURN età media delle persone che indossano il costume costumeIndossato o -1 se nessuno indossa quel costume
*/
int etaMedia(int eta[], char nome[], char costume[], int dim, char costumeIndossato)
{
	int i, somma, divisore;
	float media;
	somma=0;
	divisore=0;
	for(i=0; i<dim; i++)
	{
		if(costumeIndossato==costume[i])
		{
			somma=somma+eta[i];
			divisore++;
		}
	}
	if(somma!=0)
	{
		media = somma/divisore;
		return(media);
	}
	else
	{
		return -1;
	}
}

/*
* Funzione che dato un costume restituisce la fascia d'età delle persone che lo indosseranno
* @PARAM eta[] vettore di interi
* @PARAM nome[] vettore di caratteri
* @PARAM carattere[] vettore di caratteri
* @PARAM DIM dimensione del vettore
* @PARAM carattere costumeIndossato che rappresenta il costume da cercare
*/
void fasciaEta(int eta[], char nome[], char costume[], int dim, char costumeIndossato)
{
	int i, max, min;
	max=0;
	min=eta[0];
	for(i=0; i<dim; i++)
	{
		if(costumeIndossato==costume[i])
		{
		if(max<eta[i])
		{
			max=eta[i];
			
		}
		if(min>eta[i])
		{
			min=eta[i];
			
		}
	}
	}
	printf("\nLa fascia d'eta' media e' %d-%d", min, max);
}

/*
* Funzione che dato un costume restituisce la persona più anziana che lo indosserà
* @PARAM eta[] vettore di interi
* @PARAM nome[] vettore di caratteri
* @PARAM carattere[] vettore di caratteri
* @PARAM DIM dimensione del vettore
* @PARAM costumeIndossato che rappresenta il costume da cercare
* @Return nome della persona più anziana che indosserà il costume costumeIndossato o -1 se nessuno indossa quel costume
*/
char personaAnzianaCostume(int eta[], char nome[], char costume[], int dim, char costumeIndossato)
{
	int i, max, imax, controllo;
	char personaPiuAnziana;
	controllo=-1;
	max=0;
	imax=0;
	for(i=0; i<dim; i++)
	{
		if(costumeIndossato==costume[i])
		{
			if(max<eta[i])
			{
				max=eta[i];
				imax=i;
				controllo=0;
			}
		}
	}
	personaPiuAnziana=nome[imax];
	if (controllo==0)
	{
		return (personaPiuAnziana);
	}
	else
	{
		return -1;
	}
}

/*
* Funzione che dato il nome di un invitato stampa tutti i suoi dati
* @PARAM eta[] vettore di interi
* @PARAM nome[] vettore di caratteri
* @PARAM carattere[] vettore di caratteri
* @PARAM DIM dimensione del vettore
* @PARAM nomeInvitato  che rappresenta il nome della persona
* @Return indice del vettore su cui si trovano i dati della persona o -1 se la persona non esiste 
*/
int datiInvitato(int eta[], char nome[], char costume[], int dim, char nomeInvitato)
{
	int i, controllo, inome;
	controllo=-1;
	for(i=0; i<dim; i++)
	{
		if(nomeInvitato==nome[i])
		{
			controllo=0;
			inome=i;
		}
	}
	if(controllo==0)
	{
		return (inome);
	}
	else
	{
		return (-1);
	}
}

/*
* Funzione che ordina i dati in ordine alfabetico rispetto al nome
* @PARAM eta[] vettore di interi
* @PARAM nome[] vettore di caratteri
* @PARAM carattere[] vettore di caratteri
* @PARAM DIM dimensione del vettore
* @MODIFY eta[], nome[], costume[] ordinati in oridne alfabetico
*/
void ordineAlfabetico(int eta[], char nome[], char costume[], int dim)
{
	int i, j, tmp1, tmp2, tmp3;
	for(i=0; i<dim; i++)
	{
		for(j=0; j<dim; j++)
		{
			if(nome[i]<nome[j])
			{
				tmp1=nome[i];
				nome[i]=nome[j];
				nome[j]=tmp1;
				tmp2=eta[i];
				eta[i]=eta[j];
				eta[j]=tmp2;
				tmp3=costume[i];
				costume[i]=costume[j];
				costume[j]=tmp3;
			}
		}
	}
}

int main(int argc, char *argv[])
{
	int eta[DIM], scelta, dim, media, dati;
	char nome[DIM], costume[DIM], costumeIndossato, persone, personaPiuAnziana, nomeInvitato;
	scelta=1;
	carica(eta, nome, costume, dim);
	while(scelta!=0)
	{
		printf("\n\n1. Stampa del vettore: \n");
		printf("2. Stampa dei nomi delle persone sapendo il costume che indosseranno: \n");
		printf("3. Stampa dell'eta' media: \n");
		printf("4. Stampa della fascia d'eta' delle persone sapendo il costume che indosseranno: \n");
		printf("5. Stampa del nome della persona piu' anziana ad indossare un costume scelto dall'utente: \n");
		printf("6. Stampa di tutti i dati di un invitato: \n");
		printf("7. Stampa dei dati in ordine alfabetico rispetto al nome: \n");
		scelta=leggiNumero();
		printf("\n");
		switch(scelta)
 		{
			case 1:
				stampa(eta, nome, costume, dim);
	 			break;
	 		case 2:
	 			printf("\nInserisci il costume da cercare: \n");
	 			costumeIndossato=leggiCarattere();
				persone=nomiDaCostume(eta, nome, costume, dim, costumeIndossato);
				if (persone==-1) 
				{
	 				printf("\nNessuna persona indossa il costume %c", costumeIndossato);
				}
				else 
				{
					printf("\nLa persona %d indossa il costume %c", persone, costumeIndossato);
				}
	 			break;
	 		case 3:
	 			printf("\nInserisci un costume per cercare l'eta' media:\n");
	 			costumeIndossato=leggiCarattere();
	 			media=etaMedia(eta, nome, costume, dim, costumeIndossato);
	 			if(media!=-1)
	 			{
	 				printf("\nL'eta' media e' %d", media);
				}
	 			else
	 			{
	 				printf("\nNessuna persona indossa quel costume");
				}
	 			break;
	 		case 4:
	 			printf("\nInserisci un costume per cercare la fascia d'eta:\n");
	 			costumeIndossato=leggiCarattere();
	 			fasciaEta(eta, nome, costume, dim, costumeIndossato);
	 			break;
	 		case 5:
	 			printf("\nInserisci un costume per cercare la persona piu' anziana ad indossarlo:\n");
	 			costumeIndossato=leggiCarattere();
	 			personaPiuAnziana=personaAnzianaCostume(eta, nome, costume, dim, costumeIndossato);
	 			if (personaPiuAnziana==-1) 
				{
	 				printf("\nNessuno indossa il costume scelto\n");
				}
				else 
				{
				
					printf("\nLa persona e' %c", personaPiuAnziana);
				}
	 			break;
	 		case 6:
	 			printf("\nInserisci il nome dell'invitato: \n");
	 			nomeInvitato=leggiCarattere();
	 			dati=datiInvitato(eta, nome, costume, dim, nomeInvitato);
	 			if (dati==-1) 
				{
	 				printf("\nNessun invitato si chiama cosi\n");
				}
				else 
				{
				
					printf("\nIl nome e' %c, l'eta' e' %d e il costume e' %c\n", nome[dati], eta[dati], costume[dati]);
				}
	 			break;
	 		case 7:
	 			ordineAlfabetico(eta, nome, costume, dim);
	 			stampa(eta, nome, costume, dim);
	 			break;
			default:
				printf("\nper favore introdurre un'opzione valida\n");
		}
	}
	
	
	return 0;
}
