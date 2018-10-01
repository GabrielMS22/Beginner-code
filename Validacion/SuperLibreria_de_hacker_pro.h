
#include <stdlib.h> // LIBRERÍAS QUE SIEMPRE UTILIZO
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <dos.h>

//////////////////////////////////// PROTOTIPOS DESCRITOS /////////////////////////////////////////////
//.....................................................................................................    
      
void ValidaNumeros(char *cadena, char msge[]);
// 1 - Se encarga de validar que las entradas del teclado, sean solo numeros.
// 2 - No existe ningún límite de dígitos.
// 3 - necesita recibir como parametro una cadena como mensaje
//     entre comillas ("") desde donde se manda a llamar.
// 5 - Numero maximo de digitos: 10. Si excede ese valor se retornará un número negativo.
//.....................................................................................................

int ValidaNumeros_limitado(int dig, char msge[]);
// 1 - Se encarga de validar que las entradas del teclado, sean solo numeros.
// 2 - Recibe como parámetro el límite de dígitos deseado (int dig) y mensaje ("").
// 3 - necesita recibir como parametro una cadena como mensaje  entre comillas ("msge") para funcionar.
// 5 - Numero maximo de digitos: 10. Si excede ese valor se retornará un número negativo.

//..................................................................................................... 

void ValidaLetras(char cadena[], char msge[], int numero_caracteres);
// 1 - Se encarga de validar que las entradas del teclado, sean solo letras.
//     Los caracteres que asigna en cadena son sólo mayusculas.
// 2 - Recibe como parámetro una cadena previamente declarada donde se guardarán los caracteres y
//     un mensaje entre comillas ("").
// 3 - No retorna ningún valor, sólo llena espacios de la cadena recibida.

//.....................................................................................................
void delay(int tiempo);

///////////////////////////////////////////// FUNCIONES ///////////////////////////////////////////////
void ValidaNumeros(char *cadena, char msge[])
{
	int i;
	char tecla;
	printf("\n\n");
	puts(msge);
	i=0;
	do
	{
		tecla = getch();
		if(tecla >= 48 && tecla <=57)
		{
			cadena[i] = tecla; i++; printf("%c",tecla);	
		}
	}while(tecla!=13&&(strlen(cadena))<=10);
	cadena[i]='\0';
}   

int ValidaNumeros_limitado(int dig, char msge[])
{
	char cadena[20];
	printf("\n\n");
	puts(msge);	
	char tecla;
	int i=0;
		do
		{
			tecla = getch();	
			if((tecla >= 48 && tecla <=57) && i<dig)
			{			
				tecla=toupper(tecla);
				printf("%c",tecla);
				cadena[i]=tecla;				
				i++;
			}	
		} while(tecla!=13);
	cadena[i]='\0';	
	int numero = atoi(cadena);
	return numero;
}                                                                                          

void ValidaLetras(char cadena[], char msge[], int numero_caracteres) 
{
	cadena[0]='\0';
	printf("\n\n");
	puts(msge);
	char letra;
	int i=0;
	do {
            letra=getch();
            if (letra>=97 && letra<=122)
            {
                letra=letra-32;
                          
            }
            if ((letra>=65) && (letra<=90) || (letra==32))
            {
                cadena[i]=letra;
                i++;
                printf("%c",letra); 
        	}	
	} while(letra!=13&&i!=numero_caracteres);
	cadena[i]='\0';
	
}

void delay(int tiempo)
{
  int i,j;
  for(i=0;i<tiempo*100;i++)
     {
	   for(j=0;j<tiempo*100;j++);
		

	 }
}
