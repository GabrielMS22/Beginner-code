////////////////////////////////////LISTAS SIMPLES///////////////////////////////////

Tnodo AgregarLS(Tnodo *lista, Tnodo *nuevo);
Tnodo EliminarLS(Tnodo *lista, int num);
int BuscarL(Tnodo *lista, int busqueda);
void LeerListaS(Tnodo *lista);



Tnodo AgregarLS(Tnodo *lista, Tnodo *nuevo)
      {
          Tnodo temp=NULL,nodo=NULL;
          temp=*lista;
          if(temp && (*nuevo)->dato>=(temp->dato))
            {
            while(temp->sig && (temp->sig)->dato < (*nuevo)->dato )
                 {
                   
                   temp=(temp->sig);
                   
                 }
                 if((*nuevo)->dato==(temp->dato))
                   {
                                   
                                  return *nuevo;
                   }
                    
                   (*nuevo)->sig=(temp->sig);
                   (temp->sig)=*nuevo;
                   return nodo;
            }
           
           (*nuevo)->sig=*lista;
           *lista=*nuevo;
           return nodo; 
                     
      }
Tnodo EliminarLS(Tnodo *lista, int num)
      {
                     Tnodo temp=NULL,nodo=NULL;
                     if(!(lista))
                         {
                                 return nodo;
                         }
                        else
                         {
                            temp=*lista;
                            if(num==(*lista)->dato)
                               {
                                                 *lista=(temp->sig);
                                                 (temp->sig)=NULL;
                                                 return temp;
                               }
                               else
                                {
                                   while((temp->sig) && (temp->sig)->dato < num)
                                        {
                                                   temp=(temp->sig);
                                        }
                                        nodo=(temp->sig);
                                 }    
                                        if(nodo && (nodo->dato)==num)
                                          {
                                                (temp->sig)=(nodo->sig);
                                                (nodo->sig)=NULL;
                                                return nodo;    
                                          }
                                         else
                                          {
                                                nodo=NULL;            
                                          } 
                                          return nodo;
                         }                                    
      }      
int BuscarL(Tnodo *lista, int busqueda)
      {
               int cont=0,aux;
               Tnodo temp=NULL;
               if(*lista)
                 {
                       temp=*lista;
                         while(temp && (temp->dato))
                              { 
                                 cont++;
                                 
                                 if(busqueda==(temp->dato))
                                    {                    
                                         return cont;        
                                                         
                                    }
                                  if(temp==NULL)
                                     {
                                                cont=-1;
                                                return cont;
                                     }  
                                  temp=(temp->sig);  
                              }    
                                    
                 }   
      }      
      
void LeerListaS(Tnodo *lista)  
   {  
                   Tnodo temp=NULL;   
                           if(*lista)
                            {
                                   temp=*lista;
                                   while(temp)
                                        {
                                          Servicio(temp); 
                                          temp=(temp->sig);   
                                              
                                        }
                                        
                            }
                            else
                            {
                            printf("Lista Vacia\n");
                            system("PAUSE");
                            }  
   }        
   

