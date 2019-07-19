#include "../Librerias/Lista.h"
#include "../Librerias/Nodo.cpp"

template <class Tipo>
Nodo<Tipo>* Lista<Tipo>::ObtPrimero(){
  return primero;          
}

template <class Tipo>
void Lista<Tipo>::AsigPrimero(Nodo<Tipo>* p){
     primero=p;
}

template <class Tipo>
Lista<Tipo>::Lista()
{
     primero=NULL;
}

template <class Tipo>
bool Lista<Tipo>::Vacia()
{
  return primero == NULL;
}

template <class Tipo>
bool Lista<Tipo>::Llena()
{
  Nodo<Tipo> *p;
  p=new Nodo<Tipo>;
  if (p==NULL)
     return true;
  else
    { 
      delete p;
      return false;       
    }   
}

template <class Tipo>
Lista<Tipo>::~Lista()
{
 Nodo<Tipo> *p;
  while (!Vacia())
   {
        p=primero->ObtDer();
        delete primero;
        primero=p;     
   }
 
}

template <class Tipo>
bool Lista<Tipo>::InsComienzo(Tipo Valor)
{
  Apuntador nuevo;
  if (!Llena()) 
     {
      nuevo=new Nodo<Tipo>;
      nuevo->AsigInfo(Valor);
      nuevo->AsigDer(primero);
      primero=nuevo;
      return true;
     }
  else
      return false;    
}

template <class Tipo>
bool Lista<Tipo>::EliComienzo(Tipo &valor)
{
  Apuntador viejo;
  if (!Vacia()) 
     {
      viejo=primero;          
      valor=viejo->ObtInfo();
      primero=primero->ObtDer();
      delete viejo;
      return true;
     }
  else
      return false;    
}

template <class Tipo>
bool Lista<Tipo>::InsDerecho(Apuntador p,Tipo valor)
{
  Apuntador nuevo;
  if (!Llena())
      if (Vacia()) 
         {
            InsComienzo(valor);
            p = ObtPrimero();
         }
      else if (p==NULL)
         return false;
      else
         {          
               nuevo=new Nodo<Tipo>;
               nuevo->AsigInfo(valor);
               nuevo->AsigDer(p->ObtDer());
               p->AsigDer(nuevo);
               return true;
         }
  else
  return false;
}

template <class Tipo>
bool Lista<Tipo>::Modificar(Apuntador p,Tipo &valor){
	if(p==NULL){
		return false;
	}
	else{
		p->AsigInfo(valor);
		return true;
	}
}

template <class Tipo>
bool Lista<Tipo>::Eliminar(Apuntador p,Tipo &valor, Apuntador an){
	 if (p==NULL)
	    return false;
	 else{
		 valor=p->ObtInfo();
		 an->AsigDer(p->ObtDer());
		 delete p;
		 return true;
	}
}

template <class Tipo>
bool Lista<Tipo>::EliDerecho(Apuntador p,Tipo &valor)
{
  Apuntador viejo;  
     if (p==NULL)
         return false;
     else{
    	 if ((p->ObtDer())==NULL)
    		 return false;
    	 else
    	     {
    	       viejo=p->ObtDer();
    	       valor=viejo->ObtInfo();
    	       p->AsigDer(viejo->ObtDer());
    	       delete viejo;
    	       return true;
    	      }
     }

}

template <class Tipo>
bool Lista<Tipo>::BuscarTaquilla(MTaquilla &mt, string cd, Apuntador &p){
	MTaquilla aux;
	Apuntador buscar;
	bool a;
	if(Vacia()){
		a=false;
	}
	else{
		buscar=primero;
		while(buscar!=NULL and !a){
			aux=buscar->ObtInfo();
			if(aux.getCodTaquilla()==cd){
				mt=aux;
				p=buscar;
				a=true;
			}
			else{
				buscar=buscar->ObtDer();
				a=false;
			}
		}
	}
	return a;
}

