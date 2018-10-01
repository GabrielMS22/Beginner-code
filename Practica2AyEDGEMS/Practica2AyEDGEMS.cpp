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
        char nombre[30];
        char appat[30];
        char apmat[30];      
        int edad;
        char sexo[9];
        int stat;
        long matri;
        struct tdato *sig; 
        int dato;      
        }Tdato;        
        
        
typedef Tdato *Tnodo;

//****************************************************************************
// PROTOTIPO DE FUNCIONES                 
Tnodo llenaDatos();     
Tnodo llenaDatosA();  
Tnodo POP(Tnodo *pila);
void PUSH(Tnodo *pila, Tnodo *nuevo);
void Servicio(Tnodo temp);
void ServicioA(Tnodo temp);
void menu(void);
void num(void);
void datalum(void);
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
   srand(time(NULL));
   int res;
   printf("  M   E   N   U \n");
   printf("1.-Pila con num Aleatorio\n2.-Pila con Datos de Alumno\n");
   res=validanum(1,2,"Insertar Numero valido (1,2)\n","Que parte de numero valido no entendiste?");
   if(res==1)
     {
             num();
     }
   else
     {
             datalum();       
     }
     
     
 }
 
void num(void)
{
     
	int op;
	Tnodo nuevo=NULL,pila=NULL,temp=NULL;
	srand(time(NULL));
	
	   do{
	    system("cls");
		printf("  M   E   N   U \n");
		printf("1.PUSH\n");
		printf("2.POP\n");
		printf("3.SALIR\n");
		printf("4.REGRESAR A MENU ANTERIOR\n");
        op=validanum(1,4,"Insertar Numero valido (1,2,3,4)\n","Que parte de numero valido no entendiste?");
		
		 
		switch(op)
		     {
                  case 1: 
                       system("cls");
                       nuevo=llenaDatos();
                       PUSH(&pila,&nuevo);
                       printf("Numero agregado a LIFO\n");
                       system("PAUSE");                  
                          break;
                  case 2: 
                       system("CLS");
                       temp=POP(&pila);
                       if(temp)
                         {
                          Servicio(temp);
                          free(temp);
                          }
                        else
                          {
                          printf("Pila Vacia\n");
                          system("pause");
                          
                          }
                          break;
                    case 3: 
                           system("cls");
                           while(pila)
                           {
                                      temp=POP(&pila);
                                      printf("...\n");
                                      printf("%d \n",(temp->dato));
                                      free(temp);
                                      delay(80);    
                                      }
                                       printf("MEMORIA LIBERADA");
                                      delay(200);
                                      break;
                           
                           
                    case 4:
                           free(temp);
                           system("cls");
                           menu();    
                           break;  
                        
                  
             }                      
           }while(op!=3);           

}
void datalum(void)
{
     
	int op;
	Tnodo nuevo=NULL,pila=NULL,temp;
	srand(time(NULL));
	
	   do{
	    system("cls");
		printf("  M   E   N   U \n");
		printf("1.PUSH\n");
		printf("2.POP\n");
		printf("3.SALIR\n");
		printf("4.REGRESAR\n");
        op=validanum(1,4,"Insertar Numero valido (1,2,3,4)\n","Que parte de numero valido no entendiste");
		
		 
		switch(op)
		     {
                  case 1: 
                       system("cls");
                       nuevo=llenaDatosA();
                       PUSH(&pila,&nuevo);
                       printf("Registro agregado a LIFO\n");
                       system("PAUSE");                  
                          break;
                  case 2:     
                          system("CLS");
                          temp=POP(&pila);
                          if(temp)
                            {
                            ServicioA(temp);
                            free(temp);
                            }
                        else
                          {
                          printf("Pila Vacia\n");
                          system("pause");
                          
                          }
                          break;
                     
                          
                    case 3: 
                          system("cls");
                           while(pila)
                           {
                                      temp=POP(&pila);
                                      printf("...\n");
                                      printf("Nombre :%s \n",(temp->nombre));
                                      printf("Apellido Paterno :%s \n",(temp->appat));
                                      printf("Apellido Materno :%s \n",(temp->apmat));
                                      printf("Sexo :%s \n",(temp->sexo));
                                      printf("Edad :%d \n",(temp->edad));
                                      printf("Status: %d \n",(temp->stat));
                                      printf("Matricula: %ld \n",(temp->matri));
                                      free(temp);
                                      delay(130);
                                      
                                      }
                                      printf("MEMORIA LIBERADA");
                                      delay(200);
                                      break;
                           
                           
                      case 4:
                             free(temp);
                             system("cls");
                             menu();
                             break;      
                            
                        
                  
                  
             }                      
           }while(op!=3);           

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
//FUNCION SERVICIO ALUMNOS    
void ServicioA(Tnodo temp)
    {
                    
          system("cls");
           printf("Nombre :%s \n",(temp->nombre));
           printf("Apellido Paterno :%s \n",(temp->appat));
           printf("Apellido Materno :%s \n",(temp->apmat));
           printf("Sexo :%s \n",(temp->sexo));
           printf("Edad :%d \n",(temp->edad));
           printf("Status: %d \n",(temp->stat));
           printf("Matricula: %ld \n",(temp->matri));
           system("PAUSE");
                    
                    
                    
                    
                    
    }  
        
    //FUNCION LLENADATOS NUMERO ALEATORIO
Tnodo llenaDatos(void)
   {
      Tnodo nodo=NULL;
      nodo=(Tnodo)malloc(sizeof(Tdato));
      (nodo)->sig=NULL;
      (nodo)->dato=rand()%50;
      return nodo;
      
      }
      
      //FUNCION LLENADATOS REGISTROS ALUMNOS
    
Tnodo llenaDatosA(void)
   {
                      
       Tnodo nodo=NULL;
       nodo=(Tnodo)malloc(sizeof(Tdato));
       (nodo)->sig=NULL;
       
         int sexo;
         char NombreFem[40][30]={" CECILIA"," LILIANA"," LIDIA"," KAREN"," MARIA"," ITZEL"," DENISSE"," PATRICIA"," MELISSA"," YURIANA"," JASMIN"," CASSANDRA"," YULISA"," YESENIA"," DANIELA"," ALEJANDRA"," LUZ"," ERIKA"," JACKELINE"," SOL"," MARIANA"," ELSA"," CAROLINA"," KARINA"," MIRANDA"," DULCE"," CARMEN"," CATALINA"," SARAI"," REBECA"," SALMA"," TAMARA", " ZULEMA"," SELENE"," MIRIAN"," ANDREA"," MONICA"," BLANCA"," ROSA", " GENESIS"};
         char NombreMas[140][30]={" GABRIEL"," RAFAEL"," BRANDON"," COMBO"," ERICK"," EDGAR"," MESSI"," HECTOR"," IGOR"," JOVANNY"," JOHANN"," ROMULO"," PEDRO"," DAVID"," BERNARDO"," ENRIQUE"," MARCO"," GERARDO"," RICARDO"," JHONATHAN"," ALBERTO"," LUIS"," GUILLERMO"," LUIS"," VALENTIN", " ALAN"," OSCAR"," ANTONIO"," JAVIER"," ISMAEL"," IVAN"," CESAR"," ALEJANDRO"," RENE"," CALEB"," MARIO"," LUIGI"," AARON"," DIEGO"," ELBRAYAN", " ADAN","ADELIO ","ADRIANO ","AGUSTIN ","ALANZO ","ALBERTO ","ALEJANDRO ","ALFONSO ","ALFREDO ","ALONSO ","ALVARO ","ALVINO ","AMADEO ","AMADO ","ANDREO ","ANDRES ","ANGEL ","ANGELINO ","ANGELITO ","ANGELO ","ANIBAL ","ANTONIO ","AQUILA ","AQUILINO ","ARCHIBALDO ","ARLO ","ARMANDO ","ARNOLDO ","ARTURO ","AURELIO ","BARTOLO ","BELTRAN ","BEMABE ","BENEDICTO ","BERNARDO ","BERTO ","BLANCO ","CALVINO ","CARLOS ","CESAR ","CHAVEZ ","CHAYO ","CICERON ","CLAUDIO ","CONSTANTINO ","CORNELIO ","CORTEZ ","CRISTIAN ","CRISTIANO ","CRISTOBAL ","CRISTOPHER ","DARIO ","EDUARDO ","EFRAIN ","ELIAS ","ELOY ","ELVIO ","EMANUEL ","EMILIO ","ENRIQUE ","ERASMO ","ERNESTO ","ESEQUIEL ","ESTEBAN ","ESTEFAN ","ESTEVAN ","EUGENIO ","EVERARDO ","EZEQUIEL ","FAUSTO ","FEDERICO ","FELIPE ","FELIX ","FERMIN ","FERNANDO ","FIDEL ","FLORINIO ","FRANCISCO ","FRESCO ","GABRIEL ","GALTERO ","GASPAR ","GERARDO ","GERMAN ","GILBERTO ","GREGORIO ","GUADALUPE ","GUILLERMO ","GUSTAVO ","HECTOR ","ABRAHAM ","HERIBERTO ","HERNAN ","HIDALGO ","HUGO ","HUMBERTO ","JAVIER ","JUAQUIN ","JORGE ","OSCAR "};
         char Apellido[50][30]={" MELCHOR"," YEPIZ"," GUERRERO"," BELTRAN"," CORTEZ"," CRUZ"," DIAZ"," DOMINGUEZ"," SALAZAR"," ESTRADA"," FLORES"," FERNANDEZ"," GONZALEZ"," GOMEZ"," JHONSON"," HUERTA"," INFANTE"," IGLESIAS"," JIMENEZ"," JUAREZ"," LOPEZ"," LEON"," MARTINEZ"," MORENO"," NAVARRO"," NIETO"," ORTIZ"," OJEDA"," PEREZ"," PINEDA"," QUINTANA"," QUESADA"," RAMIREZ"," RODRIGUEZ"," SANCHEZ"," SANTANA"," TORRES"," TRUJILLO"," URIBE"," URBANO"," VEGA"," VIDAL"," ZAVALA"," ZAPATA"," GALINDO"," GARCIA"," ACOSTA"," AGUILERA"," WILLIAMS"," EZEQUIAZ"};
         sexo=(rand()%2)+1;
          
         if (sexo==1)
            {
             strcpy(nodo->nombre,NombreMas[(rand()%140)]);
             strcpy(nodo->sexo,"MASCULINO");
            }
            else
            { 
              strcpy(nodo->nombre,NombreFem[(rand()%40)]);
              strcpy(nodo->sexo,"FEMENINO");
            }
             strcpy(nodo->appat,Apellido[(rand()%50)]);
             strcpy(nodo->apmat,Apellido[(rand()%50)]);
             (nodo)->edad=(rand()%20)+17;
             (nodo)->stat=1;
             (nodo)->matri=(rand()%99000)+300000-(rand()%99);
             return nodo;            
      }                     
                 
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

