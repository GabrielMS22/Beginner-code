//Gabriel Melchor Sanchez
//    LIBRERIAS
#include "GEMSEstructService.h"
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
     	int op,num,numr,buscar,busqueda;
	    Tnodo nuevo=NULL,temp=NULL,lista=NULL,eliminar=NULL;
	   do{
	    system("cls");
		printf("  M   E   N   U \n");
		printf("1.AGREGAR DATO A LISTA\n");
		printf("2.ELIMINAR DATO DE LISTA\n");
		printf("3.DESPLEGAR(TODA LISTA)\n");
		printf("4.BUSCAR NUMERO EN LISTA \n");
		printf("5.SALIR\n");
        op=validanum(1,5,"Insertar Numero valido (1,2,3,4,5)\n","Que parte de numero valido no entendiste?");
		switch(op)
		     {
                  case 1: system("cls");
                          nuevo=llenaDatos();
                          if(Agregar(&lista,&nuevo))
                             {
                                                    printf("Nodo repetido\n");
                                                    system("PAUSE");
                                                    free(nuevo);
                             }
                             else
                               {
                                                   printf("Exito...\n");
                                                   system("PAUSE");
                               }
                                
                            break;  
                           
                  case 2:     
                          system("CLS");
                          if(lista)
                            {
                                   temp=lista;
                                   printf("Numeros que hay en lista:\n");
                                   while(temp)
                                        {
                                          Servicio(temp); 
                                          temp=temp->sig;   
                                              
                                        }
                                        
                                       
                            printf("Dime el numero que quieras eliminar");
                            num=validanum(1,3000,"Insertar Numero valido (1-3000)\n","Que parte de numero valido no entendiste?");
                            eliminar=Eliminar(&lista,num);
                            if(eliminar)
                               {
                                        free(eliminar);
                                        printf("Numero Eliminado\n");
                                        system("PAUSE");
                                        
                               }
                             else
                               {
                                                  printf("Numero no encontrado\n");
                                                  
                                                  system("PAUSE");
                                                 
                                }
                             } 
                            else
                             {
                                 printf("Lista Vacia\n");
                                 system("PAUSE");
                             }
                                  
                                 
                             break;
                            
                            
                           
                  case 3: system("cls");
                          LeerListaS(&lista);
                          system("PAUSE");
                          break;
                  case 4:  system("CLS");
                           
                           if(lista)
                             {
                                    
                                   temp=lista;
                                   printf("Numeros que hay en lista:\n");
                                   while(temp)
                                        {
                                          Servicio(temp); 
                                          temp=temp->sig;   
                                              
                                        }
                                        
                                      
                           buscar=validanum(1,3000,"Insertar Numero valido (1-3000)\n","Que parte de numero valido no entendiste?");
                           busqueda=BuscarL(&lista,buscar);
                              if(busqueda>0 && busqueda<3000) 
                                {
                                        printf("Numero encontrado\n");
                                        printf("Posicion %d\n",busqueda);
                                        system("PAUSE");
                                }
                            
                             else
                              {
                                        printf("Numero no encontrado\n");
                                        system("PAUSE");
                               } 
                              }
                             else
                              {
                                        printf("Lista Vacia\n");
                                        system("PAUSE");
                              }
                               
                            break;
                           
                  case 5: system("cls");
                          if(lista)
                            {
                                  temp=lista;
                                   while(temp)
                                        {
                                        
                                          lista=lista->sig;
                                          free(temp);
                                          temp=lista;  
                                          
                                          
                                              
                                        }
                                       
                                        
                            }
                            printf("Memoria Liberada");
                            delay(180);
                            break;        
                           
                         
                          
                          
                                                                 
             }                      
           }while(op!=5);      
}



