//Gabriel Melchor Sanchez
//    LIBRERIAS
#include "GEMSEstructService.h"
//**************************************************************************************
// PROTOTIPO DE FUNCIONES                 
void menu(void);
// MAIN PRINCIPAL  ...  funcion principal
int main (void)
{
   menu();
   return 0;
}
// desarollo de las funciones en el mismo orden de como listamos los prototipos
//***************   FUNCION MENU DESDE DONDE SE MANDA LLAMAR LAS DEMAS FUNCIONES
void menu(void)
{
        srand(time(NULL)); 
     	int op,cont,busqueda;
     	long matri;
	    Tnodo nuevo=NULL,temp=NULL,listaC=NULL,eliminar=NULL,fin=NULL,agregar=NULL;
	   do{
	    system("cls");
		printf("  M   E   N   U \n");
		printf("1.AGREGAR DATO ALUMNO (LISTA CIRCULAR)\n");
		printf("2.BUSCAR ALUMNO\n");
		printf("3.ELIMINAR ALUMNO X MATRICULA \n");
		printf("4.MOSTRAR ALUMNOS DE LISTA CIRCULAR\n");
		printf("5.SALIR\n");
        op=validanum(1,6,"Insertar Numero valido (1,2,3,4,5)\n","Que parte de numero valido no entendiste?");
		switch(op)
		     {
                  case 1: system("cls");  
                          nuevo=llenaDatosA();
                          agregar=AgregarLCA(&listaC,&nuevo,&fin);
                          if(!(agregar))
                             {
                                 printf("Agregado\n");
                             }
                            else
                             {                               
                                  printf("Dato Repetido\n");
                                  free(nuevo);
                             } 
                             system("PAUSE"); 
                             break;          
                  case 2:  system("CLS");
                          if(!(listaC))
                            {
                                       printf("Lista Vacia\n");
                                       system("PAUSE");
                                       break;
                                       
                            }          
                            LeerListaC(&listaC); 
                              printf("Escribe la Matricula a buscar.");
                              scanf("%ld",&matri);
                              busqueda=BuscarLCA(&listaC,&fin,matri);
                            if(busqueda)
                              {
                                          
                                          printf("Dato Encontrado\n");
                                          printf("Posicion %d\n",busqueda);  
                                        
                              }
                             else
                              {
                                          printf("Dato no encontrado\n");
                              }
                             
                            
                            system("PAUSE");
                            break;
                  case 3: system("cls");  
                            if(!(listaC))
                            {
                                       printf("Lista Vacia\n");
                                       system("PAUSE");
                                       break;         
                            }         
                          LeerListaC(&listaC);                 
                          printf("Escribe la Matricula a eliminar.");
                          scanf("%ld",&matri);
                          eliminar=EliminarLCA(&listaC,&fin,matri);
                            if(!(eliminar))
                              {
                                          printf("Dato no encontrado\n");                  
                              }
                             else
                              {
                                          printf("Dato Eliminado\n");
                              }
                            system("PAUSE");
                             break;
                    case 4: system("cls");  
                              if(!(listaC))
                               {
                                       printf("Lista Vacia\n");
                                       system("PAUSE");
                                       break; 
                               }  
                             LeerListaC(&listaC);          
                             system("PAUSE");
                             break;    
                    case 5: system("cls");
                            LiberarmemoriaLCA(&listaC);
                            delay(150);
                             break;                                                  
             }                      
           }while(op!=5);      
}
