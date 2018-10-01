
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//FUNCION PUSH DE PILAS
void PUSH_S(Tnodo *pila, Tnodo *nuevo)
    {
                (*nuevo)->sig=*pila;
                *pila=*nuevo;
                
                
                
    }
//FUNCION POP DE PILAS
Tnodo POP_S(Tnodo *pila)
    {
                Tnodo temp=NULL;
                if(*pila)
                {
                temp=*pila;
                *pila=(*pila)->sig;
                temp->sig=NULL;
                }
                return temp;
                
                
    }        
    
//FUNCION PUSH DE COLAS
void PUSH_Q(Tnodo *cola, Tnodo *ultimo, Tnodo *nuevo)
    {
                  if(!(*cola))
                    {
                              *cola=*nuevo;
                    }
                  else
                    {
                              (*ultimo)->sig=*nuevo;
                    }
                    
                   *ultimo=*nuevo;               
    }
    //FUNCION POP DE COLAS
Tnodo POP_Q(Tnodo *cola, Tnodo *ultimo)
    {
                Tnodo temp=NULL;
                if(*cola)
                  {
                     if(*cola==*ultimo)
                        {
                                       *ultimo=NULL;
                        }
                        temp=*cola;
                        *cola=(*cola)->sig;
                        temp->sig=NULL;
                  }      
                                 
                
                return temp;
                
                
    }   

