//Gabriel Melchor Sanchez
//    LIBRERIAS
#include "EstructuraGM.h"
#include "ServicioGM.h"
#include "PilaGM.h"
#include "ColaGM.h"
#include "ListasimpleGM.h"
#include "ListacircularGM.h"
//**************************************************************************************
//****************************************************************
// PROTOTIPO DE FUNCIONES                 
void menu(void);
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
     	int op,band=0;
     	FILE *Archtxt;
        char Nombrearch[30],palabra[500],buscarp[100];
	    Tnodo nuevo=NULL,temp=NULL,pila=NULL,cola=NULL,lista=NULL,listaC=NULL,fin=NULL,ultimo=NULL,recibir=NULL;
	   do{
	    system("cls");
		printf("INSTRUCCIONES ARCHIVO DE TEXTO (COLA,PILA,LISTA SIMPLE, LISTA CIRCULAR)\n");
		printf("\nEl programa leera las instrucciones del archivo Instrucciones.txt\n");
		printf("los archivos de texto generados estaran en la raiz de este programa\n\n");
		printf("1-INICIAR INSTRUCCIONES DE TXT\n");
		printf("2-SALIR\n");
        op=validanum(1,2,"Insertar Numero valido (1,2)\n","Que parte de numero valido no entendiste?");
		switch(op)
		     {
                  case 1: system("cls");
                          Archtxt=fopen("Instrucciones.txt","r");
                           while(!feof(Archtxt))
                                  {
                                     fscanf(Archtxt,"%s\n",palabra);
                                     if(strcmp(palabra,"ADD")==0)
                                       {
                                                           system("CLS");
                                                           printf("%s\n",palabra);
                                                           int valor=0; 
                                                           fscanf(Archtxt,"%s\n",palabra);
                                                           valor=atoi(palabra);
                                                           printf("%d\n",valor);
                                                           nuevo=llenaDatos(valor);
                                                           PUSH_S(&pila,&nuevo);
                                                           nuevo=llenaDatos(valor);
                                                           PUSH_Q(&cola,&ultimo,&nuevo);
                                                           nuevo=llenaDatos(valor);
                                                           AgregarLS(&lista,&nuevo);
                                                           nuevo=llenaDatos(valor);
                                                           AgregarLC(&listaC,&nuevo,&fin);                                                           
                                                           printf("NUMERO %d AGREGADO A ESTRUCTURAS\n",valor);
                                                           system("PAUSE");
                                         
                                       }
                                       if(strcmp(palabra,"VIEW")==0)
                                         {
                                                               system("CLS");  
                                                               printf("%s.\n",palabra);
                                                               printf("DATOS DE LISTA SIMPLE\n");
                                                               LeerListaS(&lista);
                                                               printf("DATOS DE LISTA CIRCULAR\n");
                                                               LeerListaC(&listaC); 
                                                               system("pause");
                                        }
                                       if(strcmp(palabra,"PRINT")==0)
                                         {
                                                      system("CLS");
                                                      if(band==2)
                                                        {
                                                            GenerarTXTListaSimple(&lista,band);                                                             
                                                            GenerartxtLC(&listaC,&fin,band);
                                                            printf("\nLista3.txt y ListaC3 Creadas con Exito\n!");    
                                                            band++;
                                                        }                                                     
                                                      if(band==1)
                                                         {
                                                            GenerarTXTListaSimple(&lista,band);                                                              
                                                            GenerartxtLC(&listaC,&fin,band);
                                                            printf("\nLista2.txt y ListaC2 Creadas con Exito\n!");  
                                                            band++;
                                                         }
                                                      if(band==0)
                                                        {
                                                            GenerarTXTListaSimple(&lista,band);                                                             
                                                            GenerartxtLC(&listaC,&fin,band);
                                                            printf("\nLista1.txt y ListaC1 Creadas con Exito\n!");    
                                                            band++;
                                                        }
                                                      system("PAUSE");                                                              
                                         }
                                        if(strcmp(palabra,"DELETE")==0)
                                          {
                                                                                system("CLS");
                                                                                int valor;
                                                                                fscanf(Archtxt,"%s\n",palabra);
                                                                                valor=atoi(palabra);
                                                                                EliminarLS(&lista,valor);
                                                                                printf("\nNumero %d Eliminado de Lista\n\n",valor);
                                                                                valor=atoi(palabra);
                                                                                EliminarLCD(&listaC,&fin,valor);
                                                                                printf("\nNumero %d Eliminado de Lista Circular\n\n",valor);
                                                                                system("PAUSE");
                                                                       
                                                                       
                                          } 
                                         if(strcmp(palabra,"DELETElistaC")==0)
                                            {
                                                                                system("CLS");
                                                                                int valor;
                                                                                fscanf(Archtxt,"%s\n",palabra);
                                                                                valor=atoi(palabra);
                                                                                EliminarLCD(&listaC,&fin,valor);
                                                                                printf("\nNumero %d Eliminado de Lista Circular\n\n",valor);
                                                                                system("PAUSE");
                                                                          
                                            }
                                           if(strcmp(palabra,"DELETElista")==0)
                                              {
                                                                                system("CLS");
                                                                                int valor;
                                                                                fscanf(Archtxt,"%s\n",palabra);
                                                                                valor=atoi(palabra);
                                                                                EliminarLS(&lista,valor);
                                                                                printf("\nNumero %d Eliminado de Lista\n\n",valor);
                                                                                system("PAUSE");                               
                                              } 
                                            if(strcmp(palabra,"ADDpila")==0)
                                              {
                                                                                system("CLS");
                                                                               
                                                                                int valor;
                                                                                fscanf(Archtxt,"%s\n",palabra);
                                                                                valor=atoi(palabra);
                                                                                nuevo=llenaDatos(valor);
                                                                                PUSH_S(&pila,&nuevo);
                                                                                printf("\nNumero %d agregado a PILA\n\n",valor);
                                                                                system("PAUSE");
                                              }
                                              if(strcmp(palabra,"ADDlistaC")==0)
                                                {
                                                                                printf("Agrega a lista Circulareana\n");
                                                }
                                                if(strcmp(palabra,"ADDcola")==0)
                                                   {
                                                                                system("CLS");
                                                                                
                                                                                int valor;
                                                                                fscanf(Archtxt,"%s\n",palabra);
                                                                                valor=atoi(palabra);
                                                                                nuevo=llenaDatos(valor);
                                                                                PUSH_Q(&cola,&ultimo,&nuevo);
                                                                                printf("\nNumero %d agregado a Cola\n\n",valor);
                                                                                system("PAUSE");
                                                   }
                                                
                                                if(strcmp(palabra,"POPcola")==0)
                                                  {
                                                       
                                                                                system("CLS");
                                                                                Tnodo valor=NULL;
                                                                                valor=POP_Q(&cola,&ultimo);
                                                                                printf("\nPOP a Cola realizado con Exito\n\n");
                                                                                printf("Numero eliminado: %d\n",(valor->dato));
                                                                                system("PAUSE");                        
                                                  }
                                                 if(strcmp(palabra,"POPpila")==0)
                                                   {
                                                       
                                                                                system("CLS");
                                                                                Tnodo valor=NULL;
                                                                                valor=POP_S(&cola);
                                                                                printf("\nPOP a Pila realizado con Exito\n\n");
                                                                                printf("Numero eliminado: %d\n",(valor->dato));
                                                                                system("PAUSE");                        
                                                   }
                                                   if(strcmp(palabra,"EXIT")==0)
                                                    {
                                                                system("CLS");
                                                                Tnodo temp=NULL;
                                                                       while(pila)
                                                                             {
                                                                              temp=POP_S(&pila);
                                                                               printf("...\n");
                                                                              printf("%d \n",(temp->dato));
                                                                              free(temp);
                                                                              }
                                                                                while(cola)
                                                                                     {
                                                                                     temp=POP_Q(&cola,&ultimo);
                                                                                     printf("%d \n",temp->dato);
                                                                                     free(temp);
                                                                                     delay(80);                                       
                                                                                     }        
                                                                LiberarmemoriaLS(&lista);
                                                                LiberarmemoriaLCA(&listaC);                                         
                                                                printf("MEMORIA DE PILA LIBERADA\n");
                                                                printf("MEMORIA DE COLALIBERADA\n");
                                                                printf("MEMORIA DE LISTA SIMPLE LIBERADA\n");
                                                                printf("MEMORIA DE LISTA CIRCULAR LIBERADA\n");
                                                                               
                                                                               
                                                    }
                                                    if(strcmp(palabra,"ADDlista")==0)
                                                      {
                                                                                system("CLS");
                                                                                int valor;
                                                                                fscanf(Archtxt,"%s\n",palabra);
                                                                                valor=atoi(palabra);
                                                                                nuevo=llenaDatos(valor);
                                                                                AgregarLS(&lista,&nuevo);
                                                                                printf("\nNumero %d agregado a Lista\n\n",valor);
                                                                                system("PAUSE");
                                                                                     
                                                                                     
                                                      }
                                              
                                                                           
                                    }
          
                          fclose(Archtxt);
                          system("PAUSE");                                                  
             }                      
           }while(op!=2);      
}
