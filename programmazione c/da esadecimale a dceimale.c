#include <stdio.h>
#include <stdlib.h>

/**
 * funzione che legge una cifra esadecimale o INVIO (non accetta altri caratteri)
 * @RETURN il valore intero corrispondente alla cifra oppure un valore negativo se inserito INVIO
 */
int leggiCifra()
{
  int cifra;
  char car;

  car=getch();
  
  while((car<'0' && car!=13) || (car>'9' && car<'A') || car>'F')
  {
    car=getch();
  }
  
  printf("%c", car);
  
  if(car<='9') //il carattere letto è una cifra da 0 a9 o INVIO//
  {
  	cifra=car-'0';
  }
  
  else
  {
  	cifra=(car-'A')+10;
  }
  
  return(cifra);

}

/**
 * funzione che legge un numero esadecimale di massimo 7 cifre terminato con INVIO (non accetta altri caratteri)
 * @RETURN il numero decimale corrispondente al numero esadecimale
 */
int leggiNumero()
{
    int num, c, cifra, base;
    num=0;
    base=16;
    
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
  int num;
  printf("inserisci un numero di 7 cifre esadecimali (0-9 'A'-'F'): ");
  num= leggiNumero();
  printf("\nIl numero inserito e': %d\n", num);
  system("PAUSE");	
  return 0;
}
