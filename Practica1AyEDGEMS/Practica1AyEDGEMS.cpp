//Gabriel Melchor Sanchez
//***************************************************************************************
//    LIBRERIAS
//**************************************************************************************
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

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
        }Talumno;
        
//****************************************************************************
// PROTOTIPOS DE FUNCIONES
//****************************************************************************
void menu (void);
void delay(int);
Talumno Agregar(void);
void BusquedaD(Talumno Valum[], int limit);
void BusquedaOD(Talumno Valum[], int limit);
void Ordenar(Talumno Valum[], int limit);
void imprDatos(Talumno Valum[],int limit);
void Archtext(Talumno Valum[], int limit);
void Archbin(Talumno Valum[], int limit);
void LeerArchbin();
int BusquedaSecD(Talumno Valum[],int matricula,int n);
int BusquedaSecO(Talumno Valum[],int matricula,int n);
int burbuja(Talumno Valum[], int n);
int validanum(int n1, int n2, char *msge, char *merror);
  
  
//****************************************************************************
// MAIN PRINCIPAL  ...  funcion principal
//****************************************************************************

int main (void)
{
   srand(time(NULL)); 
   menu();
   return 0;
}

//****************************************************************************
// desarollo de las funciones en el mismo orden de como listamos los prototipos
//****************************************************************************

//*****************   FUNCION MENU DESDE DONDE SE MANDA LLAMAR LAS DEMAS FUNCIONES
void menu(void)
{
	int op,i,limit=0,band=FALSE,matric,busqueda,j=0;
	Talumno reg[200];
	srand(time(NULL));
	
	do{
		system("cls");
		printf("  M   E   N   U \n");
		printf("1.Agregar 5 Registros (Maximo 200) \n");
		printf("2.Buscar Por Matricula\n");
		printf("3.Ordenar Por Matricula\n");
		printf("4.Imprimir (30 en 30)\n");
		printf("5.Generar Archivo de Texto (Salida) \n");
		printf("6.Generar Archivo Binario (Salida) \n");
		printf("7.Imprimir Arch Bin\n");
		printf("8.Salir\n");
		op=validanum(1,8,"Insertar Numero valido (1-8)\n","Que parte de numero valido no entendiste?");
		
		switch(op)
	        	{
		      	case 1:  system("cls");                         
		      	         if(limit<200)
			                {
			               	 for (i=0;i<5;i++)
			                     {
			                 	  reg[j]=Agregar();
			            	      j++;			            	
			                      }  				               
			                      limit=limit+5;
			                      band=FALSE;			               			               
			                      printf("5 Registros agregados");			               			             			               			             			             				            			   	
			                 }                          
			                else			            
			                 {
			              	 printf("Solo se pueden agregar 200 registros");
			              	 PAUSA;
			                 }
			             
                  		     PAUSA;			            				            			            	
						     break;
                         						 
		    	case 2:     if (band==FALSE)
			                   {
		               	              BusquedaD(reg,limit);
                               }           			                 
						      else
                               {
                                 	      BusquedaOD(reg,limit);			                                           
                               }
                               break;			
			              		
					
		        case 3: system("cls");
                        burbuja(reg,limit);
				        printf("Matriculas Ordenadas");
				        band=TRUE;
				        PAUSA;
				        break;
						
			    case 4:	system("cls");
                        imprDatos(reg,limit);		            				            			            	
					    break;
						
				case 5:	system("cls");
                        Archtext(reg,limit);	
			            PAUSA;			            				            			            	
						break;	
                      
     	        case 6:	system("cls");
                        Archbin(reg,limit);                         
     	                PAUSA;			            				            			            	
					    break;
					    
				case 7:	system("cls");
                        LeerArchbin();                         
     	                PAUSA;			            				            			            	
					    break;	    
			             	
                }
		
		
	}while(op!=8);
}


