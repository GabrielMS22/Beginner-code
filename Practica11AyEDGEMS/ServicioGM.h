////////////////////SERVICIOS///////////////////

void Servicio(Tnodo temp);
void ServicioL(Tnodo temp);
void LiberarmemoriaLCA(Tnodo *listaC);
void LiberarmemoriaLS(Tnodo *lista);



void Servicio(Tnodo temp)
     {
          printf("%d \n",(temp->dato));    
    }    
    
void ServicioL(Tnodo temp)
    {         
           printf("%s \n",(temp->dato));               
    }
void LiberarmemoriaLS(Tnodo *lista)
{
     Tnodo temp=NULL;
                           if(*lista)
                            {
                                  temp=*lista;
                                   while(temp)
                                        {  
                                          *lista=(*lista)->sig;
                                          free(temp);
                                          temp=*lista;  
     
                                        }     
                            }
                            
}
////////////////Liberacion de memoria Listas Circulares////////////////////////                   
void LiberarmemoriaLCA(Tnodo *listaC)  
   {  
                   Tnodo temp=NULL;   
                           if(*listaC)
                            {
                                   temp=*listaC;
                                   do{
                                          Servicio(temp); 
                                          delay(100);
                                          free(temp);
                                          temp=(temp->sig);       
                                                
                                   }while(*listaC && temp != *listaC);           
                            }
                            
                            
   }    
