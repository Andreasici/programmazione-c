// Inserire in un array 10 valori (da utente) e, successivamente, stampare la somma totale e la media//
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define DIM 10
int vet[DIM];
int leggiCifra()
{
	int cifra;
	char car;
	car=getch();
	while((car<'0'&& car!=13) || car>'9')
	{
		car=getch();
	}
	printf("%c", car);
  
	cifra=car-'0';
	  
	return(cifra);
}

int leggiNumero()
{
	int num, c, cifra, base;
    num=0;
    base=10;
    
    cifra=leggiCifra();
    
    for(c=0; c<8 && cifra>=0; c++)
    {
        num=num*base+cifra;
        cifra=leggiCifra();
    }

    return(num);
}




int main(int argc, char *argv[]) 
{
	int i, somma; 
	float media;
	somma=0;
	media=0;
	for(i=0;i<DIM;i++)
	{
		printf("valore vet[%d] = \n", i);
		vet[i]=leggiNumero();
		somma=somma+vet[i];
		printf("\n");
		
	}
	for(i=0;i<DIM;i++)
	{
		printf("valore vet[%d] = %d\n",i,vet[i]);
	}
	media= (float) somma/DIM;
	printf("la somma dei vettori e' %d\n",somma);
	printf("la media dei vettori e' %f\n",media);
	return 0;
}
