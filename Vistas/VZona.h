/*
 * VZona.h
 *
 *  Created on: 28 oct. 2018
 *      Author: Scorpion
 */

#ifndef VZONA_H_
#define VZONA_H_
#include "VGeneral.h"

class VZona:public VGeneral {
public:
	VZona();
	void ImprimirZona(string ds, string cd, float pr, int ps);
	void ImprimirReporte(string ds, float gn, float gnt, int pd,string ct);
};

#endif /* VZONA_H_ */
