#include <stdio.h>
#include <stdlib.h>
#define DIM 10
/* programma che permette l'introduzione di 10 valori in un array e li stampa */
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
int main(int argc, char *argv[]) 
{
	int vet[DIM];
	int i;

	for(i=0; i<DIM; i++)
	{
		printf("inserisci valore vet[%d] = \n", i);
		vet[i]=leggiNumero();
		printf("\n");
	}
	for(i=0; i<DIM; i++)
	{
		printf("\nvet[%d] = %d\n",i, vet[i]);
	}
	return 0;
}
