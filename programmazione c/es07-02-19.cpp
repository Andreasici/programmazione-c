/* da numero decimale a numero binario usando array. */
#include <stdio.h>
#include <stdlib.h>
#define DIM 32


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
	int i, r, num, quoto, base;
	r=0;
	printf("Inserisci un numero decimale: ");
	num=leggiNumero();
	base=2;
	quoto=num;
	for(i=0;num>0;i++)
	{
		
		printf("\n%d ", num);
		r=num%base;
		printf("%d", r);
		vet[i]=r;
		num=num/base;
		
		
	}	
	printf("\nIl numero %d in binario e' ", quoto);
	for(i=i-1; i>=0; i--)
	{
		printf("%d", vet[i]);
	}
	if(quoto==0)
	{
		printf("0");
	}
	return 0;
}
