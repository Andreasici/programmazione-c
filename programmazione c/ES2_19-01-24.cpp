/*Scrivere il Programma che legge 10 numeri e stampa il maggiore e il minore usando la funzione leggiNumero().*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define INVIO 13
int leggiCifra()
{
	int cifra;
	char car;
	
	car=getch();
	
	while((car<'0' && car!=INVIO) || car>'9')
	{
		car=getch();
	}
	
	printf("%c", car);
	cifra=car-'0';
	return (cifra);
}


int main()
{
	int num, c, cifra, base, cont;
	base=10;
	cont=0;
	while(cont<10)
	{
		cifra=leggiCifra();
	for(c=0; c<2 && cifra>=0; c++)
	{
	
		num=num*base+cifra;
		cifra=leggiCifra();
		
	}
	
	cont++;
	}
printf(" %d ",num);

}
