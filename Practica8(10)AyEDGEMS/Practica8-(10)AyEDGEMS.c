//Gabriel Melchor Sanchez
//    LIBRERIAS
#include "GEMSEstructService.h"
//**************************************************************************************
//****************************************************************
// PROTOTIPO DE FUNCIONES                 
void menu(void);


int ValidaRepetidos(Tnodo *listaC, char *palabra, Tnodo *fin);
//****************************************************************************
// MAIN PRINCIPAL  ...  funcion principal
int main (void)
{
   menu();
   return 0;
}
//****************************************************************************
// desarollo de las funciones en el mismo orden de como listamos los prototipos
//***************   FUNCION MENU DESDE DONDE SE MANDA LLAMAR LAS DEMAS FUNCIONES
void menu(void)
{
        
        srand(time(NULL)); 
     	int op,num,numr,buscar,busqueda,i,band=0,x;
        FILE *Archtxt;
        char Nombrearch[30],palabra[500],buscarp[100];
	    Tnodo nuevo=NULL,temp=NULL,listaC=NULL,eliminar=NULL,fin=NULL,agregar=NULL,aux=NULL;
	   do{
	    system("cls");
		printf("LISTA CIRCULAR PALABRAS\n");
		printf("1.AGREGAR PALABRAS A L.C.\n");
		printf("2.MOSTRAR TODA LA LISTA ORDENADA\n");
		printf("3.ELIMINAR PALABRAS L.C.\n");
		printf("4.ALMACENAR EN UN ARCHIVO DE TEXTO\n");
		printf("5.SALIR\n");
        op=validanum(1,6,"Insertar Numero valido (1,2,3,4,5)\n","Que parte de numero valido no entendiste?");
		switch(op)
		     {
                  case 1: system("cls");
                       if(band==0)
                       {        
                          fflush(stdin);
                          strcpy(Nombrearch,leecadena("Escribe el nombre del archivo, puedes probar con 'PALABRAS'"));
                          strcat(Nombrearch,".txt");
                          Archtxt=fopen (Nombrearch,"r");
                          if(!(Archtxt))
                            {
                              printf("\nNo existe el archivo %s !\n",Nombrearch);
                             }
                            else
                             { 
                               band++;               
                             while(!feof(Archtxt))
                                  {
                          
                                  fscanf(Archtxt,"%s\n",palabra);
                                  if(strlen(palabra)>=3 && ValidaRepetidos(&listaC,palabra,&fin)==0)
                                    {
                                     nuevo=llenaDatosTxt(palabra);         
                                     validaaski(&nuevo); 
                                     agregar=AgregarpalabraLCP(&listaC,&nuevo,&fin);
                                     printf("%s\n",palabra);
                                    }
          
                                  }
                                  printf("Agregado a lista\n");
                             }
                           }    
                          else
                           {
                                printf("Ya agregaste un archivo\n");
                           } 
                               system("PAUSE");
                            break;         
                  case 2:  system("CLS");
                           LeerListaCP(&listaC);
                           system("PAUSE");
                           break;
                  case 3: system("cls");
                          if(band==1)
                          {
                           fflush(stdin);
                           LeerListaCP(&listaC);
                           
                           strcpy(buscarp,leecadena("Escribe la palabra a eliminar."));
                           x=strlen(buscarp);
                           for(i=0;i<1;i++)
                               {
                                           buscarp[i]=toupper(buscarp[i]);
                               }
                               for(i=1;i<x;i++)
                                  {
                                           buscarp[i]=tolower(buscarp[i]);
                                  }    
                          	
					               aux=buscarLCP(&listaC,buscarp);
					              if(aux)
					                {
						              printf("\n\n LA PALABRA %s A SIDO ELIMINADA\n\n",aux->palabra);
						              aux=EliminarLCP(&listaC,&fin,buscarp);
						              free(aux);
								    }
                                   else
					                {
						          printf("\nNO ENCONTRADO");
					                }
                            }
                           else
                            {
                                printf("No hay palabras\n");
                            }
                            system("PAUSE");
                            break;
                  case 4: system("cls");
                          Generartxt(&listaC,&fin);
                            break;       
                            
                  case 5: system("CLS");
                          LiberarmemoriaLCP(&listaC);
                          delay(70);
                          break;           
                           
                         
                          
                          
                                                                 
             }                      
           }while(op!=5);      
}
