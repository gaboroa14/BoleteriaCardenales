#ifndef Cola_H
#define Cola_H
#include<iostream>
using namespace std;

template <class Tipo>
class Cola;

template <class Tipo>
class nodo
{
Tipo info;
nodo *prox;
friend class Cola<Tipo>;
};

template <class Tipo>
class Cola
{
nodo<Tipo> *Frente,*Final;
public:
Cola();
bool Vacia();
bool Llena();
bool Insertar(Tipo Valor);
bool Remover(Tipo &Valor);
};

#endif