//**************************************************************************************
Talumno Agregar(void)
  {
    fflush(stdin);
    int i,sexo;   
    long num;
    Talumno reg;
    char NombreFem[40][30]={" CECILIA"," LILIANA"," LIDIA"," KAREN"," MARIA"," ITZEL"," DENISSE"," PATRICIA"," MELISSA"," YURIANA"," JASMIN"," CASSANDRA"," YULISA"," YESENIA"," DANIELA"," ALEJANDRA"," LUZ"," ERIKA"," JACKELINE"," SOL"," MARIANA"," ELSA"," CAROLINA"," KARINA"," MIRANDA"," DULCE"," CARMEN"," CATALINA"," SARAI"," REBECA"," SALMA"," TAMARA", " ZULEMA"," SELENE"," MIRIAN"," ANDREA"," MONICA"," BLANCA"," ROSA", " GENESIS"};
    char NombreMas[140][30]={" GABRIEL"," RAFAEL"," BRANDON"," COMBO"," ERICK"," EDGAR"," MESSI"," HECTOR"," IGOR"," JOVANNY"," JOHANN"," ROMULO"," PEDRO"," DAVID"," BERNARDO"," ENRIQUE"," MARCO"," GERARDO"," RICARDO"," JHONATHAN"," ALBERTO"," LUIS"," GUILLERMO"," LUIS"," VALENTIN", " ALAN"," OSCAR"," ANTONIO"," JAVIER"," ISMAEL"," IVAN"," CESAR"," ALEJANDRO"," RENE"," CALEB"," MARIO"," LUIGI"," AARON"," DIEGO"," ELBRAYAN"," ADAN","ADELIO ","ADRIANO ","AGUSTIN ","ALANZO ","ALBERTO ","ALEJANDRO ","ALFONSO ","ALFREDO ","ALONSO ","ALVARO ","ALVINO ","AMADEO ","AMADO ","ANDREO ","ANDRES ","ANGEL ","ANGELINO ","ANGELITO ","ANGELO ","ANIBAL ","ANTONIO ","AQUILA ","AQUILINO ","ARCHIBALDO ","ARLO ","ARMANDO ","ARNOLDO ","ARTURO ","AURELIO ","BARTOLO ","BELTRAN ","BEMABE ","BENEDICTO ","BERNARDO ","BERTO ","BLANCO ","CALVINO ","CARLOS ","CESAR ","CHAVEZ ","CHAYO ","CICERON ","CLAUDIO ","CONSTANTINO ","CORNELIO ","CORTEZ ","CRISTIAN ","CRISTIANO ","CRISTOBAL ","CRISTOPHER ","DARIO ","EDUARDO ","EFRAIN ","ELIAS ","ELOY ","ELVIO ","EMANUEL ","EMILIO ","ENRIQUE ","ERASMO ","ERNESTO ","ESEQUIEL ","ESTEBAN ","ESTEFAN ","ESTEVAN ","EUGENIO ","EVERARDO ","EZEQUIEL ","FAUSTO ","FEDERICO ","FELIPE ","FELIX ","FERMIN ","FERNANDO ","FIDEL ","FLORINIO ","FRANCISCO ","FRESCO ","GABRIEL ","GALTERO ","GASPAR ","GERARDO ","GERMAN ","GILBERTO ","GREGORIO ","GUADALUPE ","GUILLERMO ","GUSTAVO ","HECTOR ","ABRAHAM ","HERIBERTO ","HERNAN ","HIDALGO ","HUGO ","HUMBERTO ","JAVIER ","JUAQUIN ","JORGE ","OSCAR "};
    char Apellido[50][30]={" MELCHOR"," YEPIZ"," GUERRERO"," BELTRAN"," CORTEZ"," CRUZ"," DIAZ"," DOMINGUEZ"," SALAZAR"," ESTRADA"," FLORES"," FERNANDEZ"," GONZALEZ"," GOMEZ"," JHONSON"," HUERTA"," INFANTE"," IGLESIAS"," JIMENEZ"," JUAREZ"," LOPEZ"," LEON"," MARTINEZ"," MORENO"," NAVARRO"," NIETO"," ORTIZ"," OJEDA"," PEREZ"," PINEDA"," QUINTANA"," QUESADA"," RAMIREZ"," RODRIGUEZ"," SANCHEZ"," SANTANA"," TORRES"," TRUJILLO"," URIBE"," URBANO"," VEGA"," VIDAL"," ZAVALA"," ZAPATA"," GALINDO"," GARCIA"," ACOSTA"," AGUILERA"," WILLIAMS"," EZEQUIAZ"};
    
      for(i=0;i<5;i++)
         {               
                         
                         
         reg.matri=(rand()%99000)+300000-(rand()%99);
         strcpy(reg.appat,Apellido[(rand()%50)]);
         strcpy(reg.apmat,Apellido[(rand()%50)]);
         sexo=(rand()%2)+1;
         reg.edad=(rand()%20)+17;
         reg.stat=1;     
         
             
         if (sexo==1)
            {
                     
                     
             strcpy(reg.nombre,NombreMas[(rand()%20)]);
             strcpy(reg.sexo,"MAS");
             
             
            }
          else
            {
                          
                           
              strcpy(reg.nombre,NombreFem[(rand()%20)]);
              strcpy(reg.sexo,"FEM");
            }
            
          }
                   
           return reg;  
  }
  
//**************************************************************************************  \

void BusquedaD(Talumno Valum[], int limit)
     {
                       
                       int busqueda;
                       long matric;
                       imprDatos(Valum,limit);
                       printf("Inserte la matricula a buscar.");
                       scanf("%ld",&matric);
                       busqueda=BusquedaSecD(Valum,matric,limit);
                       if (busqueda==-1)
                           {
                                        printf("Matricula no encontrada\n");                                                                               
                           }
                          else
                           {
                                        printf("la matricula esta en la posicion %d\n",busqueda);
                           }         
                         
                          
                       system("PAUSE");
                       
                       
     }
