//***************************************************************************************
//    LIBRERIAS
//**************************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

//****************************************************************
/// Constantes
//**********************************************************************

#define TRUE 1
#define FALSE 0
#define PAUSA printf("\nPresione cualquier tecla para continuar"); getch();

//****************************************************************************
// PROTOTIPOS DE FUNCIONES
//****************************************************************************
void menu (void);
void GRFC(void);
char* validanum(char* msge);
char* leecadena(char*msge);
void delay(int);

//****************************************************************************
// MAIN PRINCIPAL  ...  funcion principal
//****************************************************************************9

int main (void)
{
   menu();
   return 0;
}

//********************************************************************

//*****************   FUNCION MENU DESDE DONDE SE MANDA LLAMAR LAS DEMAS FUNCIONES
void menu (void)
{
   int op;
   
   do{
      system ("cls");
      printf("\n M  E   N   U");
	  printf("\n1.-GENERAR RFC");
	  printf("\n2.- Salir");
	  printf("\nESCOGE UNA OPCION.");
      scanf ("%d",&op);
	  switch(op)
	    {
		    case 1: GRFC();   break;
		}
   }while(op !=2);
}

//************************************************************************************** Generar RFC

void GRFC (void)
{
	char RFC[40],Nombre[20],Appat[20],Apmat[20],dia[5],mes[5],anio[5];
	system("cls");
	
    strcpy(Nombre,leecadena("Dame tu Nombre"));
    
    strcpy(Appat,leecadena("Dame tu Apeliido Paterno"));
    
    strcpy(Apmat,leecadena("Dame tu Apellido Materno"));
    
    strcpy(dia,validanum("Dame tu Dia de Nacimiento"));
    
    strcpy(mes,validanum("Dame tu Mes de Nacimiento"));
    
    strcpy(anio,validanum("Dame tu Anio de Nacimiento"));
	    
    RFC[0]=Appat[0];  
    RFC[1]=Appat[1];
    RFC[2]=Apmat[0];
 	RFC[3]=Nombre[0];
 	RFC[4]=anio[2];
 	RFC[5]=anio[3];
 	RFC[6]=mes[0];
 	RFC[7]=mes[1];
 	RFC[8]=dia[0];
 	RFC[9]=dia[1];
 	RFC[10]='\0';
	printf("\n%s",RFC);	
	PAUSA;
}

///**************************************************************************************

/////Funcion Validanum

char* validanum (char* msge)
{
	char cadena[40];
	int letra,i;
	system("cls");
	
	printf("%s\n",msge);
	i=0;
	do {
		letra=getch();
		if  ((letra>=48) && (letra<=57))
		    {
			printf("%c",letra);
			cadena[i]=letra;
			i++;
		    }
    	} while(letra!=13);
	     cadena[i]='\0';
	     return cadena;
}

//******************************************************************************************
// Funcion Valida letra


char* leecadena (char*msge)
      {
        int x,letra,i;
        char cadena[40];
       
        system("cls");
        printf("%s\n",msge);
        
         i=0;
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
          } while (letra!=13);
          cadena[i]='\0';
          return cadena;     
      }
      

//**************************************************************************
void delay(int tiempo)
{
  int i,j;
  for(i=0;i<tiempo*100;i++)
     {
	   for(j=0;j<tiempo*100;j++);
		

	 }
}







