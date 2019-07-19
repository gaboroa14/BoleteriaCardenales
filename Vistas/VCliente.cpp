/*
 * VCliente.cpp
 *
 *  Created on: 28 oct. 2018
 *      Author: Scorpion
 */

#include "VCliente.h"

VCliente::VCliente() {
	// TODO Auto-generated constructor stub

}
void VCliente::ImprimirFactura(string cd, string no, int ca, float m){
	Limpiar();
	ImprimirEncabezado("		Factura","		=======");
	ImprimirString("\n Cedula del Cliente: ", cd);
	ImprimirString("\n Nombre del Cliente: ", no);
	ImprimirNro("\n Catidad de Boletos: ", ca);
	ImprimirNroDecimal("\n Monto Total: ", m);
	Pausa();
}