//**************************************************************************************  
void BusquedaOD(Talumno Valum[], int limit)
     {
                       
                       int busqueda;
                       long matric;
                       imprDatos(Valum,limit);
                       printf("Inserte la matricula a buscar.");
                       scanf("%ld",&matric);
                       busqueda=BusquedaSecO(Valum,matric,limit);
                       if (busqueda==-1)
                           {
                                        printf("Matricula no encontrada\n");                                                                               
                           }
                          else
                           {
                                        printf("la matricula esta en la posicion %d\n",busqueda);
                           }         
                         
                          
                       system("PAUSE");
                       
                       
     }
//**************************************************************************************



int burbuja(Talumno Valum[], int limit)
{
	int band;
	int i,j,aux;
	for(i=0;i<limit-1;i++)
	for(j=i+1;j<limit;j++)
	if(Valum[j].matri<Valum[i].matri)
	{
		 aux=Valum[j].matri;
		 Valum[j].matri=Valum[i].matri;
		 Valum[i].matri=aux;
	}
	band=TRUE;
	
}
//***********
void imprDatos(Talumno Valum[],int limit)
{
	
 
   system("cls"); 
   int i,k=0;
   printf("________________________________________________________________________________");
   printf(" NOMBRE             A.PATERNO          A.MATERNO       EDAD SEXO STAT MATRICULA\n");
   printf("________________________________________________________________________________");
   
    
    for(i=0;k<limit;i++)
       {                                                                                           
       for(i=0;i<30 && k<limit;i++)
          {
        
           printf("%-18s %-18s %-18s %3d %3s %3d %10ld\n",Valum[k].nombre,Valum[k].appat,Valum[k].apmat,Valum[k].edad,Valum[k].sexo,Valum[k].stat,Valum[k].matri); 
           k++;
           
          }
          system("PAUSE");
      }
      
      
      
    
       
	   
}

void Archtext(Talumno Valum[],int limit)
{
  
  int i;
  FILE *arch;//Direccion de memoria
  char Nombrearch[30];
  fflush(stdin);
  printf("Que nombre quieres ponerle al archivo?.");
  gets(Nombrearch);
  strcat(Nombrearch, ".txt");
  arch=fopen (Nombrearch,"r+");
  //!arch sera null si fallo al abrir el archivo, por que no existe o error 
  //arch tendra la direccion de memoria donde esta alojado el archivo fisicamente
   if(!arch)//arch verdadero si tiene direccion de memoria y falso si es NULL
    {
  	arch=fopen (Nombrearch,"w+");
    }  
   fprintf(arch," NOMBRE             A.PATERNO          A.MATERNO       EDAD SEXO STAT MATRICULA\n");
   
   
  
   for(i=0;i<limit;i++)
   {
    
    
    fprintf(arch,"%-18s %-18s %-18s %3d %3s %3d %10ld\n",Valum[i].nombre,Valum[i].appat,Valum[i].apmat,Valum[i].edad,Valum[i].sexo,Valum[i].stat,Valum[i].matri);
   	
    
   }
   printf("TOTAL DE REGISTROS GENERADOS : %d\n\n",limit);
   
   fclose(arch);
   printf("ARCHIVO GENERADO CON EXITO!\n");
   
  
}


void Archbin(Talumno reg[],int limit)
{
   system("cls"); 
   FILE *archB;
   archB = fopen("Registro.bin","ab"); 
   int i;
   printf("________________________________________________________________________________");
   printf(" NOMBRE             A.PATERNO          A.MATERNO       EDAD SEXO STAT MATRICULA\n");
   printf("________________________________________________________________________________");

    for(i=0;i<limit;i++)
       {
                    
      
       fwrite(&reg[i],sizeof(struct tdato),1,archB); 
       }
    
    
    fclose(archB);
    printf("Archivo Binario Generado!");
    
       
	   
}

//**************************************************************************************
int BusquedaSecD(Talumno Valum[],int matricula,int n)
{
	    int i;
  		for(i=0;i<n;i++)
  		  {
    		if(Valum[i].matri==matricula)
    		   {
      		       return(i+1);
    		   }
  		  }
  	 return -1;
}

//***********
int BusquedaSecO(Talumno Valum[],int matricula,int n)
{
   
    int i;
    for (i=0;i<n&&(Valum[i].matri<=matricula);i++)
        {
        if (Valum[i].matri==matricula)
           {
                      return (i+1);                      
           }               
                                                           
        }
       return -1;         
}

//***********
//***********PROGRAMA QUE IMPRIME LOS DATOS DEL ARCHIVO BINARIO*****************  
void LeerArchbin(void)
{
   int i;
   Talumno reg;
   FILE *archB;
   
   archB=fopen("Registro.bin","rb");
   system ("cls");
   printf("MATRICULA\tNOMBRE\t\tA.PATERNO\tA.MATERNO\t  EDAD  SEXO \n");
   
    
   while(fread(&reg,sizeof(struct tdato),1,archB));
        {
          
              
              
            
               printf("%-18s %-18s %-18s %3d %3s %3d %10ld\n",reg.nombre,reg.appat,reg.apmat,reg.edad,reg.sexo,reg.stat,reg.matri); 
        }       
                   
   
       
   fclose(archB);
   
	
	
	
	
	


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

