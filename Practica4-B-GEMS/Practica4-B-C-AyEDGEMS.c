//Gabriel Melchor Sanchez
//    LIBRERIAS
//**************************************************************************************
#include "GEMSEstructService.h"
//****************************************************************
// PROTOTIPO DE FUNCIONES                 
void menu(void);
//****************************************************************************
// MAIN PRINCIPAL  ...  funcion principal
int main (void)
{
   srand(time(NULL)); 
   menu();
   return 0;
}
//****************************************************************************
// desarollo de las funciones en el mismo orden de como listamos los prototipos
//***************   FUNCION MENU DESDE DONDE SE MANDA LLAMAR LAS DEMAS FUNCIONES
void menu(void)
{
     	int op,i,cant,pibote,pib=0;
	    Tnodo nuevo=NULL,cola=NULL,temp=NULL,ultimo=NULL;
	   do{
	    system("cls");
		printf("  M   E   N   U \n");
		printf("1.AGREGAR DATOS A LA COLA\n");
		printf("2.SACAR DATO DE COLA ORDENADOS\n");
		printf("3.SALIR\n");
        op=validanum(1,3,"Insertar Numero valido (1,2,3)\n","Que parte de numero valido no entendiste?");
		switch(op)
		     {
                  case 1: system("cls");
                          printf("Escriba la cantidad de datos a meter a la Cola.");
                          cant=validanum(1,1500,"Insertar Numero valido (1-1500)\n","Que parte de numero valido no entendiste?");
                         
                          for(i=0;i<cant;i++)
                             {
                                               
                               nuevo=llenaDatos();
                               PUSH_Q(&cola,&ultimo,&nuevo);
                             }
                                printf("Datos agregado a la Cola\n");
                                system("Pause");
                                 break;
                           
                  case 2:  system("CLS");
                           
                           while(cola)
                                 {
                                  temp=POP_Q(&cola,&ultimo);
                                   pibote=(temp)->dato;
                                 if(pibote>pib)
                                   { 
                                    pib=pibote;
                                    Servicio(temp);
                                   }
                                   free(temp);
                               
                                }
                                pib=0;
                                pibote=0;
                               printf("Cola liberada\n");
                               system("PAUSE");
                              
                               break;
                           
                  case 3: system("cls");
                           while(cola)
                                {
                                      temp=POP_Q(&cola,&ultimo);
                                      printf("%d \n",temp->dato);
                                      free(temp);
                                      delay(40); 
                                       
                                 }
                                       printf("MEMORIA LIBERADA");
                                       delay(250);                                                                      
                                       break;
                           
                         
                          
                          
                                                                 
             }                      
           }while(op!=3);      
}
