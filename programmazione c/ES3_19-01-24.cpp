#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define INVIO 13
/*
*funzione che legge una cifra decimale o INVIO (non accetta altri caratteri)
* @RETURN il valore intero corrispondente al valore della cifra oppure un valore negativo in caso venga premuto INVIO
*/
int leggiCifra()
{
	int cifra;
	char car;
	
	car=getch();
	
	while((car<'0' && car!=INVIO) || car>'1')
	{
		car=getch();
	}
	
	printf("%c", car);
	cifra=car-'0';
	return (cifra);
}

int main()
{
	int num, c, cifra, base, a;
	num=0;
	base=10;
	cifra=leggiCifra();
	while(a>=0)
	{
		for(c=0; c<(a+1) && cifra>=0; c++)
	{
		num=num*base+cifra;
		cifra=leggiCifra();
		num=cifra*2^a;
		a--;
	}
	}
	
		
	printf("\n%d",num);
	return(num);

}