template <class Tipo>
bool Lista<Tipo>::BuscarZona(MZona &mz, string cd, Apuntador &p){
	MZona aux;
	Apuntador buscar;
	bool a;
	if(Vacia()){
		a=false;
	}
	else{
		buscar=primero;
		while(buscar!=NULL and !a){
			aux=buscar->ObtInfo();
			if(aux.getCodigo()==cd){
				mz=aux;
				p=buscar;
				a=true;
			}
			else{
				buscar=buscar->ObtDer();
				a=false;
			}
		}
	}
	return a;
}

template <class Tipo>
bool Lista<Tipo>::ContarTaquilla(string cd){
	MTaquilla mt;
	Apuntador buscar;
	bool a;
	int cont=0;
	if(Vacia()){
		a=false;
	}
	else{
		buscar=primero;
		while(cont<2 && buscar!=NULL){
			mt=buscar->ObtInfo();
			if(mt.getzona()==cd){
				buscar=buscar->ObtDer();
				cont++;
			}
			else{
				buscar=buscar->ObtDer();
			}
		}
		if(cont==2)
			a=true;
		else
			a=false;
	}
	return a;
}

template <class Tipo>
bool Lista<Tipo>::BuscarAntTaquilla(string cd, Apuntador &p){
	MTaquilla aux;
	Apuntador buscar;
	bool a;
	if(Vacia()){
		a=false;
	}
	else{
		buscar=primero;
		p=buscar;
		while(buscar!=NULL and !a){
			aux=buscar->ObtInfo();
			if(aux.getCodTaquilla()==cd){
				a=true;
			}
			else{
				p=buscar;
				buscar=buscar->ObtDer();
				a=false;
			}
		}
	}
	return a;
}

template <class Tipo>
bool Lista<Tipo>::BuscarAntZona(string cd, Apuntador &p){
	MZona aux;
	Apuntador buscar;
	bool a;
	if(Vacia()){
		a=false;
	}
	else{
		buscar=primero;
		p=buscar;
		while(buscar!=NULL and !a){
			aux=buscar->ObtInfo();
			if(aux.getCodigo()==cd){
				a=true;
			}
			else{
				p=buscar;
				buscar=buscar->ObtDer();
				a=false;
			}
		}
	}
	return a;
}

template <class Tipo>
bool Lista<Tipo>::TaquillaMayorXZona(string cd, MTaquilla &mt){
	MTaquilla mtaux;
	MTaquilla mayor;
	Apuntador buscar;
	bool a;
	int cont=0;
	if(Vacia()){
		a=false;
	}
	else{
		buscar=primero;
		while(cont<2 && buscar!=NULL){
			mtaux=buscar->ObtInfo();
			if(mtaux.getzona()==cd){
				buscar=buscar->ObtDer();
				cont++;
				if(mayor.CalcularGancia()<mtaux.CalcularGancia()){
					mayor=mtaux;
				}
			}
			else{
				buscar=buscar->ObtDer();
			}
		}
		if(cont==2)
			a=true;
		else
			a=false;
	}
	mt=mayor;
	return a;
}

template <class Tipo>
bool Lista<Tipo>::TaquillaMayor(MTaquilla &mt){
	MTaquilla mtaux;
	MTaquilla mayor;
	Apuntador buscar;
	bool a;
	if(Vacia()){
		a=false;
	}
	else{
		buscar=primero;
		while(buscar!=NULL){
			mtaux=buscar->ObtInfo();
			if(mayor.CalcularGancia()<mtaux.CalcularGancia()){
				buscar=buscar->ObtDer();
				mayor=mtaux;
			}
			else{
				buscar=buscar->ObtDer();
			}
		}
		a=true;
	}
	mt=mayor;
	return a;
}

template <class Tipo>
bool Lista<Tipo>::ZonaMayor(MZona &mz){
	MZona mtaux;
	MZona mayor;
	Apuntador buscar;
	bool a;
	if(Vacia()){
		a=false;
	}
	else{
		buscar=primero;
		while(buscar!=NULL){
			mtaux=buscar->ObtInfo();
			if(mayor.GananciaTotal()<mtaux.GananciaTotal()){
				buscar=buscar->ObtDer();
				mayor=mtaux;
			}
			else{
				buscar=buscar->ObtDer();
			}
		}
		a=true;
	}
	mz=mayor;
	return a;
}
