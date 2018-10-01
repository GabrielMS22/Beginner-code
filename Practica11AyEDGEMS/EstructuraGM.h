
//////////////Estructura Basica Pilas,Colas,Listas,ListaCircular/////////////////

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

typedef struct tdato{
        int dato;
        struct tdato *sig;   
        }Tdato;  
        
typedef Tdato *Tnodo;  

Tnodo llenaDatos(int valor);
int validanum(int n1, int n2, char *msge, char *merror);
char* leecadena (char*msge);
void delay(int tiempo);
void GenerarTXTListaSimple(Tnodo *lista,int band);
void GenerartxtLC(Tnodo *listaC, Tnodo *fin,int band);


/////////////////////////////////////////////////////////////////////////////////
void GenerarTXTListaSimple(Tnodo *lista, int band)
   {
          Tnodo temp=NULL;   
          if(band==0)
          {
          FILE *ArchtxtL1;
          ArchtxtL1=fopen("lista1.txt","w");
                           if(*lista)
                            {
                                   temp=*lista;
                                   while(temp)
                                        {
                                          printf("%d \n",temp->dato);
                                  	      fprintf(ArchtxtL1,"%d\n",(temp->dato));
                                          temp=(temp->sig);   
                                              
                                        }           
                            }
                            else
                            {
                            printf("Lista Vacia\n");
                            system("PAUSE");
                            }   
            fclose(ArchtxtL1); 
          }
         if(band==1)
          {
                    FILE *ArchtxtL2;
                   ArchtxtL2=fopen("lista2.txt","w");
                           if(*lista)
                            {
                                   temp=*lista;
                                   while(temp)
                                        {
                                          printf("%d \n",temp->dato);
                                  	      fprintf(ArchtxtL2,"%d\n",(temp->dato));
                                          temp=(temp->sig);   
                                              
                                        }           
                            }
                            else
                            {
                            printf("Lista Vacia\n");
                            system("PAUSE");
                            }   
            fclose(ArchtxtL2); 
                    
                    
          } 
          if(band==2)
          {
                     FILE *ArchtxtL3;
                   ArchtxtL3=fopen("lista3.txt","w");
                           if(*lista)
                            {
                                   temp=*lista;
                                   while(temp)
                                        {
                                          printf("%d \n",temp->dato);
                                  	      fprintf(ArchtxtL3,"%d\n",(temp->dato));
                                          temp=(temp->sig);   
                                              
                                        }           
                            }
                            else
                            {
                            printf("Lista Vacia\n");
                            system("PAUSE");
                            }   
            fclose(ArchtxtL3);
                     
          }
  }
 
 
void GenerartxtLC(Tnodo *listaC, Tnodo *fin, int band)
{
    
    FILE *ArchivoTXTLC,*ArchivoTXTLC2,*ArchivoTXTLC3;
    Tnodo temp=NULL;  
    temp=*listaC;  
    ArchivoTXTLC=fopen("listaC1.txt","w");
    if(band==0)
	  {
		
		do{
			printf("%d ",temp->dato);
			fprintf(ArchivoTXTLC,"%d\n",(temp->dato));
			temp=(temp->sig);
		}while(temp != (*listaC) );
	
		fclose(ArchivoTXTLC);
	}
	if(band==1)
	 {
           ArchivoTXTLC2=fopen("listaC2.txt","w");
           	do{
			printf("%d ",temp->dato);
			fprintf(ArchivoTXTLC2,"%d\n",(temp->dato));
			temp=(temp->sig);
		}while(temp != (*listaC) );
		
		fclose(ArchivoTXTLC2);   
    }               
    if(band==2)
     {
            ArchivoTXTLC3=fopen("listaC3.txt","w");
           	do{
			printf("%d ",temp->dato);
			fprintf(ArchivoTXTLC3,"%d\n",(temp->dato));
			temp=(temp->sig);
		}while(temp != (*listaC) );
		
		fclose(ArchivoTXTLC3);
               
     }
    
    
                             
}   

Tnodo llenaDatos(int valor)
   {
                      
      Tnodo nodo=NULL;
      nodo=(Tnodo)malloc(sizeof(Tdato));
      nodo->sig=NULL;
      nodo->dato=valor;
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

char* leecadena (char*msge)
      {
        int x,letra,i;
        char cadena[40];
        printf("%s.",msge);
        
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


void delay(int tiempo)
{
  int i,j;
  for(i=0;i<tiempo*100;i++)
     {
	   for(j=0;j<tiempo*100;j++);
	 }
}

