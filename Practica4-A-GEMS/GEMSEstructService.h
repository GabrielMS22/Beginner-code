#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

typedef struct tdato{
        int dato;
        char nombre[30];
        char appat[30];
        char apmat[30];      
        int edad;
        char sexo[9];
        int stat;
        long matri;
        struct tdato *sig;   
        }Tdato;  
        
typedef Tdato *Tnodo;
                  
Tnodo llenaDatos();       
Tnodo llenaDatosA(void);
Tnodo POP_Q(Tnodo *cola, Tnodo *ultimo);
void PUSH_Q(Tnodo *cola, Tnodo *ultimo, Tnodo *nuevo);
Tnodo POP_S(Tnodo *pila);
void PUSH_S(Tnodo *pila, Tnodo *nuevo);     
void Servicio(Tnodo temp);
void ServicioA(Tnodo temp);
void delay(int)
;int validanum(int n1, int n2, char *msge, char *merror); 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


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
