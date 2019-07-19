/*
 * MCliente.cpp
 *
 *  Created on: 28 oct. 2018
 *      Author: Scorpion
 */

#include "../ModelosCliente/MCliente.h"

MCliente::MCliente() {
	cantAsien=0;
	cantBoletos=0;
	monto=0.0;
	cantBoletosCom=0;
}

void MCliente::CalcularMonto(float mt){
	monto=cantAsien*mt;
}

float MCliente::Monto(){
	return monto;
}

void MCliente::setCantAsien(int as){
	cantAsien=as;
	cantBoletosCom+=as;
}

int MCliente::getCantAsien(){
	return cantAsien;
}

void MCliente::incluirBoletos(MBoleto mb){
	boletosCliente.Insertar(mb);
	cantBoletos++;
}

int MCliente::CantBoletosComprados(){
	return cantBoletosCom;
}

