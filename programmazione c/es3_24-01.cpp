/* Inserire 10 valori in un array (da utente) e, successivamente, stampare il massimo e il minimo. */
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

int main()
{
	int i, max, min,imax,imin;
	vet[0]=leggiNumero();

	max=vet[0];
	min=max;
	for(i=0;i<DIM;i++)
	{
		
		printf("valore vet[%d] = \n", i);
		
		vet[i]=leggiNumero();
		
		printf("\n");
		if (vet[i] > max) 
		{
			max = vet[i];
			imax=i;
		}
        
		if (vet[i] < min) 
		{
			min = vet[i];	
			imin=i;
		}
          
	}
	
	for(i=0;i<DIM;i++)
	{
		printf("vet[%d] = %d\n", i, vet[i]);
		
	}
	printf("Il numero massimo e' vet[%d] = %d\n", imax, max);
	printf("Il numero minimo e' vet[%d] = %d\n", imin, min);
	return 0;
}