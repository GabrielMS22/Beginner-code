

///////////////////////////////PILAS//////////////////////////////
void PUSH_S(Tnodo *pila, Tnodo *nuevo);
Tnodo POP_S(Tnodo *pila);
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
    
