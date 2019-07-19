#ifndef Lista_H
#define Lista_H
#include "Nodo.h"
#include "../ModelosTaquilla/MZona.h"
#include "../ModelosTaquilla/MTaquilla.h"
#include <iostream>
#include <string>
using namespace std;

template <class Tipo>
class Lista
{  
typedef Nodo<Tipo>* Apuntador;
private:
        Nodo<Tipo>* primero;             
public:
         
         Lista();
         Nodo<Tipo>* ObtPrimero();           //get  
         void AsigPrimero(Nodo<Tipo>* p);    //Set
         bool Vacia();
         bool Llena();
         bool InsComienzo(Tipo valor);
         bool EliComienzo(Tipo &valor);
         bool Modificar(Apuntador p, Tipo &valor);
         bool Eliminar(Apuntador p,Tipo &valor, Apuntador an);
         bool InsDerecho(Apuntador p,Tipo valor);
         bool EliDerecho(Apuntador p,Tipo &valor);
         bool BuscarTaquilla(MTaquilla &mt, string cd, Apuntador &p);
         bool BuscarAntTaquilla(string, Apuntador &p);
         bool BuscarAntZona(string, Apuntador &p);
         bool BuscarZona(MZona &mz, string cd, Apuntador &p);
         bool ContarTaquilla(string cd);
         bool TaquillaMayorXZona(string cd, MTaquilla &mt);
         bool TaquillaMayor(MTaquilla &mt);
         bool ZonaMayor(MZona &mz);
         ~Lista();
         	     

};


#endif
