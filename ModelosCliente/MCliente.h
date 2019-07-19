/*
 * MCliente.h
 *
 *  Created on: 28 oct. 2018
 *      Author: Scorpion
 */

#ifndef MCLIENTE_H_
#define MCLIENTE_H_
#include "MPersona.h"
#include "../Librerias/Pila.cpp"
#include "../ModelosTaquilla/MBoleto.h"
#include <iostream>
using namespace std;

class MCliente:public MPersona {
	int cantAsien;
	int cantBoletos;
	int cantBoletosCom;
	float monto;

public:
	Pila<MBoleto> boletosCliente;
	MCliente();
	void setCantAsien(int as);
	int getCantAsien();
	void CalcularMonto(float mt);
	float Monto();
	void incluirBoletos(MBoleto mb);
	int CantBoletosComprados();
};

#endif /* MCLIENTE_H_ */
