//Inserire in un array 10 valori e stampare l'INDICE di dove si trova il max e il min.//
#include <stdio.h>
#include <stdlib.h>
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
	int i, max, min, imax, imin;
	vet[0]=leggiNumero();

	max=vet[0];
	min=max;
	imin=0;
	imax=0;
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
		printf("il numero massimo si trova nella posizione %d\n", imax);
		printf("il numero minimo si trova nella posizione %d\n", imin);		
	
	return 0;
}
