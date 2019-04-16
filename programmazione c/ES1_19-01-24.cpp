/*Scrivere una funzione che accetta una lettera MAIUSCOLA o minuscola e restituisce il carattere MAIUSCOLO (è lo stesso esercizio proposto in passato ma usando una FUNZIONE)*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define INVIO 13
/*
*funzione che legge una lettera minuscola o maiuscola
* @RETURN lettera maiuscola
*/
int minuscola()
{
	char lettera;
	lettera=getch();
	while((lettera<'A' && lettera!=INVIO) || lettera >'z' || (lettera>'Z' && lettera<'a'))
	{
		lettera=getch();
	}
	
	if(lettera>'a' && lettera<'z')
	{
		lettera=lettera-('a'-'A');
		printf("%c", lettera);
	}
	else
	{
		printf("%c", lettera);
	}
	
}


int main()
{
	char lettera;
	int c;
	lettera=minuscola();
	for(c=0; lettera>INVIO && c>=0; c++)
	{
		lettera=minuscola();
	}
}
