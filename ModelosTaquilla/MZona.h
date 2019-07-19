/*
 * MZona.h
 *
 *  Created on: 28 oct. 2018
 *      Author: Scorpion
 */

#ifndef MZONA_H_
#define MZONA_H_
#include <string>
using namespace std;

class MZona {
private:
	string codigo;
	string descrip;
	float precio;
	int cantpuestos;
	int cantpuestosV;
public:
	MZona();
	void Vaciar();
	void limpiar();
	void setCodigo(string cd);
	string getCodigo();
	void setDatos(string ds, float pr, int cp);
	string getDescrip();
	float getPrecio();
	int getCantPues();
	void PuestosVendidos(int pv);
	int PuestosVendidosTotal();
	int PuestosDisponibles();
	float GananciaTotal();
};

#endif /* MZONA_H_ */
