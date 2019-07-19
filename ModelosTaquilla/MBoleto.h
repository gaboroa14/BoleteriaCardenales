/*
 * MBoleto.h
 *
 *  Created on: 10 dic. 2018
 *      Author: Gabriel
 */

#ifndef MODELOSTAQUILLA_MBOLETO_H_
#define MODELOSTAQUILLA_MBOLETO_H_
#include <string>
using namespace std;

class MBoleto {
private:
	int nroAsiento;
	string codZona;

public:
	MBoleto();
	void setNroAsiento(int na);
	int getNroAsiento();
	void setCodZona(string cz);
	string getCodZona();
};

#endif /* MODELOSTAQUILLA_MBOLETO_H_ */
