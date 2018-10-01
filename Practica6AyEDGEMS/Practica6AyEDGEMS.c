//Gabriel Melchor Sanchez
//    LIBRERIAS
#include "GEMSEstructService.h"
//**************************************************************************************
//****************************************************************
// PROTOTIPO DE FUNCIONES                 
void menu(void);
void LeerTxt(void);
void EliminarPalabra(void);
void EliminarPalabraX(void);
void AlmacenarArchtxt(void);
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
     	int op,num,numr,buscar,busqueda,i;
        FILE *Archtxt;
        char Nombrearch[30],palabra[500];
	    Tnodo nuevo=NULL,temp=NULL,lista=NULL,eliminar=NULL;
	   do{
	    system("cls");
		printf("  M   E   N   U \n");
		printf("1.AGREGAR PALABRAS\n");
		printf("2.MOSTRAR TODA LA LISTA ORDENADA\n");
		printf("3.ELIMINAR PALABRA\n");
		printf("4.ELIMINAR PALABRAS QUE EMPIEZEN CON X CARACTER\n");
		printf("5.ALMACENAR EN UN ARCHIVO DE TEXTO\n");
		printf("6.SALIR\n");
        op=validanum(1,6,"Insertar Numero valido (1,2,3,4,5)\n","Que parte de numero valido no entendiste?");
		switch(op)
		     {
                  case 1: system("cls");
                          fflush(stdin);
                          strcpy(Nombrearch,leecadena("Escriba letras unicamente"));
                          strcat(Nombrearch,".txt");
                          Archtxt=fopen (Nombrearch,"r");
                          if(!(Archtxt))
                            {
                              printf("\nNo existe el archivo %s !\n",Nombrearch);
                              system("Pause");
                   
                             }
                            else
                             { 
                             while(!feof(Archtxt))
                                  {
                          
                                  fscanf(Archtxt,"%s\n",palabra);
                                  if(strlen(palabra)>=3)
                                    {
                                     nuevo=llenaDatosTxt(palabra);          
                                     AgregarTXT(&lista,&nuevo);
                                     printf("%s\n",palabra);
                                    }
          
                                  }
                                  printf("Agregado a lista\n");
                                  system("PAUSE");
                             }
                          
                            break;  
                           
                  case 2:  system("CLS");
                           LeerListaS(&lista);
                           system("PAUSE");
                           break;
                  case 3: system("cls");
                          printf("Escribir palabra a borrar.");
                          scanf("%s",&palabra);
                          
                          eliminar=EliminarLP(&lista,palabra);
                          if(eliminar)
                             {
                                      printf("Blablabla");
                             }
                          system("PAUSE");
                           break;
                  case 4:  system("CLS");                               
                           break;
                           
                  case 5: system("cls");
                            break;       
                            
                  case 6: system("CLS");
                          break;           
                           
                         
                          
                          
                                                                 
             }                      
           }while(op!=6);      
}


 
void AlmacenarArchtxt(void)
 {
     
     
     FILE *Archtxt;
     Archtxt=fopen("PALABRAS.txt","r+b");
     if(!Archtxt)
     {
  	   Archtxt=fopen ("PALABRAS.txt","w");
     }
     
     
     
     
 }
