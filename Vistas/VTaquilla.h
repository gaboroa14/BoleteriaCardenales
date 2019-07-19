/*
 * VTaquilla.h
 *
 *  Created on: 28 oct. 2018
 *      Author: Scorpion
 */

#ifndef VTAQUILLA_H_
#define VTAQUILLA_H_
#include "VGeneral.h"

class VTaquilla:public VGeneral {
public:
	VTaquilla();
	void ImprimirInformacion(string cd, string zo, float ps, int pv);
	void ImprimirReporte(string cd, int pv, float gn, float mv, string ced,string nom);
};

#endif /* VTAQUILLA_H_ */
