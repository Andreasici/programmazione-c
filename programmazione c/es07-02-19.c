/*Creare le seguenti funzioni:
a) Caricamento del vettore 
b) Stampa del vettore 
c) Restituire indice max 
d) Restituire indice min 
e) Restituire la somma degli elementi 

f) Scambia i valori contenuti nell'array nelle posizioni x e y (che vengono passati alla funzione)
g) ORDINARE in ordine crescente gli elementi del vettore*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 10

int vet[DIM];

 
 int leggiCifra()
{
  int cifra;
  char car;

  car=getch();
  
  while((car<'0' && car!=13) || car>'9')
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


/**
 * funzione che carica il vettore vet[]
 * @RETURN void
 */
void carica()
{
 	int i, num;
    for(i=0; i<DIM; i++)
    {
    	printf("\nvet[%d]: ", i);
		num=leggiNumero();
    	vet[i]=num;
	}
 	
}


/**
 * funzione che stampa il vettore vet[]
 * @RETURN void
 */
void stampa()
{
	int i;
	for(i=0; i<DIM; i++)
	{
		printf("%d", vet[i]);
	}
}


/**
 * funzione che restituire l'indice massimo del vettore vet[]
 * @RETURN indice massimo
 */
int indiceMax()
{
	int i, imax, max;
	max=vet[0];
	imax=0;
	for(i=0; i<DIM; i++)
	{
		if (vet[i] > max)
		{
			imax=i;
		}
		
	}
	
	return(imax);
}

/**
 * funzione che restituire l'indice minimo del vettore vet[]
 * @RETURN indice minimo
 */
int indiceMin()
{
	int i, imin, min, max;

	min=vet[0];
	imin=0;
	for(i=0; i<DIM; i++)
	{
		if (vet[i] < min)
		{
			imin=i;
		}
		
	}
	return(imin);
}

/**
 * funzione che restituisce la somma degli elementi del vettore vet[]
 * @RETURN somma degli elementi del vettore vet[]
 */
int sommaElementi()
{
	int i, somma;
	somma=0;
	for(i=0; i<DIM; i++)
	{
		somma=somma+vet[i];
	}
	return(somma);
}


/**
 * funzione che scambia i valori contenuti nell'array nelle posizioni x e y (che vengono passati alla funzione)
 * @RETURN somma degli elementi del vettore vet[]
 */





int main(int argc, char *argv[]) 
{
	int i, imax, imin, somma;
	imax, imin, somma=0;
	carica();
	
	imax=indiceMax();
	printf("imax e' %d\n",imax);
	imin=indiceMin();
	printf("imin e' %d\n",imin);
	somma=sommaElementi();
	printf("somma e' %d\n",somma);
	return 0;
}
