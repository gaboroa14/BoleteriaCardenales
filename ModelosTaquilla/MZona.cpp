/*
 * MZona.cpp
 *
 *  Created on: 28 oct. 2018
 *      Author: Scorpion
 */

#include "../ModelosTaquilla/MZona.h"

MZona::MZona() {
	codigo="";
	descrip="";
	precio=0.0;
	cantpuestos=0;
	cantpuestosV=0;
}

void MZona::limpiar(){
	codigo="";
	descrip="";
	precio=0.0;
	cantpuestos=0;
}

void MZona::Vaciar(){
	descrip="";
	precio=0.0;
	cantpuestos=0;
}

void MZona::setCodigo(string cd){
	codigo=cd;
}

string MZona::getCodigo(){
	return codigo;
}

void MZona::setDatos(string dp, float pr, int cp){
	descrip=dp;
	precio=pr;
	cantpuestos=cp;
}

string MZona::getDescrip(){
	return descrip;
}

float MZona::getPrecio(){
	return precio;
}

int MZona::getCantPues(){
	return cantpuestos;
}

void MZona::PuestosVendidos(int pv){
	cantpuestosV+=pv;
}

int MZona::PuestosVendidosTotal(){
	return cantpuestosV;
}

int MZona::PuestosDisponibles(){
	return (getCantPues()-PuestosVendidosTotal());
}

float MZona::GananciaTotal(){
	return (getPrecio()*PuestosVendidosTotal());
}
