/*
 * MTaquilla.h
 *
 *  Created on: 28 oct. 2018
 *      Author: Scorpion
 */

#ifndef MTAQUILLA_H_
#define MTAQUILLA_H_
#include <string>
#include "../ModelosCliente/MCliente.h"
#include "../Librerias/Cola.cpp"
using namespace std;

class MTaquilla {
private:
	string codTaquilla;
	string zona;
	int puestosV;
	float precio;

public:
	Cola<MCliente> clientesTaquilla;
	MTaquilla();
	void Vaciar();
	void setCodTaquilla(string ct);
	void setDatosTaquilla(string zo, float pr);
	string getCodTaquilla();
	string getzona();
	void PuestosV(int cp);
	int getPuestosV();
	float CalcularGancia();
	float getPrecio();
	void incluirCliente(MCliente c);
	bool buscarCliente(string ced, MCliente &c);
	void modificarCliente(MCliente c);
	float AcumularMontXVenta();
	MCliente MayorVenta();
};

#endif /* MTAQUILLA_H_ */
