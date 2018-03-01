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
#define AGUASCALIENTES 'AS'
#define PAUSA printf("\nPresione cualquier tecla para continuar"); getch();

//****************************************************************************
// PROTOTIPOS DE FUNCIONES
//****************************************************************************
void menu (void);
void GCURP(void);
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
		    case 1: GCURP();   break;
		}
   }while(op !=2);
}

//************************************************************************************** Generar CURP

void GCURP (void)
{
    system("cls");
	
	 int ent,i;
	
	char curp[40],Nombre[20],Appat[20],Apmat[20],dia[5],mes[5],anio[5],sexo[5];
	
    strcpy(Nombre,leecadena("Dame tu Nombre"));
    
    strcpy(Appat,leecadena("Dame tu Apeliido Paterno"));
      
    strcpy(Apmat,leecadena("Dame tu Apellido Materno"));
    
    strcpy(dia,validanum("Dame tu Dia de Nacimiento"));
    
    strcpy(mes,validanum("Dame tu Mes de Nacimiento"));
    
    strcpy(anio,validanum("Dame tu Anio de Nacimiento"));
    
    strcpy(sexo,leecadena("Hombre o Mujer"));
    
       for (i=0;i<10;i++)
            {
            	if(Appat[i]=='A'|| Appat[i]=='E' || Appat[i]=='I' || Appat[i]=='O' || Appat[i]=='U')
            	{
            		curp[1]=Appat[i];
            		i=10;
            	}
            }
     printf("\n\n\t\t\tENTIDAD FEDERATIVA\n\n");
       printf("\t\t1) AGUASCALIENTES");      printf("\t17) MORELOS \n");
       printf("\t\t2) BAJA CALIFORNIA");     printf("\t18) NAYARIT \n");
       printf("\t\t3) BAJA CALIFORNIA SUR"); printf("\t19) NUEVO LEON \n");
       printf("\t\t4) CAMPECHE\t");            printf("\t20) OAXACA \n");
       printf("\t\t5) COAHUILA\t");            printf("\t21) PUEBLA \n");
       printf("\t\t6) COLIMA\t");              printf("\t22) QUERETARO \n");
       printf("\t\t7) CHIAPAS\t");             printf("\t23) QUINTANA ROO \n");
       printf("\t\t8) CHIHUAHUA\t");           printf("\t24) SAN LUIS POTOSI \n");
       printf("\t\t9) DISTRITO FEDERAL");    printf("\t25) SINALOA \n");
       printf("\t\t10) DURANGO\t");            printf("\t26) SONORA \n");
       printf("\t\t11) GUANAJUATO\t");         printf("\t27) TABASCO \n");
       printf("\t\t12) GUERRERO\t");           printf("\t28) TAMAULIPAS \n");
       printf("\t\t13) HIDALGO\t");            printf("\t29) TLAXCALA \n");
       printf("\t\t14) JALISCO\t");            printf("\t30) VERACRUZ \n");
       printf("\t\t15) MEXICO\t");             printf("\t31) YUCATAN \n");
       printf("\t\t16) MICHUACAN\t");          printf("\t32) ZACATECAS \n");
       scanf("%d",&ent);
        if(ent==1)
          {
          	curp[11]='A';curp[12]='S'; 
          	
          }
          if(ent==2)
            {
            	 curp[11]='B';curp[12]='C'; 
            }
             if(ent==3)
               {
            	 curp[11]='B';curp[12]='S';  
               }
            if(ent==4)
              {
            	 curp[11]='C';curp[12]='C';  
              }
           if(ent==5)
             {
            	 curp[11]='C';curp[12]='L'; 
             } 
             if(ent==6)
               {
            	curp[11]='C';curp[12]='M'; 
               }  
             if(ent==7)
               {
            	curp[11]='C';curp[12]='S'; 
                }  
              if(ent==8)
                {
            	curp[11]='C';curp[12]='H'; 
                }  
               if(ent==9)
               {
			
		     	curp[11]='D';curp[12]='F'; 
            	
               }   
              if(ent==10)
                {
			
	          	curp[11]='D';curp[12]='G'; 
                }
         
            
          
        for (i=0;i<10;i++)
            {
            	if(Appat[i]!='A'&& Appat[i]!='E' && Appat[i]!='I' &&Appat[i]!='O' &&Appat[i]!='U')
            	{
            		curp[13]=Appat[i];
            		i=10;
            	}
            }
          for (i=0;i<10;i++)
            {
            	if(Apmat[i]!='A'&& Apmat[i]!='E' && Apmat[i]!='I' &&Apmat[i]!='O' &&Apmat[i]!='U')
            	{
            		curp[14]=Apmat[i];
            		i=10;
            	}
            }    
           for (i=0;i<10;i++)
            {
            	if(Nombre[i]!='A'&& Nombre[i]!='E' && Nombre[i]!='I' &&Nombre[i]!='O' &&Nombre[i]!='U')
            	{
            		curp[15]=Nombre[i];
            		i=10;
            	}
            }      
		       
         
    curp[0]=Appat[0];
    curp[2]=Apmat[0];
 	curp[3]=Nombre[0];
 	curp[4]=anio[2];
 	curp[5]=anio[3];
 	curp[6]=mes[0];
 	curp[7]=mes[1];
 	curp[8]=dia[0];
 	curp[9]=dia[1];
    curp[10]=sexo[0];
  
     
    
 	curp[16]='\0';

	printf("\nCURP:%s",curp);	
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







