/*
 * VZona.cpp
 *
 *  Created on: 28 oct. 2018
 *      Author: Scorpion
 */

#include "VZona.h"

VZona::VZona() {
	// TODO Auto-generated constructor stub

}
void VZona::ImprimirZona(string ds, string cd, float pr, int ps){
	Limpiar();
	ImprimirEncabezado("		ZONA: "+ds,"		=================");
	ImprimirString("\n CODIGO ASIGNADO: ", cd);
	ImprimirNroDecimal("\n PRECIO DE LOS BOLETOS: BsS. ", pr);
	ImprimirNro("\n CANTIDAD DE PUESTOS DE LA ZONA: ", ps);
	Pausa();
}

void VZona::ImprimirReporte(string ds, float gn, float gnt, int pd, string ct){
	ImprimirEncabezado("		ZONA: "+ds,"		=================");
	ImprimirNro("\n CANTIDAD DE PUESTOS DISPONIBLES DE LA ZONA: ", pd);
	ImprimirNroDecimal("\n GANANCIA DE LA ZONA: BsS. ", gn);
	ImprimirNroDecimal("\n MAYOR GANANCIA POR TAQUILLAS: ", gnt);
	ImprimirString("\n CODIGO DE LA TAQUILLA: ", ct);
	Pausa();
}

