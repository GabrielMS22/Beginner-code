

////////////////LISTA DOBLE/////////////////////////

Tnodo AgregarLC(Tnodo *listaC, Tnodo *nuevo, Tnodo *fin);
Tnodo EliminarLCD(Tnodo *listaC, Tnodo *fin, int num);
void LeerListaC(Tnodo *listaC);

Tnodo AgregarLC(Tnodo *listaC, Tnodo *nuevo, Tnodo *fin)
               {
                      Tnodo temp=NULL,nodo=NULL;
                      if(!(*listaC))
                        {
                                  *listaC=*nuevo;
                                  *fin=*listaC;
                                  (*fin)->sig=*listaC;      
                        }
                       else
                        {     
                           if((*nuevo)->dato< (*listaC)->dato)
                             {
                                  (*nuevo)->sig=*listaC;
                                  *listaC=*nuevo;
                                  (*fin)->sig=*listaC;                                                    
                             }
                            else
                             {
                                   temp=*listaC;
                                   while(temp!=*fin && (temp->sig)->dato <= (*nuevo)->dato)
                                        {           
                                                    temp=(temp->sig);                       
                                        }                  
                                        if((temp->dato)==(*nuevo)->dato)
                                          {                                          
                                           return *nuevo;                                                                     
                                          }     
                                         else
                                          {
                                                (*nuevo)->sig=(temp->sig);
                                                (temp->sig)=*nuevo;
                                                if(temp==*fin)
                                                  {
                                                             *fin=*nuevo;          
                                                  }
                                                 return nodo;  
                                          }                              
                             }          
                        }
                    return nodo; 
               }
Tnodo EliminarLCD(Tnodo *listaC, Tnodo *fin, int num)
      {
                        
        Tnodo temp=NULL, nodo=NULL;
	
	temp=*listaC;
	
	if(!(*listaC))
	{
		return nodo;
	}
	else
	{
		if((*listaC)->dato == num)
		{
			if(*listaC == *fin)
			{
				nodo=*listaC;
				*listaC=NULL;
				*fin=NULL;
				return nodo;
			}
			else
			{
				nodo=*listaC;
				*listaC=nodo->sig;
				(*fin)->sig=*listaC;
				nodo->sig=NULL;
				
				return nodo;
			}
		}
		else
		{
			while(temp != *fin && (temp->sig)->dato < num)
			{
				temp=temp->sig;
			}
			if((temp->sig)->dato == num)
			{
				if(temp->sig == *fin)
				{
					*fin =temp;
				}
				nodo = (temp->sig);
				temp->sig=nodo->sig;
				nodo->sig=NULL;
				return nodo;
			}
			else
			{
				return nodo;
			}
		}	
	}
 }     

void LeerListaC(Tnodo *listaC)
     {
                    Tnodo temp=NULL;  
                    temp=*listaC;
                            if (temp)
                            {
                             do{
                                                      Servicio(temp);
                                                      temp=(temp->sig);
                                           
                               } 
                             while(temp != *listaC);
                             }      
                      
     }   
