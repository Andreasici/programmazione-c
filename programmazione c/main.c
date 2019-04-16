#include <stdio.h>
#include <stdlib.h>
/* gioco del tris */
int leggiCifra();
void caricaMatrice(char matrice[][3], int r);
void stampaMatrice(char matrice [][3], int r);
int sostituzioneX(char matrice [][3], int r, int numeroScelto);
int sostituzioneO(char matrice [][3], int r, int numeroScelto);
int controlloTris(char matrice [][3], int r, int numeroScelto);
int main(int argc, char *argv[]) 
{
	int r,c, numeroScelto, tris, mosse;
	r=3;
	c=3;
	char matrice[r][c];
	tris=0;
	mosse = 0;
	int mossaValida;
	
	caricaMatrice(matrice, r);
	stampaMatrice(matrice, r);
	while(tris==0 && mosse<9) {
		printf("Giocatore %d inserisci dove mettere la X\n");
		numeroScelto=leggiCifra();
		mossaValida=sostituzioneX(matrice, r, numeroScelto);
		while(mossaValida==1)
		{
			printf("mossa non valida, riprova\n");
			numeroScelto=leggiCifra();
			mossaValida=sostituzioneX(matrice, r, numeroScelto);
		}
		stampaMatrice(matrice, r);
		tris=controlloTris(matrice, r, numeroScelto);
		if(tris==1)
		{ 
			tris = 2;
			break;
		}
		mosse++;
		printf("Giocatore 2 inserisci dove mettere la O\n");
		numeroScelto=leggiCifra();
		mossaValida=sostituzioneO(matrice, r, numeroScelto);
		while(mossaValida==1)
		{
			printf("mossa non valida, riprova\n");
			numeroScelto=leggiCifra();
			mossaValida=sostituzioneO(matrice, r, numeroScelto);
		}
		stampaMatrice(matrice, r);
		tris=controlloTris(matrice, r, numeroScelto);
		mosse++;
	}
	if(tris==1) {
		printf("hai vinto giocatore 2");
	}
	
	else if (tris==2) {
		printf("hai vinto giocatore 1");
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
	while ((cifra<'1' && cifra!=13) || cifra>'9')
	{
		cifra=getch();
	}
	return (cifra);
	printf("%c",cifra);
}
/*
* funzione che carica la matrice
*@Param matrice
*@Modify modifica degli elementi della matrice
*/
void caricaMatrice(char matrice [][3], int r) {
	int i, j;
	char numero = 49;
	for(i=0; i<3; i++) // righe
	{
		for(j=0; j<3; j++) // colonne
		{
			matrice[i][j]=numero;
			numero++;
		}
	}
}



/*
* funzione che stampa la matrice
*/
void stampaMatrice(char matrice [][3], int r)
{
	int i, j;
	char numero = 1;
	for(i=0; i<3; i++) // righe
	{
		for(j=0; j<3; j++) // colonne
		{
			printf("%c ",matrice[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
/*
* funzione che sostituisce il numero con il segno X
*@Modify modifica degli elementi della matrice
*/
int sostituzioneX(char matrice [][3], int r, int numeroScelto) {
	int i, j;
	char numero = 49;
	char lettera='X';
	for(i=0; i<3; i++) // righe
	{
		for(j=0; j<3; j++) // colonne
		{
			if(matrice[i][j]==numeroScelto) {
				matrice[i][j]='X';
				return 0;
			}
		}
	}
	return 1;
}
/*
* funzione che sostituisce il numero con il segno O
*@Modify modifica degli elementi della matrice
*/
int sostituzioneO(char matrice [][3], int r, int numeroScelto)
{
	int i, j;
	char numero = 49;
	char lettera='O';
	for(i=0; i<3; i++) // righe
	{
		for(j=0; j<3; j++) // colonne
		{
			if(matrice[i][j]==numeroScelto) {
				matrice[i][j]='O';
				return 0;
			}
			numero++;
		}
	}
	return 1;
}
/*
* funzione che controlla se è stato fatto tris
*/
int controlloTris(char matrice [][3], int r, int numeroScelto)
{
	int i, j;

	i=0;
	for(j=0;j<3;j++) 
		{
			if (matrice[i][j]==matrice[i+1][j] && matrice[i+1][j]==matrice[i+2][j])
			return 1;
		}
		j=0;	
	for(i=0; i<3; i++) 
	{
		if(matrice[i][j]==matrice[i][j+1] && matrice[i][j+1]==matrice[i][j+2]) {
			return 1;
		}
	}
	
	if(matrice[0][0]==matrice[1][1] && matrice[1][1]==matrice[2][2])
		{
			return 1;
		}
	else if (matrice[2][0]==matrice[1][1] && matrice[1][1]==matrice[0][2])
		{
			return 1;
		}
	else {
		return 0;
	}
}
