/*
 * MBoleto.cpp
 *
 *  Created on: 10 dic. 2018
 *      Author: Gabriel
 */

#include "../ModelosTaquilla/MBoleto.h"

MBoleto::MBoleto() {
	nroAsiento=0;
}

void MBoleto::setNroAsiento(int na){
	nroAsiento=na;
}

int MBoleto::getNroAsiento(){
	return nroAsiento;
}

void MBoleto::setCodZona(string cz){
	codZona=cz;
}

string MBoleto::getCodZona(){
	return codZona;
}
