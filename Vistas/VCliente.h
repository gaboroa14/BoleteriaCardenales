/*
 * VCliente.h
 *
 *  Created on: 28 oct. 2018
 *      Author: Scorpion
 */

#ifndef VCLIENTE_H_
#define VCLIENTE_H_
#include "VGeneral.h"

class VCliente:public VGeneral {
public:
	VCliente();
	void ImprimirFactura(string cd, string no, int ca, float m);
};

#endif /* VCLIENTE_H_ */
