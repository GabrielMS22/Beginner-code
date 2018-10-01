//Gabriel Melchor Sanchez
//***************************************************************************************
//    LIBRERIAS
//**************************************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
//****************************************************************
/// Constantes
//**********************************************************************

  
#define PAUSA printf("\nPresione una tecla para continuar"); getch();
#define TRUE 1
#define FALSE 0

typedef struct tdato{
        struct tdato *sig; 
        int dato;      
        }Tdato;        
              
typedef Tdato *Tnodo;
typedef Tdato *Pila;

//****************************************************************************
// PROTOTIPO DE FUNCIONES                 
Tnodo llenaDatos(int i);    
Tnodo POP(Tnodo *pila);
void PUSH(Tnodo *pila, Tnodo *nuevo);
void Servicio(Tnodo temp);
void menu(void);
void factorial(void);
int validanum(int n1, int n2, char *msge, char *merror);  
void delay(int);
//****************************************************************************
// MAIN PRINCIPAL  ...  funcion principal
//****************************************************************************

int main (void)
{
   menu();
   return 0;
}
//****************************************************************************
// desarollo de las funciones en el mismo orden de como listamos los prototipos
//****************************************************************************
//*****************   FUNCION MENU DESDE DONDE SE MANDA LLAMAR LAS DEMAS FUNCIONES
void menu(void)
{
     	int op,numf,i,factorial;
	    Tnodo nuevo=NULL,pila=NULL,temp=NULL;
	    srand(time(NULL));
	
	   do{
	    system("cls");
		printf("  M   E   N   U \n");
		printf("1.FACTORIAL DE UN NUMERO(USANDO PILAS,PUSH,POP)\n");
		printf("2.SALIR\n");
        op=validanum(1,2,"Insertar Numero valido (1,2)\n","Que parte de numero valido no entendiste?");
		switch(op)
		     {
                  case 1: system("cls");
                          printf("Dame el numero a Calcular Factorial: ");
                          numf=validanum(1,1000,"Insertar Numero valido \n","Que parte de numero valido no entendiste?");
                          for(i=1;i<=numf;i++)
                             {
                               nuevo=llenaDatos(i);
                               PUSH(&pila,&nuevo);                              
                             } 
                            factorial=1;      
                            while(pila)
                             {
                                      temp=POP(&pila);   
                                      factorial=factorial*(temp->dato);
                                      printf("...\n");
                                      printf("%d \n",factorial);
                                      delay(100);
                            } 
                            
                            printf("Factorial de %d = %d \n",numf,factorial);
                            system("Pause");
                            break;
                  case 2: 
                          free(temp);
                          printf("Liberando memoria...");
                          delay(120);
                          system("cls");
                    
                          break;                                       
             }                      
           }while(op!=2);           

}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//FUNCION PUSH
void PUSH(Tnodo *pila, Tnodo *nuevo)
    {
                (*nuevo)->sig=*pila;
                *pila=*nuevo;
                
                
                
    }
    //FUNCION POP
Tnodo POP(Tnodo *pila)
    {
                Tnodo nodo=NULL;
                if(*pila)
                {
                nodo=*pila;
                *pila=(*pila)->sig;
                nodo->sig=NULL;
                }
                return nodo;
                
                
    }        

//FUNCION SERVICIO DATO
void Servicio(Tnodo temp)
    {
                    
          system("cls");
          printf("%d \n",(temp->dato));
          system("PAUSE");
                    
                    
                    
                    
                    
    }    

    //FUNCION LLENADATOS NUMERO ALEATORIO
Tnodo llenaDatos(int i)
   {
      Tnodo nodo=NULL;
      nodo=(Tnodo)malloc(sizeof(Tdato));
      (nodo)->sig=NULL;
      (nodo)->dato=i;   
      return nodo;
   
      }
//////////////////////////////////////////////////////////////////////////////////////////////////////    
 //FUNCION VALIDA NUM            
int validanum(int n1, int n2, char *msge, char *merror)
{
	char elnum[100];
	int num;
	do{
		
		printf("\n%s",msge);
		fflush(stdin);
		gets(elnum);
		num=atoi(elnum);
		if(num<n1||num>n2)
		{
			printf("%s",merror);
			delay(250);
		}
		
	}while(num<n1||num>n2);
}
//************************************************************************
void delay(int tiempo)
{
  int i,j;
  for(i=0;i<tiempo*100;i++)
     {
	   for(j=0;j<tiempo*100;j++);
		

	 }
}

