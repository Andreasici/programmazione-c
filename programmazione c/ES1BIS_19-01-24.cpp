/* Scrivere una funzione calcolatrice() che legge due numeri (usando la leggiNumero()) e un carattere che rappresenta una operazione (+, -, *, /) e restituisce il risultato.*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define PER 42
#define PIU 43
#define MENO 45
#define DIVISO 47
/*
*funzione che legge un numero decimale
* @RETURN il valore intero corrispondente al valore del numero decimale
*/
int leggiNumero()
{
	int cifra;
	char car;
	
	car=getch();
	
	while(car<'0' || car>'9')
	{
		car=getch();
	}
	
	cifra=car-'0';
	
	return (cifra);
}

/*
*funzione che legge una operazione e due numeri decimali
* @RETURN risultato dell'operazione
*/
int calcolatrice(int cifra)
{
	int numero;
	numero=cifra+cifra;
}

int main()
{
	int num, c, cifra, base;
	num=0;
	base=10;
	
	cifra=leggiNumero();
	for(c=0; c<3 && cifra>=0; c++)
	{
	
		num=num*base+cifra;
		cifra=leggiNumero();
		
	}
		
	printf("\n%d",num);
	return(num);
	
	
}
