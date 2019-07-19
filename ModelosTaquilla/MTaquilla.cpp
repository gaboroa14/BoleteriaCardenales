/*
 * MTaquilla.cpp
 *
 *  Created on: 28 oct. 2018
 *      Author: Scorpion
 */

#include "../ModelosTaquilla/MTaquilla.h"
#include <iostream>
using namespace std;

MTaquilla::MTaquilla() {
	zona="";
	precio=0.0;
	puestosV=0;
}

void MTaquilla::Vaciar(){
	zona="";
	precio=0.0;
}

void MTaquilla::setCodTaquilla(string ct){
	codTaquilla=ct;
}

void MTaquilla::setDatosTaquilla(string zo, float pr){
	zona=zo;
	precio=pr;
}

string MTaquilla::getCodTaquilla(){
	return codTaquilla;
}

string MTaquilla::getzona(){
	return zona;
}


int MTaquilla::getPuestosV(){
		return puestosV;
}

void MTaquilla::PuestosV(int cp){
	puestosV+=cp;
}

float MTaquilla::CalcularGancia(){
	return (getPuestosV()*getPrecio());
}

float MTaquilla::getPrecio(){
	return precio;
}

void MTaquilla::incluirCliente(MCliente c){
	clientesTaquilla.Insertar(c);
}

bool MTaquilla::buscarCliente(string ced, MCliente &c){
	bool enco;
	MCliente marca;
	MCliente aux;
	marca.SetCedula("-1");
	if(!clientesTaquilla.Vacia()){
		clientesTaquilla.Insertar(marca);
			do{
				clientesTaquilla.Remover(aux);
				if(aux.GetCedula()==ced){
					c=aux;
					enco=true;
				}
				else
					clientesTaquilla.Insertar(aux);
			}while(marca.GetCedula()!=aux.GetCedula());
		clientesTaquilla.Remover(aux);
	}
	else{
		enco=false;
	}
	return enco;
}

void MTaquilla::modificarCliente(MCliente c){
	MCliente marca;
	MCliente aux;
	marca.SetCedula("-1");
	clientesTaquilla.Insertar(marca);
	do{
		clientesTaquilla.Remover(aux);
		if (aux.GetCedula()==c.GetCedula()){
			clientesTaquilla.Insertar(c);
			break;
		}
		else if (aux.GetCedula()!="-1")
			clientesTaquilla.Insertar(aux);
	}while (aux.GetCedula()!="-1");
}

float MTaquilla::AcumularMontXVenta(){
	float acum=0;
	if(!clientesTaquilla.Vacia()){
		MCliente marca;
		MCliente aux;
		marca.SetCedula("-1");
		clientesTaquilla.Insertar(marca);
		do{
			clientesTaquilla.Remover(aux);
			acum+=aux.Monto();
			clientesTaquilla.Insertar(aux);
		}while(marca.GetCedula()!=aux.GetCedula());
		clientesTaquilla.Remover(aux);
		return acum;
	}
	else
		return acum;
}

MCliente MTaquilla::MayorVenta(){
	MCliente mayor;
	if(!clientesTaquilla.Vacia()){
		MCliente marca;
		MCliente aux;
		marca.SetCedula("-1");
		clientesTaquilla.Insertar(marca);
		do{
			clientesTaquilla.Remover(aux);
			if(mayor.Monto()<aux.Monto())
				mayor=aux;
			clientesTaquilla.Insertar(aux);
		}while(marca.GetCedula()!=aux.GetCedula());
		clientesTaquilla.Remover(aux);
		return mayor;
	}
	else
		return mayor;
}
