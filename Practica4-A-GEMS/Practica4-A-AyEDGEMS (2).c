//Gabriel Melchor Sanchez
//***************************************************************************************
//    LIBRERIAS
//**************************************************************************************
#include "GEMSEstructService.h"
//****************************************************************
/// Constantes
//**********************************************************************
//****************************************************************************
// PROTOTIPO DE FUNCIONES                 
void menu(void);
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
     	int op,res;
	    Tnodo nuevo=NULL,cola=NULL,temp=NULL,ultimo=NULL;
	    srand(time(NULL));
	   
	    printf("ELIJA UNA OPCION \n");
	    printf("1.-AGREGAR DATOS \n");
	    printf("2.-AGREGAR INFO. ALUMNO\n");
        res=validanum(1,2,"Insertar Numero valido (1,2)\n","Que parte de numero valido no entendiste?");
        if(res==1)
          {
	    
	   do{
	    system("cls");
		printf("  M   E   N   U \n");
		printf("1.AGREGAR DATO A COLA\n");
		printf("2.SACAR DATO A COLA\n");
		printf("3.SALIR\n");
        op=validanum(1,3,"Insertar Numero valido (1,2,3)\n","Que parte de numero valido no entendiste?");
		switch(op)
		     {
                  case 1: system("cls");
                           nuevo=llenaDatos();
                           PUSH_Q(&cola,&ultimo,&nuevo);
                           printf("Dato agregado a la Cola\n");
                           system("Pause");
                           
                           break;
                  case 2:  system("cls");
                           temp=POP_Q(&cola,&ultimo);
                           if(temp)
                              {
                                   Servicio(temp);
                                   free(temp);
                                   
                  
                              }
                              else
                               {
                                   printf("Cola Vacia\n");
                                   system("pause");
                               }
                           break;
                           
                  case 3: system("cls");
                           while(cola)
                           {
                                      temp=POP_Q(&cola,&ultimo);
                                      printf("%d \n",temp->dato);
                                      free(temp);
                                      delay(80); 
                                       
                           }
                                       printf("MEMORIA LIBERADA");
                                       delay(200);                                                                      
                                       break;
                           
                         
                          
                          
                                                                 
             }                      
           }while(op!=3);      
         }
       if(res==2)
          {
            do{
	              system("cls");
		          printf("  M   E   N   U \n");
		          printf("1.AGREGAR DATO DE ALUMNO A COLA\n");
		          printf("2.SACAR DATO (POP)\n");
           	      printf("3.SALIR\n");
                  op=validanum(1,3,"Insertar Numero valido (1,2,3)\n","Que parte de numero valido no entendiste?");
		          switch(op)
		           {
                       case 1: system("cls");
                               nuevo=llenaDatosA();
                               PUSH_Q(&cola,&ultimo,&nuevo);
                               printf("Dato agregado a la Cola\n");
                               system("Pause");
                           
                               break;
                      case 2:  system("cls");
                               temp=POP_Q(&cola,&ultimo);
                               if(temp)
                                 {
                                   ServicioA(temp);
                                   free(temp);
                                   
                  
                                 }
                               else
                                 {
                                   printf("Cola Vacia\n");
                                   system("pause");
                                 }
                                break;
                           
                  case 3: system("cls");
                           while(cola)
                           {
                                      temp=POP_Q(&cola,&ultimo);
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
            
                   
                   }
                   
              }while(op!=3);      
          }   
    

}

