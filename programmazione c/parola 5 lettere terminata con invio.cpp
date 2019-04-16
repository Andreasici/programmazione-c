/* programma che legge 5 lettere (minuscole) e le stampa maiuscole */
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define INVIO 13
/* funzione che legge solo una lettera minuscola o il tasto invio e restituisce il valore*/
/* @return lettera minuscola letta o tasto invio*/

char minuscola()
{
	char lettera;
	lettera=getch();
	while((lettera<'a' && lettera!=INVIO) || lettera>'z')
	{
		lettera=getch();
	}
	
	return (lettera);
	
}

/* funzione che riceve una lettera minuscola e la restituisce maiuscola*/
/* @param lettera minuscola che verrà restituita maiuscola */
/* @return lettera minuscola letta*/

char maiuscola(char lettera)
{
	char letteraM;
	letteraM=lettera-('a'-'A');
	return (letteraM);
}


int main(int argc, char *argv[])
{
	int c;
	char lettera, parola;
	printf("Introduci una parola: ");	
	lettera=minuscola();
	while(lettera!=INVIO)
	{	
		lettera=maiuscola(lettera);
		printf("%c",lettera);
		lettera=minuscola();
	}
	
}
